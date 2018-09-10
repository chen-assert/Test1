#include<stdio.h>
#include <stdlib.h> 
#include<algorithm>
#include<limits.h>
#include<time.h>
#include<iostream>
#include<functional>
#include<vector>
#include<queue>
#include<string.h>
#include<stack>
//#include"segment tree.h"
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
typedef pair<ll, ll> llP;
inline void read(int &x) {//only read int
	static char c;
	for (c = getchar(); !('0' <= c && c <= '9'); c = getchar());
	for (x = 0; '0' <= c && c <= '9'; x = x * 10 + c - 48, c = getchar());
}
int BigRand()
{
	return RAND_MAX * rand() + rand();
}
struct segment_tree_node {
	segment_tree_node* left;
	segment_tree_node* right;
	int begin;//左右边界
	int end;
	int mid;
	int size;//该节点大小
	long long delay_amount;
	ll pure_sum;
	ll study_sum;
};
segment_tree_node* create_segment_tree(int begin, int end, long long array[]) {
	segment_tree_node *operated_node = (segment_tree_node*)malloc(sizeof(segment_tree_node));
	//多次malloc会显著降低速度并大幅增加内存占用
	memset(operated_node, 0, sizeof(segment_tree_node));
	operated_node->begin = begin;
	operated_node->end = end;
	operated_node->mid = (begin + end) / 2;
	//mid这点属于左半边
	operated_node->size = end - begin + 1;
	operated_node->delay_amount = 0;
	if (begin == end)operated_node->pure_sum = operated_node->study_sum = array[begin];
	else {
		operated_node->left = create_segment_tree(begin, operated_node->mid, array);
		operated_node->right = create_segment_tree(operated_node->mid + 1, end, array);
		operated_node->pure_sum = operated_node->left->pure_sum + operated_node->right->pure_sum;
		operated_node->study_sum = operated_node->left->study_sum+operated_node->right->study_sum+ (operated_node->left->pure_sum)*(operated_node->end-operated_node->mid);
	}
	return operated_node;
}
int push_delay(segment_tree_node *operated_node) {
	/*
	if (operated_node->left != 0) {
		segment_tree_node *&left_node = operated_node->left;
		segment_tree_node *&right_node = operated_node->right;
		left_node->sum *= operated_node->multi_delay_amount;
		left_node->sum += (operated_node->plus_delay_amount)*left_node->size;
		left_node->plus_delay_amount *= operated_node->multi_delay_amount;
		left_node->plus_delay_amount += operated_node->plus_delay_amount;
		left_node->multi_delay_amount *= operated_node->multi_delay_amount;

		right_node->sum *= operated_node->multi_delay_amount;
		right_node->sum += operated_node->plus_delay_amount*right_node->size;
		right_node->plus_delay_amount *= operated_node->multi_delay_amount;
		right_node->plus_delay_amount += operated_node->plus_delay_amount;
		right_node->multi_delay_amount *= operated_node->multi_delay_amount;
	}
	operated_node->plus_delay_amount = 0;
	operated_node->multi_delay_amount = 1;
	*/
	return 0;
}
//first-pure second-study
llP search(int begin, int end, segment_tree_node *operated_node) {
	if (operated_node->begin >= begin && operated_node->end <= end) {
		return llP(operated_node->pure_sum, operated_node->study_sum);
	}
	else {
		//if (operated_node->delay_amount != 0)push_delay(operated_node);
		llP r(0, 0);
		llP tl, tr;
		if (operated_node->left->end >= begin) {
			tl = search(begin, end, operated_node->left);
			r.first += tl.first;
			r.second += tl.second;
		}
		if (operated_node->right->begin <= end) {
			tr = search(begin, end, operated_node->right);
			r.first += tr.first;
			r.second +=(min(end,operated_node->end)-operated_node->mid)*tl.first;
			r.second += tr.second;
		}
		return r;
	}
}
int update(int point, long long c, segment_tree_node *operated_node) {
	if (operated_node->begin >= point && operated_node->end <= point) {
		operated_node->pure_sum = c;
		operated_node->study_sum = c;
		//operated_node->delay_amount += c;
	}
	else {
		//push_delay(operated_node);
		if (operated_node->left->end >= point)
			update(point, c, operated_node->left);
		if (operated_node->right->begin <= point)
			update(point, c, operated_node->right);
		operated_node->pure_sum = operated_node->left->pure_sum + operated_node->right->pure_sum;
		operated_node->study_sum = operated_node->left->study_sum + operated_node->right->study_sum + (operated_node->left->pure_sum)*(operated_node->end - operated_node->mid);
	}
	return 0;
}
int main() {
	input_int2(n, q);
	ll *a = new ll[n + 10];
	range0(i, n) {
		scanf("%lld", &a[i + 1]);
	}
	segment_tree_node *root = create_segment_tree(1, n, a);
	range0(i, q) {
		input_int(a);
		input_int2(b, c);
		if (a == 1) {
			printf("%lld\n", search(b, c, root).second);
		}
		else {
			update(b, c, root);
		}
	}
}