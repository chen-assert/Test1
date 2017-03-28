#include<stdio.h>
#include<queue>
using namespace std;
int n;
int p[50][50];
queue<int>x;
queue<int>y;
void push(int a, int b) {
	if (a >= 0 && a <= n + 1 && b >= 0 && b <= n + 1) {
		x.push(a);
		y.push(b);
	}
	return;
}
void find1() {
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			if (p[a][b] == 0) {
				x.push(a);
				y.push(b);
				return;
			}
		}
	}
	return;
}
void c02() {
	int nx, ny;
	while (1) {
		nx = x.front();
		ny = y.front();
		if (p[nx][ny] == 0) {
			p[nx][ny] = 2;
			push(nx, ny - 1);
			push(nx, ny + 1);
			push(nx + 1, ny);
			push(nx - 1, ny);
		}
		x.pop();
		y.pop();
		if (x.empty() == 1)return;
	}
}
void c01() {
	int nx, ny;
	while (1) {
		nx = x.front();
		ny = y.front();
		if (p[nx][ny] == 0) { 
			p[nx][ny] = 1;
			push(nx , ny - 1);
			push(nx , ny + 1);
			push(nx + 1, ny );
			push(nx - 1, ny );
		}
		x.pop();
		y.pop();
		if (x.empty() == 1)return;
	}
}
int main() {
	scanf("%d", &n);
	/*int **p = new int *[n+2];
	for (int i = 0; i < n+2; i++)p[i] = new int[n + 2]{ 0 };*/
	for (int x = 0; x <= n + 1; x++) {
		for (int y = 0; y <= n + 1; y++) {
			p[x][y] = 0;
		}
	}
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			scanf("%d", &p[x][y]);
		}
	}
	x.push(0);
	y.push(0);
	c01();
	find1();
	c02();
	for (int x = 1; x <= n ; x++) {
		
		for (int y = 1; y <= n; y++) {
			printf("%d ", p[x][y]);
		}
		printf("\n");
	}
}