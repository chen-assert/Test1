#include <iostream>
#include <string.h>
#include <stdio.h>
#define max_(a,b) ((a)>(b))?(a):(b)
#define min_(a,b) ((a)<(b))?(a):(b)
int mod(int *a, int *b) {
	int modd=0;
	if (*a%*b >= 0) {
		modd = *a%*b;
		*a = (*a)/(*b);
	}
	else {
		modd = *a%*b - *b;
		*a = (*a) / (*b)+1;
	}
	return modd;
}
int p[200];
int n, r, i = 1,N;
void putchar_(int a) {
	if (a < 10)printf("%d",a);
	else {
		a = a - 10 + 'A';
		printf("%c", a);
	}
}
void output() {
	printf("%d=", N);
	for (int k = i - 1; k >= 1; k--) {
		putchar_(p[k]);
	}
	printf("(base%d)", r);
}

int main() {
	scanf("%d %d", &n, &r);
	N = n;
	while (n!=0) {
		p[i] = mod(&n, &r);
		i++;
	}
	output();
	return 0;
}