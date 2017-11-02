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
int num[10][10];
int dp[22][11][11];
int main() {
	input_int(n);
	int x, y, z;
	do {
		scanf("%d %d %d", &x, &y, &z);
		num[x][y] = z;
	} while (x != 0 || y != 0 || z != 0);
	int sum = num[1][1]+num[n][n];
	for (int step = 1; step <= (n - 1) * 2-1; step++) {
		//保证路径不重叠
		for (int x1 = max(2,step-n+3); x1 <=min(n,1+step) ; x1++) {//向右
			for (int x2 = max(1,step-n+2); x2 <= x1-1; x2++) {//向下
				dp[step][x1][x2] = max(max(dp[step-1][x1][x2],dp[step-1][x1][x2-1]),max(dp[step-1][x1-1][x2],dp[step-1][x1-1][x2-1]))+num[x1][step-x1+2]+num[x2][step-x2+2];
			}
		}
	}
	sum += dp[(n-1)*2-1][n][n-1];
	printf("%d", sum);
}