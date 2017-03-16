#include<stdio.h>
int main() {
	int y = 19;
	int a, b;
	scanf("%d %d", &a, &b);
	int all = a * 10 + b;
	printf("%d", all/y);
}