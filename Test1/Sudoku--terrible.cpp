#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<cstring>
#include<time.h>
char z[11][11];
int p[11][11];//原始数据是否为0
int find = 0;
int judge2(int x, int y, int i, int t) {
	int sx, sy;
	sy = ((t-1) % 3) * 3+1;
	sx = ((t-1) / 3) * 3+1;
	for (int ix = sx; ix < sx + 3; ix++) {
		for (int iy = sy; iy < sy + 3; iy++) {
			if (ix == x&&iy==y)continue;
			if (z[ix][iy] == i)return 0;
		}
	}
	return 1;
}
int judge(int x, int y, int i) {
	int t = 0;
	for (int ii = 1; ii <= 9;ii++) {//可以剪枝
		if (ii == x)continue;
		if (z[ii][y] == i)return 0;
	}
	for (int ii = 1; ii <= 9; ii++) {//可以剪枝*2
		if (ii == y)continue;
		if (z[x][ii] == i)return 0;
	}
	//if (x > 0 && x <= 3)t += 0;
	if (x > 3 && x <= 6)t += 3;
	if (x > 6 && x <= 9)t += 6;
	if (y > 0 && y <= 3)t += 1;
	if (y > 3 && y <= 6)t += 2;
	if (y > 6 && y <= 9)t += 3;
	return judge2(x,y,i,t);
}
int fill(int x,int y) {
	/*for (int a = 1; a <= 9; a++) {
		for (int b = 1; b <= 9; b++) {
			printf("%d", z[a][b]);
		}
		printf("\n");
	}
	printf("\n");*/
	int e = 0, k = 0,m=0;
	int a = x, b = y;
	if (a == 9 && b > 9) {
		find = 1;
		return 0;
	}
	if (b >9) {
		a++;
		b = 1;
	}
	for (; a <= 9; a++) {
		for (; b <= 9; b++) {
			if (p[a][b] == 1) {
				m = 0;
				for (int i = 1; i <= 9; i++) {
					if (judge(a, b, i) == 1) {
						z[a][b] = i;
						fill(a, b + 1);
						m++;
						if (find == 1)break;
						z[a][b] = 0;
						
					}
					if (find == 1)break;
				}
				if (m == 0) {
					return -1;/*匹配失败  需要回退*/
				}
				k++;
				e = 1;
				break;
			}
			//if (e == 1 || find == 1)break;
		}
		b = 1;
		if (e == 1 || find == 1)break;
	}
	if (k == 0)find = 1;
	return 0;
}
int main() {
	int n;
	memset(p, 0, sizeof(int) * 121);
	//scanf("%d", &n);
	n = 1;
	for (int o = 0; o < n; o++) {
		/*for (int a = 1; a <= 9; a++) {
			scanf("%s", &z[a][1] );
			for (int b = 1; b <= 9; b++) {
				z[a][b]  -='0';
			}
		}*/
		for (int a = 1; a <= 9; a++) {
			for (int b = 1; b <= 9; b++) {
				scanf("%d", &z[a][b]);
			}
		}
		for (int a = 1; a <= 9; a++) {
			for (int b = 1; b <= 9; b++) {
				if (z[a][b] == 0)p[a][b] = 1;
			}
		}
		int e = 0, k = 0,m=0;//需要封装//封不起来
		for (int a = 1; a <= 9; a++) {
			for (int b = 1; b <= 9; b++) {
				if (p[a][b] == 1) {
					for (int i = 1; i <= 9; i++) {
						if (judge(a, b, i) == 1) {
							z[a][b] = i;
							fill(a, b+1);
							m++;
						}
						if (find == 1)break;
					}
					if (m == 0)return -1;/*匹配失败  需要回退*/
					k++;
					e = 1;
					break;
				}
				//if (e == 1|| find == 1)break;
			}
			if (e == 1 || find == 1)break;
		}
		if (k == 0)find = 1;//
		for (int a = 1; a <= 9; a++) {
			for (int b = 1; b <= 9; b++) {
				printf("%d ", z[a][b]);
			}
			printf("\n");
		}
	}
}