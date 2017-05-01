#include <stdio.h>
#include <stdlib.h>
#include<iostream>
int main() {
	char a[550] = { 0 }, b[550] = { 0 };
	int i = 1;
	scanf("%s %s", a+1, b+1);
	char s[550] = { 0 };
	int ae = 1, be = 1;
	while (a[ae] != 0)ae++;
	ae--;
	while (b[be] != 0)be++;
	be--;
	int t = 1;
	while (1) {
		s[t] += a[ae] + b[be];
		if (s[t] >= 96)s[t] -= '0';
		if (s[t] > '9') {
			s[t + 1]++;
			s[t] -= 10;
		}
		t++;
		if (ae > 0)ae--;
		if (be > 0)be--;
		if (ae == 0 && be == 0)break;
	}
	if (s[t] == 1) {
		printf("1");
		t--;
	}
	else t--; 
	while (s[t] != 0) {
		printf("%c", s[t]);
		t--;
	}
}
