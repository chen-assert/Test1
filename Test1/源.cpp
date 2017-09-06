#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<limits.h>
#include<queue>
#include<time.h>
#include<stack>
#include<map>
#include<iostream>
#include<string.h>
#include<functional>
//#include"segment tree.h"
//#include<windows.h>
#define range(i, s, e) for (int i = (s); i < int(e); i++)
#define range0(i, e) for (int i = 0; i < int(e); i++)
#define input_int(n) int n;scanf("%d",&n);
#define INF 0x3f3f3f3f
#define INF2 2147483647
using namespace std;
typedef unsigned long long ull;
typedef pair<int, int> P;
struct EDGE {
	int u;
	int v;
	int cost;
};
bool cmp(const EDGE &a1, const EDGE &a2) {
	return a1.cost < a2.cost;
}
static long long p = 10e9;
struct segment_tree_node {
	segment_tree_node* left;
	segment_tree_node* right;
	int begin;
	int mid;
	int end;
	int size;
	int num;
};
segment_tree_node* create_segment_tree(int begin, int end, int array[]) {
	segment_tree_node *operated_node = (segment_tree_node*)malloc(sizeof(segment_tree_node));
	memset(operated_node, 0, sizeof(segment_tree_node));
	operated_node->begin = begin;
	operated_node->mid = (begin + end) / 2;
	operated_node->end = end;
	operated_node->size = end - begin + 1;
	if (begin == end)operated_node->num = array[begin];
	else {
		operated_node->left = create_segment_tree(begin, operated_node->mid, array);
		operated_node->right = create_segment_tree(operated_node->mid + 1, end, array);
		operated_node->num = min(operated_node->left->num, operated_node->right->num);
	}
	return operated_node;
}
int search(int begin, int end, segment_tree_node *operated_node,int find_num) {
	if()
}
int next_[100010];
int main() {
	input_int(t);
	range0(i, t) {
		input_int(n);
		int a[100010];
		range0(o, n) {
			scanf("%d", &a[o + 1]);
		}
		input_int(m);
		range0(o, m) {
			int l, r;
			scanf("%d %d", &l, &r);


			printf("%d\n", ans);
		}
	}
}