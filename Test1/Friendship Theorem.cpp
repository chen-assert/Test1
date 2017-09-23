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
int link[10][10];
int n;
int dfs(int pos, int from, int jud, int dep) {
	if (dep == 3) {
		if (link[from][pos] == jud) {
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (link[from][i] == jud && i!=from && i!=pos) {
				if (dfs(pos, i, jud, dep + 1) == 1) {
					return 1;
				}
			}
		}
		return 0;
	}
}
int main() {
	scanf("%d", &n);
	if (n > 6) {
		printf("Uncreative");
		return 0;
	}
	else {
		for (int i = 1; i <= n; i++) {
			for (int o = i + 1; o <= n; o++) {
				input_int(t);
				link[i][o] = link[o][i] = t;
			}
		}
		for (int i = 1; i <= n; i++) {
			if (dfs(i, i, 0, 1) == 1 || dfs(i, i, 1, 1) == 1) {
				printf("Uncreative");
				return 0;
			}
		}
		printf("Creative");
	}
}