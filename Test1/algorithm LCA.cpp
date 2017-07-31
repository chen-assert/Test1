#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<limits.h>
#include<queue>
#include<time.h>
#include<stack>
#include<map>
//#include"segment tree.h"
#define range(i, s, e) for (int i = s; i < int(e); i++)
#define range0(i, e) for (int i = 0; i < int(e); i++)
#define input_int(n) int n;scanf("%d",&n);
//#include<windows.h>
using namespace std;
int n, m, s;
int parent[500010];
struct NODE {
	//int rank;
	vector <int> edge;
	bool visited;
};
struct QUERY {
	vector <int> point;
	vector <int> num;
};
int ans[500010];
int find(int i) {
	if (parent[i] == i)return i;
	else return parent[i] = find(parent[i]);
}
void merge(int a1, int a2) {
	parent[a1] = parent[a2];
}
void tarjan(int u, NODE *node, QUERY *search, int from) {
	//merge和find为并查集合并函数和查找函数 
	size_t len2 = node[u].edge.size();
	for (size_t v = 0; v < len2; v++) {	                //访问所有u子节点v
		if (node[u].edge[v] == from)continue;
		tarjan(node[u].edge[v], node, search, u);                    //继续往下遍历
		merge(node[u].edge[v], u);                                //合并v到u上
		node[node[u].edge[v]].visited = 1;                        //标记v已被访问过
	}
	size_t len = search[u].point.size();
	for (size_t e = 0; e < len; e++) {				//访问所有和u有询问关系的e
		if (node[search[u].point[e]].visited == 1) {
			ans[search[u].num[e]] = find(search[u].point[e]);		//u, e的最近公共祖先为find(e);
		}
	}
}
int main() {
	scanf("%d %d %d", &n, &m, &s);
	range0(i, n + 1)parent[i] = i;
	NODE *node = new NODE[n + 1];
	range0(i, n + 1) {
		node[i].visited = 0;
	}
	QUERY *search = new QUERY[m+1];
	int x, y;
	range0(i, n - 1) {
		scanf("%d %d", &x, &y);
		node[x].edge.push_back(y);
		node[y].edge.push_back(x);
	}
	int a, b;
	range0(i, m) {
		scanf("%d %d", &a, &b);
		search[a].num.push_back(i);
		search[b].num.push_back(i);
		search[a].point.push_back(b);
		search[b].point.push_back(a);
	}
	node[s].visited = 1;
	tarjan(s, node, search, s);
	range0(i, m) {
		printf("%d\n", ans[i]);
	}
}