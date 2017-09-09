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
struct EDGE {
	int u;
	int v;
	int cost;
};
bool cmp(const EDGE &a1, const EDGE &a2) {
	return a1.cost < a2.cost;
}
struct edge {
	int to;
	int cost;
};
struct node {
	int dis;
	int num;
	friend bool operator<(node a, node b) {
		return a.dis < b.dis;
	}
};
vector <edge> go[10010];
int lldis[10010];
int dfs(int start) {
	if (lldis[start] != 0 || go[start].size() == 0)return lldis[start];
	for (edge i : go[start]) {
		lldis[start] = max(lldis[start], dfs(i.to) + i.cost);
	}
	return lldis[start];
}
int main() {
	input_int(t);
	range0(i, t) {
		input_int2(n, m);
		range0(i, m) {
			int s, t, l;
			scanf("%d %d %d", &s, &t, &l);
			go[s].push_back(edge{ t,l });
		}
		for (int o = n; o >= 1; o--) {
			dfs(o);
		}
		int longest = 0;
		for (int o = 1; o <= n; o++) {
			if (longest < lldis[o])longest = lldis[o];
		}
		printf("%d\n", longest);
		for (register int o = 1; o <= n; o++) {
			go[o].clear();
			lldis[o] = 0;
		}
	}
}