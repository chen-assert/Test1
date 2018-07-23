#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<cstring>
#include<time.h>
#include<algorithm>
using namespace std;
int l, s, t, m;
int st[120];
int record1[30000];//记录走过的石头数量
int record2[30000];//记录是否存在石头
int gcd(int a, int b)
{
	if (b == 0) return a;
	a %= b;
	return gcd(b, a);
}
int main() {
	scanf("%d %d %d %d", &l, &s, &t, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &st[i]);
	}
	int temp = 0, temp2 = 0;
	/*if (s != t)temp = s*t;
	else temp = t;*/
	temp = t*s/gcd(t, s);
	sort(st, st + m);
	if (st[0] - 0 > 2 * temp) {
		temp2 = ((st[0] - 0) / temp - 1)*temp;
		for (int y = 0; y < m; y++) {
			st[y] -= temp2;
		}
		l -= temp2;
	}
	if (l - st[m - 1] > 2 * temp) {
		temp2 = ((l - st[m - 1]) / temp - 1)*temp;
		l -= temp2;
	}
	for (int x = 0; x < m - 1; x++) {
		if (st[x + 1] - st[x] > 2 * temp) {
			temp2 = ((st[x + 1] - st[x]) / temp - 1)*temp;
			for (int y = x + 1; y < m; y++) {
				st[y] -= temp2;//状态压缩？
			}
			l -= temp2;
		}
	}
	for (int i = 0; i < 30000; i++) {
		record1[i] = 200;
		record2[i] = 0;
	}
	record1[0] = 0;
	for (int i = 0; i < m; i++) {
		record2[st[i]] = 1;
	}
	for (int i = 0; i < l; i++) {
		for (int x = s; x <= t; x++) {
			if (record1[i] + record2[i + x]< record1[i + x])record1[i + x] = record1[i] + record2[i + x];
		}
	}
	/*for (int i = 0; i <= l; i++) {
	printf("%d %d\n", record1[i],record2[i]);
	}*/
	//printf("l=%d\n", l);
	int min = 200;
	for (int i = 0; i <= t; i++) {
		if (min > record1[l + i])min = record1[l + i];
	}
	printf("%d", min);
	// for (int x = 0; x < m; x++)printf("\n%d  ", st[x]);
}