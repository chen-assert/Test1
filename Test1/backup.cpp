#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<limits.h>
using namespace std;
int n, m, r, c;
int row[20][75000];
int coloum[20][75000];//储存先前计算 
int matrix[30][30]; //先行后列 
int MIN = INT_MAX;
int tt1, tt2;
int dfsc(int pos, int dep);
int dfsr(int pos, int dep);
inline int abs_(int x) {
	return ((x > 0) ? x : -x);
}
inline int pow_2(int exp) {
	switch (exp) {
	case 0:return 1;
	case 1:return 2;
	case 2:return 4;
	case 3:return 8;
	case 4:return 16;
	case 5:return 32;
	case 6:return 64;
	case 7:return 128;
	case 8:return 256;
	case 9:return 512;
	case 10:return 1024;
	case 11:return 2048;
	case 12:return 4096;
	case 13:return 8192;
	case 14:return 16384;
	case 15:return 32768;
	case 16:return 65536;
	}
	return -1;
}
inline int cal() {
	//puts();
	int t0 = 0, t00 = 0;
	for (register int a = 1; a <= r; a++) {
		//the position is row[a][0] instead of a
		if (row[row[a][0]][tt1] != -1) {
			t0 += row[row[a][0]][tt1];
			continue;
		}
		t00 = 0;
		for (register int b = 2; b <= c; b++) {
			t00 += abs_(matrix[row[a][0]][coloum[b - 1][0]] - matrix[row[a][0]][coloum[b][0]]);
		}
		row[row[a][0]][tt1] = t00;
		t0 += t00;
	}
	for (register int b = 1; b <= c; b++) {
		if (coloum[coloum[b][0]][tt2] != -1) {
			t0 += coloum[coloum[b][0]][tt2];
			continue;
		}
		t00 = 0;
		for (register int a = 2; a <= r; a++) {
			t00 += abs_(matrix[row[a - 1][0]][coloum[b][0]] - matrix[row[a][0]][coloum[b][0]]);
		}
		coloum[coloum[b][0]][tt2] = t00;
		t0 += t00;
	}
	return t0;
}
int main() {
	memset(&row, -1, sizeof(int) * 1500000);
	memset(&coloum, -1, sizeof(int) * 1500000);
	scanf("%d %d %d %d", &n, &m, &r, &c);
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= m; b++) {
			scanf("%d", &matrix[a][b]);
		}
	}
	for (register int i = 1; i <= m - c + 1; i++) {
		dfsc(i, 1);
	}
	printf("%d", MIN);
}
int dfsc(int pos, int dep) {
	coloum[dep][0] = pos;
	tt1 += pow_2(pos - 1);
	if (dep != c) {
		for (register int i = pos + 1; i <= m - (c - dep) + 1; i++) {
			dfsc(i, dep + 1);
		}
	}
	else {//转入行DFS 
		for (register int i = 1; i <= n - r + 1; i++) {
			dfsr(i, 1);
		}
	}
	//coloum[dep][0] = 0;
	tt1 -= pow_2(pos - 1);
	return 0;
}
int dfsr(int pos, int dep) {
	row[dep][0] = pos;
	tt2 += pow_2(pos - 1);
	if (dep != r) {
		for (register int i = pos + 1; i <= n - (r - dep) + 1; i++) {
			dfsr(i, dep + 1);
		}
	}
	else {//进行计算 
		int t = cal();
		if (t < MIN)MIN = t;
	}
	//row[dep][0] = 0;
	tt2 -= pow_2(pos - 1);
	return 0;
}