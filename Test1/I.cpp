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
#define input_int2(n,m) int n;int m;scanf("%d %d",&n,&m);
#define INF 0x3f3f3f3f
#define INF2 INT_MAX
using namespace std;
typedef unsigned long long ull;
typedef pair<int, int> P;
struct segment_tree_node {
	segment_tree_node* left;
	segment_tree_node* right;
	segment_tree_node* last;
	int begin;//左右边界
	int end;
	int mid;//这有什么用?
	int size;//该节点大小
	int min;
	int max;
};
segment_tree_node* ground_node[150000];
segment_tree_node* create_segment_tree(int begin, int end, int array[], segment_tree_node* last_node) {
	segment_tree_node *operated_node = (segment_tree_node*)malloc(sizeof(segment_tree_node));
	memset(operated_node, 0, sizeof(segment_tree_node));
	operated_node->begin = begin;
	operated_node->mid = (begin + end) / 2;
	operated_node->end = end;
	operated_node->size = end - begin + 1;
	operated_node->last = last_node;
	if (begin == end) {
		operated_node->min = array[begin];
		operated_node->max = array[begin];
		ground_node[begin] = operated_node;
	}
	else {
		operated_node->left = create_segment_tree(begin, operated_node->mid, array, operated_node);
		operated_node->right = create_segment_tree(operated_node->mid + 1, end, array, operated_node);
		operated_node->min = min(operated_node->left->min, operated_node->right->min);
		operated_node->max = max(operated_node->left->max, operated_node->right->max);
	}
	return operated_node;
}
int search_min(int begin, int end, segment_tree_node *operated_node) {
	if (operated_node->begin >= begin && operated_node->end <= end) {
		return operated_node->min;
	}
	else if (operated_node->begin > end || operated_node->end < begin) {
		return INT_MAX;
	}
	else {
		return min(search_min(begin, end, operated_node->left), search_min(begin, end, operated_node->right));
	}
}
int search_max(int begin, int end, segment_tree_node *operated_node) {
	if (operated_node->begin >= begin && operated_node->end <= end) {
		return operated_node->max;
	}
	else if (operated_node->begin > end || operated_node->end < begin) {
		return INT_MIN;
	}
	else {
		return max(search_max(begin, end, operated_node->left), search_max(begin, end, operated_node->right));
	}
}
int change(segment_tree_node *operated_node) {	//这里只做上推  初始赋值在外面做
	operated_node->min = min(operated_node->left->min, operated_node->right->min);
	operated_node->max = max(operated_node->left->max, operated_node->right->max);
	if (operated_node->last == NULL)return 0;
	else {
		change(operated_node->last);
	}
	return 0;
}
int main() {
	input_int(t);
	int array[150000] = { 0 };
	range0(i, t) {
		input_int(k);
		int len = (int)pow(2, k);
		for (int o = 0; o < len; o++) {
			scanf("%d", &array[o]);
		}
		segment_tree_node* root_node = create_segment_tree(0, len - 1, array, NULL);
		input_int(q);
		range0(o, q) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			if (a == 1) {
				long long fmax = search_max(b, c, root_node);
				long long fmin = search_min(b, c, root_node);
				if (fmin > 0) {
					printf("%lld\n",fmin*fmin);
				}
				else if (fmax<0) {
					printf("%lld\n", fmax*fmax);
				}
				else {
					printf("%lld\n", fmin*fmax);
				}
			}
			else {
				ground_node[b]->min = c;
				ground_node[b]->max = c;
				if (ground_node[b]->last != NULL) {
					change(ground_node[b]->last);
				}
			}
		}
	}
}