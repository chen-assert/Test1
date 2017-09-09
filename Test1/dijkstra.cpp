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
typedef unsigned long long ull;
using namespace std;
struct edge {
	int to;
	int cost;
};
struct node {
	int dis;
	int num;
	friend bool operator<(node a, node b) {
		return a.dis > b.dis;
	}
};
bool used[10010];
int maxdis[10010];
int n, m, s;
vector <edge> go[10010];
priority_queue<node> que;
void dijkstra(int s) {//ÇóÄãÐ´¸ö×¢ÊÍ
	node t3;
	t3.dis = 0;
	t3.num = s;
	que.push(t3);
	while (que.empty() != 1) {
		node t = que.top();
		que.pop();
		if (used[t.num] == 1 || t.dis > maxdis[t.num])continue;
		used[t.num] = 1;
		//maxdis[t.num] = t.dis; //alreade equal
		for (edge i : go[t.num]) {
			if (t.dis + i.cost < maxdis[i.to]) {
				maxdis[i.to] = t.dis + i.cost;
				node t2;
				t2.dis = maxdis[i.to];
				t2.num = i.to;
				que.push(t2);
			}
		}
	}
	return;
}
int main() {
	scanf("%d %d %d", &n, &m, &s);
	range0(i, 10010)maxdis[i] = INF2;
	maxdis[s] = 0;
	range0(i, m) {
		int f, g, w;
		scanf("%d %d %d", &f, &g, &w);
		edge t;
		t.to = g;
		t.cost = w;
		go[f].push_back(t);
		//if (f == s)maxdis[g] = min(maxdis[g], w);
	}
	dijkstra(s);
	range(i, 1, n + 1) {
		printf("%d ", maxdis[i]);
	}
}