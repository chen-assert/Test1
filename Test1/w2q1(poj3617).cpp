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
char dat[2010];
int cmp(int s, int e) {
	while (s <= e) {
		if (dat[s] == dat[e]) {
			s++;
			e--;
		}
		else {
			return dat[s] - dat[e];
		}
	}
	return 0;
}
int main() {
	input_int(n);
	range0(i, n) {
		while (dat[i] == 0 || dat[i] == '\n' || dat[i]==' ') {
			scanf("%c", &dat[i]);
		}
	}
	int s = 0, e = n - 1;
	int rec = 0;
	while (s<=e) {
		if (rec % 80 == 0 && rec!=0)printf("\n");
		if (cmp(s,e)<0) {
			printf("%c", dat[s]);
			s++;

		}
		else {
			printf("%c", dat[e]);
			e --;
		}
			rec++;
	}
}