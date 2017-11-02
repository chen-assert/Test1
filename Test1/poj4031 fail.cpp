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
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
vector <int>fun[110];
long long x, y, step;
int dir = 0;
/*
   3
   |
2-----0
   |
   1
*/
ll dep1000;
ll max_;
long long abs_(ll x) {
	if (x > 0)return x;
	else return -x;
}
void check(int dep) {
	if (abs_(x) + abs_(y) > max_)max_ = abs_(x) + abs_(y);
	if (dep == 200)dep1000 = max_;
	if (dep == 400) {
		if (max_ > dep1000) {
			printf("Infinity");
			exit(0);
		}
		else {
			printf("%lld", max_);
			exit(0);
		}
	}
}
void fd(int p, int dep) {
	int len = fun[p].size();
	for (int i = 0; i < len; i++) {
		check(dep);
		switch (fun[p][i]) {
		case -1: {
			switch (dir) {
			case 0:x++; break;
			case 2:x--; break;
			case 1:y--; break;
			case 3:y++; break;
			}
		}
		case -2: {
			dir = (dir - 1 + 4) % 4;
			break;
		}
		case -3: {
			dir = (dir + 1) % 4;
			break;
		}
		default: {
			fd(fun[p][i], dep + 1);
		}
		}
	}
}
int main() {
	input_int(n);
	range(i, 1, n + 1) {
		int len;
		scanf("%d", &len);
		char in[10];
		range0(o, len) {
			scanf("%s", in);
			if (strcmp(in, "GO") == 0) {
				fun[i].push_back(-1);
			}
			else if (strcmp(in, "LEFT") == 0) {
				fun[i].push_back(-2);
			}
			else if (strcmp(in, "RIGHT") == 0) {
				fun[i].push_back(-3);
			}
			else {
				int t = 0;
				int p = 1;
				while (in[p] != 0) {
					t *= 10;
					t += in[p] - '0';
					p++;
				}
				fun[i].push_back(t);
			}
		}
	}
	fd(1, 0);
	printf("%lld", max_);
	return 0;
}