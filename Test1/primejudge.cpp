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
	//ŷ��ɸ��
	//�����Լ�д����?
	//�Ѿ���������
	n += 10;
	record = new bool[n];
	primes = new int[n];
	memset(record, 0, sizeof(bool)*n);
	memset(primes, 0, sizeof(int)*n);
	record[0] = record[1] = 1;
	for (int i = 2; i <= n / 2 + 1; i++) {
		if (record[i] == 0)primes[num++] = i;
		for (int o = 0; o < num && primes[o] * i <= n; o++) {
			record[primes[o] * i] = 1;//������Ϊ1��ͬʱ��prime[o]�Ǻ���i*prime[o]����С������
			if (i%primes[o] == 0) break;//����һ��������������͸ú����ĳ˻�����һ������ĺ����ͱ���С��������˵õ�
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