#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<limits.h>
#include<queue>
#include<time.h>
#include<stack>
#include<map>
#include<iostream>
#include<string.h>
#include<functional>
//#include"segment tree.h"
//#include<windows.h>
#define range(i, s, e) for (int i = (s); i < int(e); i++)
#define range0(i, e) for (int i = 0; i < int(e); i++)
#define input_int(n) int n;scanf("%d",&n);
#define input_int2(n,m) int n;int m;scanf("%d %d",&n,&m);
#define INF 0x3f3f3f3f
#define INF2 INT_MAX
using namespace std;
typedef unsigned long long ull;
typedef pair<int, int> P;
int x[110];
int y[110];
#define acc 4
int graph[acc * 1010][acc * 1010];
int draw(int q, int w) {
	int write = q * 101 + w;
	//graph[x[q]][y[q]] = graph[x[w]][y[w]] = 1;
	int disx = abs(x[q] - x[w]);
	int disy = abs(y[q] - y[w]);
	if (disx > disy) {
		if (x[q] < x[w]) {
			double xielv = ((double)(y[w] - y[q])) / double(x[w] - x[q]);
			for (int i = x[q]; i <= x[w]; i++) {
				int ty = y[q] + (int)((i - x[q])*xielv + 0.5);
				if (graph[i][ty] != 0 && ty != y[w] && ty != y[q])return graph[i][ty];
				ty = y[q] + (int)((i - x[q])*xielv);
				if (graph[i][ty] != 0 && ty != y[w] && ty != y[q])return graph[i][ty];
				graph[i][ty] = write;
			}
		}
		else {	//x[q] > x[w]
			double xielv = ((double)(y[q] - y[w])) / double(x[q] - x[w]);
			for (int i = x[w]; i <= x[q]; i++) {
				int ty = y[w] + (int)((i - x[w])*xielv + 0.5);
				if (graph[i][ty] != 0 && ty != y[q] && ty != y[w])return graph[i][ty];
				ty = y[w] + (int)((i - x[w])*xielv);
				if (graph[i][ty] != 0 && ty != y[q] && ty != y[w])return graph[i][ty];
				graph[i][ty] = write;
			}
		}
	}
	else {
		if (y[q] < y[w]) {
			double xielv = ((double)(x[w] - x[q])) / double(y[w] - y[q]);
			for (int i = y[q] ; i <= y[w]; i++) {
				int tx = x[q] + (int)((i - y[q])*xielv + 0.5);
				if (graph[tx][i] != 0 && tx != x[w] && tx != x[q])return graph[tx][i];
				tx = x[q] + (int)((i - y[q])*xielv);
				if (graph[tx][i] != 0 && tx != x[w] && tx != x[q])return graph[tx][i];
				graph[tx][i] = write;
			}
		}
		else {	//y[q] > y[w]
			double xielv = (double)(x[q] - x[w]) / double(y[q] - y[w]);
			for (int i = y[w] ; i <= y[q]; i++) {
				int tx = x[w] + (int)((i - y[w])*xielv + 0.5);
				if (graph[tx][i] != 0 && tx != x[q] && tx != x[w])return graph[tx][i];
				tx = x[w] + (int)((i - y[w])*xielv);
				if (graph[tx][i] != 0 && tx != x[q] && tx != x[w])return graph[tx][i];
				graph[tx][i] = write;
			}
		}
	}
	return 0;
}
int main() {
	input_int(t);
	char save[110];
	range0(i, t) {
		input_int(n);
		range0(o, acc * 1010) {
			memset(graph[o], 0, sizeof(int) * acc * 1010);
		}
		memset(save, 'A', sizeof(char) * 110);
		range0(o, n) {
			int xt, yt;
			scanf("%d %d", &xt, &yt);
			x[o] = xt * acc;
			y[o] = yt * acc;
		}
		int jump = 0;
		for (int q = 0; q < n; q++) {
			for (int w = q + 1; w < n; w++) {
				int k = draw(q, w);
				if (k != 0) {
					printf("YES\n");
					save[k / 101] = 'A';
					save[k % 101] = 'A';
					save[q] = 'B';
					save[w] = 'B';
					for (int p = 0; p < n; p++) {
						printf("%c", save[p]);
					}
					printf("\n");
					jump = 1;
					break;
				}
			}
			if (jump == 1)break;
		}
		if (jump == 0)printf("NO\n");
	}
}