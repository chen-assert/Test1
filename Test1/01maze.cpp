#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<cstring>
#include<time.h>
#include<queue>
using namespace std;
int ans = 0;
int n, m, i, j;
char mg[1010][1010];
int ifmg[1010][1010];
int mem[1000010];
queue<int> xf;
queue<int> yf;
int push(int x, int y, char i,int p) {
	if (x < 0 || x >= n || y < 0 || y >= n)return -1;
	if (ifmg[x][y] != 0)return 0;
	if (mg[x][y] == i)return 0;
	xf.push(x);
	yf.push(y);
	ifmg[x][y] = p;
	return 1;
}
int search(int p) {
	int x = xf.front();
	xf.pop();
	int y = yf.front();
	yf.pop();
	ans++;
	//ifmg[x][y] = p;
	push(x + 1, y, mg[x][y],p);
	push(x - 1, y, mg[x][y],p);
	push(x, y + 1, mg[x][y],p);
	push(x, y - 1, mg[x][y],p);
	return 0;
}
int main() {
	memset(mg, 0, sizeof(bool) * 1010 * 1010);
	memset(ifmg, 0, sizeof(int) * 1010 * 1010);
	memset(mem, 0, sizeof(int) * 1000010);
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", &mg[i]);
	}
	for (int p = 1; p <= m; p++) {
		scanf("%d %d", &i, &j);
		//memset(ifmg, 0, sizeof(bool) * 1000000);
		i--, j--;
		if (mem[(ifmg[i][j])] != 0) {
			printf("%d\n", mem[(ifmg[i][j])]);
			continue;
		}
		xf.push(i);
		yf.push(j);
		ifmg[i][j] = p;
		while (1) {
			if (xf.empty() == 1)break;
			search(p);
		}
		mem[p] = ans;
		printf("%d\n", ans);
		ans = 0;
	}
}