#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<limits.h>
#include<queue>
#include<time.h>
#include<stack>
#define range(i, s, e) for (int i = s; i < int(e); i++)
#define range0(i, e) for (int i = 0; i < int(e); i++)
#define input_int(n) int n;scanf("%d",&n);
//#include<windows.h>
using namespace std;
long long s[100010];
long long p;
struct node {
	node* left;
	node* right;
	int begin;
	int mid;
	int end;
	int size;
	int delay_mark;//1 means plus,2 means multiply
	long long delay_amount;
	long long sum;
};
int pushup(node* operated_node) {
	if (operated_node->delay_mark == 1) {
		operated_node->sum = operated_node->left->sum + operated_node->right->sum + operated_node->size*operated_node->delay_amount;
		operated_node->sum %= p;
	}
	else if (operated_node->delay_mark == 2) {
		operated_node->sum = (operated_node->left->sum + operated_node->right->sum) * operated_node->delay_amount;
		operated_node->sum %= p;
	}
	else {
		operated_node->sum = operated_node->left->sum + operated_node->right->sum;
		operated_node->sum %= p;
	}
	return 0;
}
node* create_segment_tree(int begin, int end) {
	node *now_node = (node*)malloc(sizeof(node));
	memset(now_node, 0, sizeof(node));
	now_node->begin = begin;
	now_node->mid = (begin + end) / 2;
	now_node->end = end;
	now_node->size = end - begin + 1;
	if (begin == end)now_node->sum = s[begin];
	else {
		now_node->left = create_segment_tree(begin, now_node->mid);
		now_node->right = create_segment_tree(now_node->mid + 1, end);
		pushup(now_node);
	}
	return now_node;
}
int push_delay(node *operated_node) {
	if (operated_node->delay_mark == 1) {
		if (operated_node->left != 0) {
			node *&left_node = operated_node->left;
			if (left_node->delay_mark != 1)push_delay(left_node);
			left_node->sum += operated_node->delay_amount*left_node->size;
			left_node->sum %= p;
			left_node->delay_mark = 1;
			left_node->delay_amount += operated_node->delay_amount;

			node *&right_node = operated_node->right;
			if (right_node->delay_mark != 1)push_delay(right_node);
			right_node->sum += operated_node->delay_amount*right_node->size;
			right_node->sum %= p;
			right_node->delay_mark = 1;
			right_node->delay_amount += operated_node->delay_amount;
		}
	}
	else /*if (operated_node->delay_mark == 2)*/ {
		if (operated_node->left != 0) {
			node *&left_node = operated_node->left;
			if (left_node->delay_mark != 2)push_delay(left_node);
			left_node->sum *= operated_node->delay_amount;
			left_node->sum %= p;
			left_node->delay_mark = 2;
			if (left_node->delay_amount == 0)left_node->delay_amount = operated_node->delay_amount;
			else left_node->delay_amount *= operated_node->delay_amount;

			node *&right_node = operated_node->right;
			if (right_node->delay_mark != 2)push_delay(right_node);
			right_node->sum += operated_node->delay_amount;
			right_node->sum %= p;
			right_node->delay_mark = 2;
			if (right_node->delay_amount == 0)right_node->delay_amount = operated_node->delay_amount;
			else right_node->delay_amount *= operated_node->delay_amount;
		}
	}
	operated_node->delay_mark = 0;
	operated_node->delay_amount = 0;
	return 0;
}
long long search(int begin, int end, node *operated_node) {
	if (operated_node->begin >= begin && operated_node->end <= end) {
		return operated_node->sum;
	}
	else {
		if (operated_node->delay_mark != 0)push_delay(operated_node);
		long long return_num = 0;
		if (operated_node->left != 0) {
			if (operated_node->left->end >= begin)
				return_num += search(begin, end, operated_node->left);
			if (operated_node->right->begin <= end)
				return_num += search(begin, end, operated_node->right);
		}
		return_num %= p;
		return return_num;
	}
}
int update_multiply(int begin, int end, long long mul, node *operated_node) {
	if (operated_node->delay_mark == 1)push_delay(operated_node);
	if (operated_node->begin >= begin && operated_node->end <= end) {
		operated_node->sum *= mul;
		operated_node->sum %= p;
		operated_node->delay_mark = 2;
		if (operated_node->delay_amount == 0)operated_node->delay_amount = mul;
		else operated_node->delay_amount *= mul;
	}
	else {
		if (operated_node->left != 0) {
			if (operated_node->left->end >= begin)
				update_multiply(begin, end, mul, operated_node->left);
			if (operated_node->right->begin <= end)
				update_multiply(begin, end, mul, operated_node->right);
		}
		if (operated_node->begin != operated_node->end)pushup(operated_node);
	}
	return 0;
}
int update_plus(int begin, int end, long long plus, node *operated_node) {
	if (operated_node->delay_mark == 2)push_delay(operated_node);
	if (operated_node->begin >= begin && operated_node->end <= end) {
		operated_node->sum += (operated_node->size)*plus;
		operated_node->sum %= p;
		operated_node->delay_mark = 1;
		operated_node->delay_amount += plus;
	}
	else {
		if (operated_node->left != 0) {
			if (operated_node->left->end >= begin)
				update_plus(begin, end, plus, operated_node->left);
			if (operated_node->right->begin <= end)
				update_plus(begin, end, plus, operated_node->right);
		}
		if (operated_node->begin != operated_node->end)pushup(operated_node);
	}
	return 0;
}
int main() {
	input_int(n);
	input_int(m);
	
	scanf("%lld", &p);
	range(i, 1, n + 1) {
		scanf("%lld", &s[i]);
	}
	node *root_node = create_segment_tree(1, n);
	range0(i, m) {
		int j = 0, x = 0, y = 0;
		long long k = 0;
		scanf("%d %d %d", &j, &x, &y);
		if (j == 0) {
			i--;
			continue;
			//debug
		}
		if (j == 1) {
			scanf("%lld", &k);
			update_multiply(x, y, k, root_node);
		}
		else if (j == 2) {
			scanf("%lld", &k);
			update_plus(x, y, k, root_node);
		}
		else {
			printf("%lld\n", search(x, y, root_node) % p);
		}
	}
	//getchar();
}
