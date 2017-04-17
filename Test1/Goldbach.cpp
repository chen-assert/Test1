#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<cstring>
using namespace std;
int n;
int prime[10000] = { -1/*invalid*/,2 };
int number = 1;
int ifprime(int a) {
	for (int i = 2; i < sqrt(a); i++) {
		if (a%i == 0)return -1;//isn't a prime number
	}
	return 1;
}
int temp[4];
int recursion(int s,int d) {
	if (d == 4) {
		if (s == n) {
			return 1;
		}
		return -1;
	}
	int t = 0;
	for (int i = 1; i <= number; i++) {
		t=recursion(s + prime[i], d + 1);
		if (t == 1) { 
			temp[d] = prime[i];
			return 1;
		}
	}
	return -10;
}
int record[1000000];
void sai(int a) {
	for (int i = 2;a*i<=n; i++) {
		record[a*i] = 1;
	}
	return;
}
int main() {
	memset(record, 0, sizeof(int) * 1000001);
	scanf("%d",&n);
	/*for (int i = 3; i < n; i+=2) {
		if (ifprime(i) == 1) {
			prime[++number] = i;
		}
	}*/
	for (int i = 2; i <= sqrt(n); i++) {
		sai(i);
	}
	for (int i = 2; i <= n; i++) {
		if (record[i] == 0) {
			prime[++number] = i;
		}
	}
	//for (int i = 1; i <= number; i++)printf("%d  ", prime[i]);
	recursion(0, 1);
	printf("%d %d %d", temp[1], temp[2], temp[3]);
}