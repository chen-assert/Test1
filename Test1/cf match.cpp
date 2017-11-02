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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
ll p[200010];
struct NODE {
	int sum;
	int N1;
	int N2;
	int N3;
	int NL;
};
NODE node[500010];
int main() {
	input_int(n);
	priority_queue<ll, vector<ll>, greater<ll>> que;
	range(i, 1, n + 1) {
		scanf("%lld", &p[i]);
		que.push(p[i]);
	}
	int num = 1;
	while (que.size() > 2) {
		ll t = que.top();
		node[num++].sum = que.top();
		que.pop();
		t += que.top();
		node[num++].sum = que.top();
		que.pop();
		t += que.top();
		node[num++].sum = que.top();
		que.pop();
		que.push(t);
	}
	if (que.size() == 2) {

	}

}
