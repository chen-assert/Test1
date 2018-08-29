#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<cstring>
#include<time.h>
using namespace std;
int n, m;
bool *record;//save whether this is a prime
int *primes;//save the prime list
int num = 0;
void pre_treat(int n) {
	//欧拉筛法
	//是我自己写的吗?
	//已经看不懂了
	n += 10;
	record = new bool[n];
	primes = new int[n];
	memset(record, 0, sizeof(bool)*n);
	memset(primes, 0, sizeof(int)*n);
	record[0] = record[1] = 1;
	for (int i = 2; i <= n / 2 + 1; i++) {
		if (record[i] == 0)primes[num++] = i;
		for (int o = 0; o < num && primes[o] * i <= n; o++) {
			record[primes[o] * i] = 1;//合数标为1，同时，prime[o]是合数i*prime[o]的最小素因子
			if (i%primes[o] == 0) break;//即比一个合数大的质数和该合数的乘积可用一个更大的合数和比其小的质数相乘得到
			//what????
		}
	}
	primes[num++] = n + 100;
}
void pre_treat(int n) {
	n++;
	record = new bool[n] {};
	//memset(record, 0, sizeof(bool)*n);
	record[0] = record[1] = 1;
	for (int i = 2; i <= n / 2 + 1; i++) {
		if (record[i] == 1) continue;
		for (int o = i * 2; o < n; o += i) {
			record[o] = 1;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	pre_treat(n);
	for (int i = 0; i < m; i++) {
		int t = 0;
		scanf("%d", &t);
		if (record[t] == 0)printf("Yes\n");
		else printf("No\n");
	}
}