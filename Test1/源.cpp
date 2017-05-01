#include<stdio.h>
#include<stdlib.h>
//#include<algorithm>
//#include<iostream>
#include<math.h>
#include<string.h>
#include<time.h>
//#include<vector>
using namespace std;
#include<queue>
int n;
int xx[210];
int yy[210];
int whether[210];
double distancee[210][210];
double dis(int a, int b) {
	double dx = abs(xx[a] - xx[b]);
	double dy = abs(yy[a] - yy[b]);
	return sqrt(dx*dx+dy*dy);
}
void pretreat(){
	for (int a = 1; a <= n; a++) {
		distancee[a][a] = 0;
		for (int b = a + 1; b <= n; b++) {
			distancee[a][b] = distancee[b][a] = dis(a, b);
		}
	}
}
int tryy(double x) {//1-can  -1-can't
	memset(whether, 0, 210 * sizeof(int));
	queue<int>q;
	q.push(1);
	whether[1] = 1;
	while (q.empty() != 1) {
		int t = q.front();
		q.pop();
		for (int i = 2; i<=n; i++) {
			if (whether[i] == 1)continue;
			if (dis(i, t) <= x) {
				whether[i] = 1;
				q.push(i);
			}
		}
	}
	//if (whether[n] == 1)return 1;
	//else return 0;
	return whether[n];

}
int main() {
	scanf("%d", &n);
	int c = 0;
	while (n != 0) {
		c++;
		scanf("%d %d %d %d", &xx[1], &yy[1], &xx[n], &yy[n]);
		for (int i = 2; i <= n-1; i++)scanf("%d %d", &xx[i], &yy[i]);
		pretreat();
		double s = 0, e = 2000;
		while (e - s > 0.0001) {
			double p = (e - s) / 2;
			if (tryy(s+p) == 0)s +=p;
			 p = (e - s) / 2;
			if (tryy(e-p) == 1)e -=p;
		}


		printf("Scenario #%d\n",c);
		printf("Frog Distance = %.3f\n\n", s);
		scanf("%d", &n);
	}
}
	