#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<limits.h>
#include<queue>
#include<time.h>
#include<stack>
#include<map>
#include<cctype>
//#include"segment tree.h"
//#include<windows.h>
#define range(i, s, e) for (int i = s; i < int(e); i++)
#define range0(i, e) for (int i = 0; i < int(e); i++)
#define input_int(n) int n;scanf("%d",&n);
using namespace std;
int n, m, s;
int parent[500010];
int visited[500010];
int head[500010];
int qhead[500010];
struct NODE {
	int to;
	int last;
}node[1000010];
struct QUERY {
	int to;
	int last;
}search_[1000010];
int ans[500010];
int find(int i) {
	if (parent[i] == i)return i;
	else return parent[i] = find(parent[i]);
}
void merge(int a1, int a2) {
	parent[a1] = parent[a2];
}
void add(int a, int b, int t) {//添加道路信息
	node[t].last = head[a];
	node[t].to = b;
	head[a] = t;
}
void qadd(int a, int b, int t) {//添加询问信息
	search_[t].last = qhead[a];
	search_[t].to = b;
	qhead[a] = t;
}
void tarjan(int u, NODE *node, QUERY *search, int from) {
	//merge和find为并查集合并函数和查找函数 
	for (int v = head[u]; v != 0; v = node[v].last) {	                //访问所有u子节点v
		if (node[v].to == from)continue;
		tarjan(node[v].to, node, search, u);                    //继续往下遍历
		merge(node[v].to, u);                                //合并v到u上
		visited[node[v].to] = 1;                        //标记v已被访问过
	}
	for (int e = qhead[u]; e != 0; e = search_[e].last) {				//访问所有和u有询问关系的e
		if (visited[search_[e].to] == 1) {
			ans[e / 2] = find(search_[e].to);		//u, e的最近公共祖先为find(e);
		}
	}
}
int main() {
	scanf("%d %d %d", &n, &m, &s);
	range0(i, n + 1)parent[i] = i;
	int x, y;
	range0(i, n - 1) {
		scanf("%d %d", &x, &y);
		add(x, y, i * 2 + 2);
		add(y, x, i * 2 + 1 + 2);
	}
	int a, b;
	range0(i, m) {
		scanf("%d %d", &a, &b);
		qadd(a, b, i * 2 + 2);
		qadd(b, a, i * 2 + 1 + 2);
	}
	visited[s] = 1;
	tarjan(s, node, search_, s);
	range(i, 1, m + 1) {
		printf("%d\n", ans[i]);
	}
}