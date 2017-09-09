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
bool cmp(const EDGE &a1,const EDGE &a2) {
	return a1.cost < a2.cost;
}
vector <EDGE> edge;
int n, m, r;
int *parent;
int *rank_;
void init_union(int n) {
	if (parent != NULL) {
		delete[] parent;
		delete[] rank_;
		parent = NULL;
		rank_ = NULL;
	}
	parent = new int[n];
	rank_ = new int[n];
	range0(i, n+1) {
		parent[i] = i;
		rank_[i] = 0;
	}
}
int find(int i) {
	if (parent[i] == i)return i;
	else return parent[i] = find(parent[i]);
}
void merge(int a1, int a2) {
	a1 = find(a1);
	a2 = find(a2);
	if (a1 == a2)return;
	if (rank_[a1] < rank_[a2]) {
		parent[a1] = a2;
	}
	else {
		parent[a2] = a1;
		if (rank_[a1] == rank_[a2])rank_[a1]++;
	}
}
int kruskal() {
	sort(edge.begin(), edge.end(), cmp);
	init_union(m + n + 1);
	int len = edge.size();
	int res = 0;
	for (int i = 0; i < len; i++) {
		EDGE t = edge[i];
		if (find(t.u) != find(t.v)) {
			merge(t.u, t.v);
			res += t.cost;
		}
	}
	return res;
}
int main() {
	input_int(num);
	range0(q, num) {
		//n-x girls//m-y boys
		scanf("%d %d %d", &n, &m, &r);
		range0(i, r) {
			int x, y, d;
			scanf("%d %d %d", &x, &y, &d);
			edge.push_back({ x, y + n, -d });
		}
		int t = kruskal();
		printf("%d\n", (m + n) * 10000 + t);
		edge.clear();
	}
}