#include<stdio.h>
#include<stdlib.h>
//#include<algorithm>
//#include<iostream>
#include<math.h>
#include<string.h>
#include<time.h>
//#include<vector>
//using namespace std;
int n;
char xp[30][120];
int president = 0;
int judge(char *a, char *b) {//when a>b return 1 
	if (strlen(a) != strlen(b))return strlen(a) - strlen(b);
	for (int i = 0; i < strlen(a); i++) {
		if (a[i] != b[i]) {
			return a[i] - b[i];
		}
	}
	return 0;
}
void sort(int s, int e, int(*j)(char*, char*)) {}
void find(int s, int e, int(*j)(char*, char*)) {
	for (int i = s; i <= e; i++) {
		if (judge(xp[i], xp[president]) >= 1) {
			president = i;
		}
	}
	return;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", &xp[i]);
	}
	find(1, n, *judge);
	printf("%d\n%s", president, xp[president]);
}