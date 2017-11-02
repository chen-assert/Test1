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
int main() {
	int dat[1010];
	while (1) {
		input_int2(r, n);
		if (r == -1 && n == -1)break;
		range0(i, n) {
			scanf("%d", &dat[i]);
		}
		dat[n] = INF;
		sort(dat, dat + n);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int s = i;
			int m = upper_bound(dat + s, dat + n, dat[s] + r) - dat-1;
			int e = upper_bound(dat + m, dat + n, dat[m] + r) - dat-1;
			i = e;
			sum++;
		}
		printf("%d\n", sum);
	}
}