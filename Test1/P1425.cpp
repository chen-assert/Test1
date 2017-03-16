#include<stdio.h>
int main() {
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int h, m;
	h = c - a;
	m = d - b;
	if (m >= 60) { 
		m -= 60;
		h += 1;
	}
	if (m < 0) {
		m += 60;
		h -= 1;
	}
	printf("%d %d", h, m);
}