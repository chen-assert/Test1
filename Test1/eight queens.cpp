#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
using namespace std;
int n;
int s = 0;
bool b[256][4] = { 0 };//1/2/3层分别为行，左斜，右斜//0-可行 1-不可行
					   //int research(int depth, int q[]) {
					   //	for (int i = 1; i < depth; i++) {
					   //		if (q[depth] == q[i])return 0;
					   //	}
					   //	return 1;
					   //}
					   //int judge2(int *x1, int *y1, int *x2, int *y2) {//fail return -1
					   //	if (*x1 + *y1 == *x2 + *y2 || *x1 - *y1 == *x2 - *y2) {
					   //		return -1;
					   //	}
					   //	return 0;
					   //}
					   //int research2(int depth, int q[]) {
					   //	int b = depth;
					   //	for (int a = 1; a < depth; a++) {
					   //		if (judge2(&a, &q[a], &b, &q[b]) == -1) {
					   //			return 0;
					   //		}
					   //	}
					   //	return 1;
					   //}
void search(int depth, int q[]) {
	for (int i = 1; i <= n; i++) {
		q[depth] = i;
		if (b[i][1] == 1 || b[i + depth + n][2] == 1 || b[i - depth + n][3] == 1)continue;
		/*if (research(depth, q) == 0)continue;
		if (research2(depth, q) == 0)continue;*/
		b[i][1] = 1;
		b[i + depth + n][2] = 1;
		b[i - depth + n][3] = 1;
		if (depth == n) {
			s++;
			if (s <= 3) {
				for (int m = 1; m < n; m++) {
					printf("%d ", q[m]);
				}
				printf("%d\n", q[n]);
			}
		}
		search(depth + 1, q);
		b[i][1] = 0;
		b[i + depth + n][2] = 0;
		b[i - depth + n][3] = 0;
	}

	return;
}
int main() {
	scanf("%d", &n);
	//n = 13;
	int *p = (int*)malloc(sizeof(int)*(n + 2));
	for (int i = 0; i < n + 1; i++)p[i] = 0;
	search(1, p);
	printf("%d", s);
	free(p);
}