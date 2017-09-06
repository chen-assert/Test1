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
	int to;
	int cost;
};
int n, m, r, c;
int matrix[20][20];
int row[20];
int coloum[20];
int w[20];
int v[20][20];
int f[20][20];
int min_ = INF;
void init() {
	scanf("%d %d %d %d", &n, &m, &r, &c);
	range(a, 1, n + 1) {
		range(b, 1, m + 1) {
			scanf("%d", &matrix[b][a]);
		}
	}
}
void dp() {
	fill(w, w + 20, 0);
	fill(*v, *v + 20 * 20, 0);
	fill(*f, *f + 20 * 20, INF);
	range(i, 0, 20) {
		f[0][i] = 0;
	}
	for (int a = 1; a <= m; a++) {
		int pre = matrix[a][row[1]];
		for (int b = 1; b <= r; b++) {
			w[a] += abs(matrix[a][row[b]] - pre);
			pre = matrix[a][row[b]];
		}
	}
	for (int j = 1; j <= m; j++) {
		for (int k = 1; k <= m; k++) {
			for (int i = 1; i <= r; i++) {
				v[j][k] += abs(matrix[j][row[i]] - matrix[k][row[i]]);
			}
		}
	}
	//dp前置运算
	for (int i = 1; i <= c; i++) {//已选i列
		for (int j = i; j <= m - (c - i); j++) {
			for (int k = i - 1; k < j; k++) {
				f[i][j] = min(f[i][j], f[i - 1][k] + w[j] + v[j][k]);
			}
		}
	}
	for (int i = c; i <= m; i++) {
		min_ = min(min_, f[c][i]);
		if (min_ == 11) {
			//getchar();
		}
	}
}
int dfsr(int pos, int dep) {
	row[dep] = pos;
	if (dep != r) {
		for (register int i = pos + 1; i <= n - (r - dep) + 1; i++) {
			dfsr(i, dep + 1);
		}
	}
	else {//进行DP
		dp();
	}
	return 0;
}
int main() {
	init();
	for (register int i = 1; i <= n - r + 1; i++) {
		dfsr(i, 1);
	}
	
	printf("%d", min_);
}