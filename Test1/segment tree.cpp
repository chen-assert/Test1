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
	long long plus_delay_amount;
	long long multi_delay_amount;
	long long sum;
};
node* create_segment_tree(int begin, int end) {
	node *operated_node = (node*)malloc(sizeof(node));
	memset(operated_node, 0, sizeof(node));
	operated_node->begin = begin;
	operated_node->mid = (begin + end) / 2;
	operated_node->end = end;
	operated_node->size = end - begin + 1;
	operated_node->plus_delay_amount = 0;
	operated_node->multi_delay_amount = 1;
	if (begin == end)operated_node->sum = s[begin];
	else {
		operated_node->left = create_segment_tree(begin, operated_node->mid);
		operated_node->right = create_segment_tree(operated_node->mid + 1, end);
		operated_node->sum = operated_node->left->sum + operated_node->right->sum;
	}
	return operated_node;
}
int push_delay(node *operated_node) {
	if (operated_node->left != 0) {//
		node *&left_node = operated_node->left;
		node *&right_node = operated_node->right;
		left_node->sum *= operated_node->multi_delay_amount;
		left_node->sum %= p;
		left_node->sum += operated_node->plus_delay_amount;
		left_node->sum %= p;
		left_node->plus_delay_amount += operated_node->plus_delay_amount;
		left_node->multi_delay_amount *= operated_node->multi_delay_amount;

		right_node->sum *= operated_node->multi_delay_amount;
		right_node->sum %= p;
		right_node->sum += operated_node->plus_delay_amount;
		right_node->sum %= p;
		right_node->plus_delay_amount += operated_node->plus_delay_amount;
		right_node->multi_delay_amount *= operated_node->multi_delay_amount;
	}
	operated_node->plus_delay_amount = 0;
	operated_node->multi_delay_amount = 1;
	return 0;
}
long long search(int begin, int end, node *operated_node) {
	if (operated_node->begin >= begin && operated_node->end <= end) {
		return operated_node->sum;
	}
	else {
		if (operated_node->plus_delay_amount != 0 || operated_node->multi_delay_amount != 1)push_delay(operated_node);
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
	if (operated_node->begin >= begin && operated_node->end <= end) {
		operated_node->sum *= mul;
		operated_node->sum %= p;
		operated_node->multi_delay_amount *= mul;
		operated_node->multi_delay_amount %= p;
		operated_node->plus_delay_amount *= mul;
		operated_node->plus_delay_amount %= p;
	}
	else {
		push_delay(operated_node);
		if (operated_node->left->end >= begin)
			update_multiply(begin, end, mul, operated_node->left);
		if (operated_node->right->begin <= end)
			update_multiply(begin, end, mul, operated_node->right);
		operated_node->sum = operated_node->left->sum + operated_node->right->sum;
	}
	return 0;
}
int update_plus(int begin, int end, long long plus, node *operated_node) {
	if (operated_node->begin >= begin && operated_node->end <= end) {
		operated_node->sum += (operated_node->size)*plus;
		operated_node->sum %= p;
		operated_node->plus_delay_amount += plus;
		operated_node->plus_delay_amount %= p;
	}
	else {
		push_delay(operated_node);
		if (operated_node->left->end >= begin)
			update_plus(begin, end, plus, operated_node->left);
		if (operated_node->right->begin <= end)
			update_plus(begin, end, plus, operated_node->right);
		operated_node->sum = operated_node->left->sum + operated_node->right->sum;
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
			i = 0;
			continue;
			//debug
		}
		if (j == 1) {
			scanf("%lld", &k);
			k %= p;
			update_multiply(x, y, k, root_node);
		}
		else if (j == 2) {
			scanf("%lld", &k);
			update_plus(x, y, k, root_node);
		}
		else {
			printf("%lld\n", search(x, y, root_node) % p);
		}
		{
			printf("%d\n", i);
			range(i, 1, n ) {
				printf("%lld  ", search(i, i+1, root_node));
			}
			printf("\n\n");
		}
	}
	//getchar();
}
