#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<cstring>
#include<time.h>
using namespace std;
int n, m;
int record[10000010];
int sai(int a) {
	for (int i = 2 * a; i <= n; i += a) {
		if (record[i] == 0)record[i] = 1;
		//printf("%d ", a*i);
	}
	for (int i = a + 1;; i++) {
		if (record[i] == 0)return i;
	}
}
int main() {
	memset(record, 0, sizeof(int) * 10000011);
	scanf("%d %d", &n, &m);
	int t = 2;
	while (1) {
		t = sai(t);
		if (t > sqrt(n))break;
	}
	record[1] = 1;
	for (int i = 0; i < m; i++) {
		scanf("%d", &t);
		if (record[t] == 0)printf("Yes\n");
		else printf("No\n");
	}
	//for (int i = 1; i <= number; i++)printf("%d  ", prime[i]);
}