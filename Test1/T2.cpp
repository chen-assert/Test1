#include<stdio.h>
char m[100][100] = { '\0' };
int judge1(int x, int y, int c) {
	int q = 1;
	for (int i = x; i < x + c; i++) {
		if (m[i][y] == '#') {
			q -= 1;
			break;
		}
	}
	
	return q;
}
int judge2(int x, int y, int c) {
	int q = 1;
	for (int i = y; i < y + c; i++) {
		if (m[x][i] == '#') {
			q -= 1;
			break;
		}
	}
	return q;
}
int main() {
	int a, b,c;
	scanf("%d %d %d", &a, &b, &c);
		for(int i=0;i<b;i++){
		scanf("%s",m[i]);
	}
	int sum = 0;
	for (int x = 0; x <= a - c; x++) {
		for (int y = 0; y <b; y++) {
			sum+=judge1(x, y, c);//ºáÏò
		}
	}
	for (int x = 0; x < a; x++) {
		for (int y = 0; y <= b - c; y++) {
			sum += judge2(x, y, c);//ÊúÏò
		}
	}
	if (c == 1)sum /= 2;
	printf("%d", sum);
}