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
/*inline void read(int &x) {//only read int
	static char c;
	for (c = getchar(); !('0' <= c && c <= '9'); c = getchar());
	for (x = 0; '0' <= c && c <= '9'; x = x * 10 + c - 48, c = getchar());
}*/
inline void read2(short &x) {//only read int
	static char c;
	for (c = getchar(); !('0' <= c && c <= '9'); c = getchar());
	for (x = 0; '0' <= c && c <= '9'; x = x * 10 + c - 48, c = getchar());
}
/*
int BigRand()
{
	return RAND_MAX * rand() + rand();
}
*/
struct edge {
	short to, cost;
};
int n, m;
int s, e, k, t;
vector<edge> graph[1001];
vector<int> dist[1001];     //最短距离
//第一维-位置 第二维-k
int d, v;
inline void solve() {
	for (register int i = 0; i != n + 1; i++) {
		dist[i].resize(k+1);
		//memset(dist[i], INF, sizeof(int)*(k + 1));
		fill(&dist[i][0], &dist[i][0] + k + 1, t + 1);
	}
	priority_queue<P, vector<P>, greater<P> > que;
	dist[s - 1][0] = 0;
	//只需要设定初始点的最短路  次短路及以上保持不变
	que.push(P(0, s - 1));
	//first-距离 second-当前位置
	P p;
	int d2;
	int len;
	while (!que.empty()) {
		p = que.top(); que.pop();
		//d = p.first;
		//v = p.second;
		if (dist[p.second][k - 1] < p.first) continue;
		len = graph[p.second].size();
		for (register int i = 0; i < len; i++) {
			edge &e = graph[p.second][i];
			d2 = p.first + e.cost;
			int *p = upper_bound(&dist[e.to][0], &dist[e.to][0] + k, d2);
			//第一个大于d2的数
			for (register int *np = &dist[e.to][0] + k-1;np>p; np--) {
				*np = *(np - 1);
				que.push(P(*(np), e.to));
			}
			if(p< &dist[e.to][0] + k )*p = d2;
			que.push(P(d2, e.to));
			/*if (dist[e.to][0] > d2) {
				swap(dist[e.to][0], d2);
				que.push(P(dist[e.to][0], e.to));
			}
			for (int i = 1; i < k; i++) {
				if (dist[e.to][i] > d2 && dist[v][i - 1] < d2) {
					swap(dist[e.to][i], d2);
					que.push(P(dist[e.to][i], e.to));
				}
			}*/
		}
	}
	if (dist[e - 1][k - 1] <= t) {
		printf("yareyaredawa\n");
	}
	else {
		printf("Whitesnake!\n");
	}
}
int main() {
	while (~scanf("%d %d", &n, &m)) {
		scanf("%d %d %d %d", &s, &e, &k, &t);
		for (register int i = 0; i!=m; ++i) {
			short u, v, w;
			read2(u);
			read2(v);
			read2(w);
			//scanf("%d %d %d", &u, &v, &w);
			graph[u - 1].push_back({ v - 1, w });
		}
		solve();
		range0(i, n)graph[i].clear();
	}
}