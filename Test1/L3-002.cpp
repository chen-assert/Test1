#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<limits.h>
#include<time.h>
#include<iostream>
#include<functional>
#include<vector>
#include<queue>
#include<string.h>
#include<stack>
//#include<regex>
//#include<windows.h>
using namespace std;
#define range(i, s, e) for (int i = (s); i < int(e); i++)
#define range0(i, e) for (int i = 0; i < int(e); i++)
#define input_int(n) int n;scanf("%d",&n);
#define input_int2(n,m) int n;int m;scanf("%d %d",&n,&m);
#define remax(max_record,refresh_number) max_record=std::max(max_record,refresh_number)
#define remin(min_record,refresh_number) min_record=std::min(min_record,refresh_number)
#define INF 0x3f3f3f3f
#define INF2 INT_MAX
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
inline void read(int &x) {//only read int
	static char c;
	for (c = getchar(); !('0' <= c && c <= '9'); c = getchar());
	for (x = 0; '0' <= c && c <= '9'; x = x * 10 + c - 48, c = getchar());
}
static long long p = 10e9;
struct segment_tree_node {
	segment_tree_node* left;
	segment_tree_node* right;
	int begin;//左右边界
	int end;
	int mid;//这有什么用?
	int size;//该节点大小
	long long plus_delay_amount;
	long long multi_delay_amount;
	long long sum;
};
segment_tree_node* create_segment_tree(int begin, int end, long long array[]) {
	segment_tree_node *operated_node = (segment_tree_node*)malloc(sizeof(segment_tree_node));
	memset(operated_node, 0, sizeof(segment_tree_node));
	operated_node->begin = begin;
	operated_node->mid = (begin + end) / 2;
	operated_node->end = end;
	operated_node->size = end - begin + 1;
	operated_node->plus_delay_amount = 0;
	operated_node->multi_delay_amount = 1;
	if (begin == end)operated_node->sum = array[begin];
	else {
		operated_node->left = create_segment_tree(begin, operated_node->mid, array);
		operated_node->right = create_segment_tree(operated_node->mid + 1, end, array);
		operated_node->sum = operated_node->left->sum + operated_node->right->sum;
	}
	return operated_node;
}
int push_delay(segment_tree_node *operated_node) {
	if (operated_node->left != 0) {
		segment_tree_node *&left_node = operated_node->left;
		segment_tree_node *&right_node = operated_node->right;
		left_node->sum *= operated_node->multi_delay_amount;
		left_node->sum %= p;
		left_node->sum += (operated_node->plus_delay_amount)*left_node->size;
		left_node->sum %= p;
		left_node->plus_delay_amount *= operated_node->multi_delay_amount;
		left_node->plus_delay_amount %= p;
		left_node->plus_delay_amount += operated_node->plus_delay_amount;
		left_node->plus_delay_amount %= p;
		left_node->multi_delay_amount *= operated_node->multi_delay_amount;
		left_node->multi_delay_amount %= p;

		right_node->sum *= operated_node->multi_delay_amount;
		right_node->sum %= p;
		right_node->sum += operated_node->plus_delay_amount*right_node->size;
		right_node->sum %= p;
		right_node->plus_delay_amount *= operated_node->multi_delay_amount;
		right_node->plus_delay_amount %= p;
		right_node->plus_delay_amount += operated_node->plus_delay_amount;
		right_node->plus_delay_amount %= p;
		right_node->multi_delay_amount *= operated_node->multi_delay_amount;
		right_node->multi_delay_amount %= p;
	}
	operated_node->plus_delay_amount = 0;
	operated_node->multi_delay_amount = 1;
	return 0;
}
long long search(int begin, int end, segment_tree_node *operated_node) {
	if (operated_node->begin >= begin && operated_node->end <= end) {
		return operated_node->sum;
	}
	else {
		if (operated_node->plus_delay_amount != 0 || operated_node->multi_delay_amount != 1)push_delay(operated_node);
		long long return_num = 0;
		if (operated_node->left->end >= begin)
			return_num += search(begin, end, operated_node->left);
		if (operated_node->right->begin <= end)
			return_num += search(begin, end, operated_node->right);
		return_num %= p;
		return return_num;
	}
}
int update_multiply(int begin, int end, long long mul, segment_tree_node *operated_node) {
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
int update_plus(int begin, int end, long long plus, segment_tree_node *operated_node) {
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
void modify_mod(long long t) {
	p = t;
}
int find_middle(segment_tree_node *operated_node,int already,int find) {
	if (operated_node->begin == operated_node->end)return operated_node->begin;
	if (operated_node->left->sum +already>= find) {
		return find_middle(operated_node->left, already, find);
	}
	else {
		return find_middle(operated_node->right, already + operated_node->left->sum, find);
	}
}
int n;
ll array_[100010];
int flag = 0;
int main() {
	scanf("%d",&n);
	segment_tree_node *node = create_segment_tree(1,100000,array_);
	stack<int>s;
	range0(i, n) {
		char t[20];
		scanf("%s", t);
		if (strcmp(t, "Pop") == 0|| strcmp(t, "pop") == 0) {
			if(flag!=0)printf("\n");
			else flag = 1;
			if (s.size() == 0) {
				printf("Invalid");
			}
			else {
				int num = s.top();
				s.pop();
				update_plus(num, num, -1, node);
				printf("%d", num);
			}
		}
		if (strcmp(t, "Push") == 0||strcmp(t, "push") == 0) {
			int num;
			scanf("%d", &num);
			s.push(num);
			update_plus(num, num, 1, node);
		}
		if (strcmp(t, "PeekMedian") == 0|| strcmp(t, "peek") == 0) {
			if (flag != 0)printf("\n");
			else flag = 1;
			if (s.size() == 0) {
				printf("Invalid");
			}
			else {
				printf("%d",find_middle(node,0,(s.size()+1)/2) );
			}
		}
	}
}