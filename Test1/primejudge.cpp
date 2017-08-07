#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<cstring>
#include<time.h>
#define _MAX 10000012
using namespace std;
int n, m;
bool record[_MAX];//save whether this is a prime
int primes[_MAX];//save the prime list
int num = 0;
int main() {
	scanf("%d %d", &n, &m);
	record[0] = record[1] = 1;
	for (int i = 2; i <= n / 2 + 1; i++) {
		if (record[i] == 0)primes[num++] = i;
		for (int o = 0; o < num && primes[o] * i <= n; o++) {
			record[primes[o] * i] = 1;
			if (i%primes[o] == 0) break;
		}
	}
	for (int i = 0; i < m; i++) {
		int t = 0;
		scanf("%d", &t);
		if (record[t] == 0)printf("Yes\n");
		else printf("No\n");
	}
}