#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct brick {
	int x;
	int y;
	int z;
	int h;
};
brick *zt = (brick*)malloc(sizeof(brick) * 200);
int lx = 0, ly = 0, sz = 0, maxi = 0, place = 0;
void dfs(int z) {
	sz += zt[z].z;
	if (sz > maxi)maxi = sz;
	for (int i=0; i < place; i++) {
		if (zt[i].x < zt[z].x && zt[i].y < zt[z].y) {
			dfs(i);
		}
	}
	sz -= zt[z].z;
}
int main() {
	int number=0;
	int x = 0, y = 0, z = 0;
	while (1) {
		sz = 0;
		maxi = 0;
		scanf("%d", &number);
		if (number == 0)return 0;
		
		place = 0;
		for (int i = 0; i < number; i++) {
			scanf("%d %d %d", &x, &y, &z);
			{
				if (y > x) {//let x>=y
					zt[place].x = y;
					zt[place].y = x;
					zt[place].z = z;
				}
				else {
					zt[place].x = x;
					zt[place].y = y;
					zt[place].z = z;
				}
				zt[place].h = z;
				place++;
				if (x > z) {
					zt[place].x = x;
					zt[place].y = z;
					zt[place].z = y;
				}
				else {
					zt[place].x = z;
					zt[place].y = x;
					zt[place].z = y;
				}
				zt[place].h = y;
				place++;
				if (y > z) {
					zt[place].x = y;
					zt[place].y = z;
					zt[place].z = x;
				}
				else {
					zt[place].x = z;
					zt[place].y = y;
					zt[place].z = x;
				}
				zt[place].h = x;
				place++;//may need revise
			}
		}
		/*for (int i = 0; i < place; i++) {
			dfs(i);
		}*/
		int test = 1;
		while (test == 1) {
			test = 0;
			for (int a = 0; a < place; a++) {
				for (int b = 0; b < place; b++) {
					if (zt[a].z + zt[b].h <= zt[a].h)continue;
					if (zt[a].x > zt[b].x && zt[a].y > zt[b].y) {//b can ∑≈‘⁄a…œ
						zt[a].h= zt[a].z + zt[b].h;
						test=1;
					}
				}
			}
		}
		for (int i = 0; i < place; i++) {
			if (maxi < zt[i].h)maxi = zt[i].h;
		}
		printf("%d\n", maxi);
	}
	free(zt);
}