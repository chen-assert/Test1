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
char in[10];
int sum_(char in[10]) {
	int r = 0;
	for (int i = 0; i < 5; i++) {
		r *= 10;
		r += (in[i] - '0');
	}
	return r;
}
int sum_(int in[10]) {
	int r = 0;
	for (int i = 0; i < 5; i++) {
		r *= 10;
		r += (in[i] - 0);
	}
	return r;
}
int ans[100010][4][4];
struct NODE {
	int num[10];
};
void dfs(NODE n, int o1, int o2, int step) {
	int s = sum_(n.num);
	if (o1 + o2 + step < ans[s][o1][o2]) {
		ans[s][o1][o2] = o1 + o2 + step;
	}
	else {
		return;
	}
	if (o1 < 3) {
		for (int i = 0; i < 5; i++) {
			int t = n.num[i];
			n.num[i] = (n.num[i] + 1) % 10;
			dfs(n,o1+1,o2,step);
			n.num[i] = t;
		}
	}
	if (o2 < 2) {
		for (int i = 0; i < 5; i++) {
			int t = n.num[i];
			n.num[i] = (n.num[i] *2) % 10;
			dfs(n, o1, o2+1, step);
			n.num[i] = t;
		}
	}
	for (int i = 0; i < 4; i++) {
		swap(n.num[i], n.num[i + 1]);
		dfs(n, o1, o2, step+1);
		swap(n.num[i], n.num[i + 1]);
	}
}
int main() {
	NODE t;
	for (int i = 0; i < 5; i++)t.num[i] = i + 1;
	range0(a, 100010) {
		range0(b, 4) {
			range0(c, 4) {
				ans[a][b][c] = INF;
			}
		}
	}
	dfs(t,0,0,0);
	while (scanf("%s", in) != EOF)
	{
		int min_ = INF;
		range0(i, 4) {
			range0(o, 3) {
				min_ = min(min_, ans[sum_(in)][i][o]);
			}
		}
		printf("%d\n",min_==INF?-1:min_);
	}
}