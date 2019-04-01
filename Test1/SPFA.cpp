#include<stdio.h>
#include<stdlib.h> 
#include<algorithm>
#include<limits.h>
#include<time.h>
#include<math.h>  
#include<iostream>
#include<functional>
#include<fstream> 
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<string> 
#include<map>
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
inline void read(int &x) {
	int f = 1; x = 0; char s = getchar();
	while (s > '9' || s < '0') { if (s == '-')f = -1; s = getchar(); }
	while (s <= '9'&&s >= '0') { x = x * 10 + s - '0'; s = getchar(); }
	x *= f;
}
int n, m;
struct NODE {
	//first-route node,second-distance
	vector<P>edge;
	int distance;
	int times;
	NODE() {
		distance = 0;
		times = 0;
	}
}node[2020];
#define N 1000000
int myque[N];
int ques = 0;
int quee = 0;
void queadd(int a) {
	if (quee == N)quee = 0;
	myque[quee++]=a;
}
int quepop() {
	if (ques == N)ques = 0;
	return  myque[ques++];
}
bool queemp() {
	if (ques == quee)return true;
	return false;
}
int spfa() {
	ques = quee = 0;
	//queue<int>que;
	for (int i = 1; i <= n; i++) {
		if (node[i].distance == INF) {
			node[i].distance = 0;
			//que.push(i);
			queadd(i);
		}
		while (!queemp()) {
			//int t = que.front();
			//que.pop();
			int t = quepop();
			node[t].times++;
			if (node[t].times >= n) {
				return 1;
				//ÓÐ¸º»·
			}
			for (P o : node[t].edge) {
				if (node[o.first].distance > node[t].distance + o.second) {
					node[o.first].distance = node[t].distance + o.second;
					//que.push(o.first);
					queadd(o.first);
				}
			}
		}
	}
	return 0;
}
int main() {
	input_int(t);
	range0(i, t) {
		scanf("%d %d", &n, &m);
		range0(o, n + 10) {
			node[o].edge.clear();
			node[o].distance = INF;
			node[o].times = 0;
		}
		range0(o, m) {
			int a, b, w;
			read(a);
			read(b);
			read(w);
			//scanf("%d %d %d", &a, &b, &w);
			if (w >= 0) {
				node[a].edge.push_back(P(b, w));
				node[b].edge.push_back(P(a, w));
			}
			else {
				node[a].edge.push_back(P(b, w));
			}
		}
		printf("%s\n", spfa() ? "YE5" : "N0");
		
	}
	putchar(' ');
}