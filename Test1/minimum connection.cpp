#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
int c[25][25];
int max = 0;
int sum = 0;
int n;
int cc[25];
int accmulate(int i, int x) {
	int ss = 0;
	for (int p = 1; p <= n; p++) {
		if (((1 << (p - 1)) & i) == 0) {//第p位是0
			ss += c[p][x];
		}
	}
	return ss;
}
int dfs(int p, int w) {
	cc[w] = p;
	int k = 0;
	if (p == 1) {
		for (int i = 0; i <= n; i++) {
			if (cc[i] == 0)k += c[w][i];
		}
		for (int i = 0; i <= n; i++) {
			if (cc[i] == 1)k -= c[w][i];
		}
	}
	sum += k;
	if (w < n) {
		dfs(1, w + 1);
		dfs(0, w + 1);
		
	}
	if (sum > max)max = sum;

	if (p == 1) {
		sum -= k;
	}
	return 0;
}
int main() {
	memset(cc, 0, sizeof(int) * 25);
	scanf("%d", &n);
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			scanf("%d", &c[a][b]);
		}
	}
	//for (int i = 1; i <= pow(2, n) - 1; i++) {//state
	//	 for (int x = 1; x <= n; x++) {
	//	 	if (((1 << (x - 1)) & i) > 0) {//第x位是1
	//	 		sum += accmulate(i,x);
	//	 	}
	//	 }
	//	 if (sum > max)max = sum;
	//	 sum = 0;
	//}  //位运算超时
	dfs(1, 1);
	sum = 0;
	dfs(0, 1);
	
	printf("%d", max);
}