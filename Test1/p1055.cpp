#include<stdio.h>
int main() {
	char a[9],d;
	int sum=0;
	scanf("%c-%c%c%c-%c%c%c%c%c-%c", &a[0], &a[1], &a[2], &a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&d);
	for (int i = 0; i < 9; i++) {
		sum = sum + (a[i] - '0')*(i + 1);
	}
	sum = sum%11;
	if (sum == d - '0') {
		printf("Right");
		return 0;
	}
	if (sum == 10 && d == 'X') {
		printf("Right");
		return 0;
	}
	if (sum == 10) {
		printf("%c-%c%c%c-%c%c%c%c%c-X", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]);
		return 0;
	}
	printf("%c-%c%c%c-%c%c%c%c%c-%d", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], sum);
}
