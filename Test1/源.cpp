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
struct W {
	int s;
	int e;
	bool friend operator<(W a,W b){
		return a.e < b.e;
	}
}w[100010];
int main(){
	input_int(n);
	range0(i, n) {
		scanf("%d %d", &w[i].s, &w[i].e);
	}
	sort(w, w + n);
	int t = 0;
	int sum = 0;
	//printf("%d", INF2);
	for (int i = 0; i < n; i++) {
		if (t < w[i].s) {
			sum++;
			t = w[i].e;
		}
	}
	printf("%d", sum);
}