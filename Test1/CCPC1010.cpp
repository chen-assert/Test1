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
inline void read(int &x) {//only read int
	static char c;
	for (c = getchar(); !('0' <= c && c <= '9'); c = getchar());
	for (x = 0; '0' <= c && c <= '9'; x = x * 10 + c - 48, c = getchar());
}
int BigRand()
{
	return RAND_MAX * rand() + rand();
}
struct node {
	int x, y, v, num;
};

int n;
bool cmp(node a, node b) {
	if (a.y != b.y)return a.y < b.y;
	else return a.x > b.x;
}
struct segment_tree_node {
	segment_tree_node* left;
	segment_tree_node* right;
	int begin;//���ұ߽�
	int end;
	int mid;
	int size;//�ýڵ��С
	int max;
	segment_tree_node* parent;
};
int search(int begin, int end, segment_tree_node *operated_node) {
	if (operated_node->end < begin || operated_node->begin > end) {
		return 0;
	}
	else if (operated_node->begin >= begin && operated_node->end <= end) {
		return operated_node->max;
	}
	else {
		return max(search(begin, end, operated_node->left), search(begin, end, operated_node->right));
	}
}
int update(int point, int num, segment_tree_node *operated_node) {
	if (operated_node->begin >= point && operated_node->end <= point) {
		operated_node->max = num;
	}
	else {
		if (operated_node->left->end >= point)
			update(point, num, operated_node->left);
		if (operated_node->right->begin <= point)
			update(point, num, operated_node->right);
		operated_node->max = max(operated_node->left->max, operated_node->right->max);
	}
	return 0;
}
segment_tree_node* create_segment_tree(int begin, int end) {
	segment_tree_node *operated_node = (segment_tree_node*)malloc(sizeof(segment_tree_node));
	//���malloc�����������ٶȲ���������ڴ�ռ��
	memset(operated_node, 0, sizeof(segment_tree_node));
	//operated_node->parent;
	operated_node->begin = begin;
	operated_node->end = end;
	operated_node->mid = (begin + end) / 2;
	operated_node->size = end - begin + 1;
	if (begin == end)operated_node->max = 0;
	else {
		operated_node->left = create_segment_tree(begin, operated_node->mid);
		operated_node->right = create_segment_tree(operated_node->mid + 1, end);
		operated_node->max = max(operated_node->left->max, operated_node->right->max);
	}
	return operated_node;
}
void free_segment_tree(segment_tree_node *operated_node) {
	if (operated_node->left != NULL)free_segment_tree(operated_node->left);
	if (operated_node->right != NULL)free_segment_tree(operated_node->right);
	free(operated_node);
}
segment_tree_node *sroot;
node vill[100010];
void dp(int point) {
	int fj = search(0,vill[point].x-1,sroot);
	if (fj + vill[point].v > search(vill[point].x, vill[point].x, sroot)) {
		update(vill[point].x,fj + vill[point].v, sroot);
	}
}
void disperse(node *v) {
	vector<int>xx, yy;
	range0(i, n) {
		xx.push_back(v[i].x);
		yy.push_back(v[i].y);

	}
	sort(xx.begin(), xx.end());
	sort(yy.begin(), yy.end());
	xx.erase(unique(xx.begin(), xx.end()), xx.end());
	yy.erase(unique(yy.begin(), yy.end()), yy.end());
	range0(i, n) {
		v[i].x = lower_bound(xx.begin(), xx.end(), v[i].x) - xx.begin();
		v[i].y = lower_bound(yy.begin(), yy.end(), v[i].y) - yy.begin();
	}
}
int main() {
	input_int(t);
	range0(u, t) {
		scanf("%d", &n);
		range0(i, n) {
			scanf("%d %d %d", &vill[i].x, &vill[i].y, &vill[i].v);
		}
		disperse(vill);
		sroot = create_segment_tree(0, n+10);
		sort(vill, vill + n, cmp);
		range0(i, n) {
			dp(i);
		}
		printf("%d\n", sroot->max);
		free_segment_tree(sroot);
	}
}