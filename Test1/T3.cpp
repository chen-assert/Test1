#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<limits.h>
#include<queue>
#include<time.h>
#include<stack>
#include<map>
//#include"segment tree.h"
#define range(i, s, e) for (int i = s; i < int(e); i++)
#define range0(i, e) for (int i = 0; i < int(e); i++)
#define input_int(n) int n;scanf("%d",&n);
int inf=0x3f3f3f3f;
//#include<windows.h>
int p = 100010;
using namespace std;
int ans = 0;
int ttt = 0;
bool record[100010];
int prime[100000];
int dfs(int a,int b,int max_) {
	if (a == 1) {
		if (b == 1)ans = 1;
		return 0;
	}
	for (int* t = lower_bound(prime,prime+ttt,min((int)sqrt(max(a, b)),max_));t>=prime; t--) {
		if (a%*t != 0 || b%*t != 0)continue;

		if (a % (*t**t) == 0) {
			dfs(a / *t / *t, b / *t,*t);
		}
		if (b % (*t**t) == 0) {
			dfs(a / *t, b / *t / *t,*t);
		}
	}
	return 0;
}
int sai(int a) {
	for (int i = 2 * a; i <= p-5; i += a) {
		if (record[i] == 0)record[i] = 1;
		//printf("%d ", a*i);
	}
	for (int i = a + 1;; i++) {
		if (record[i] == 0)return i;
	}
}
int main() {
	memset(record, 0, sizeof(bool) * p);
	int t = 2;
	while (1) {
		t = sai(t);
		int tt = (int)sqrt(p);
		if (t > tt)break;
		//printf("%d\n",t);
	}
	record[1] = 1;
	ttt = 0;
	for (int i = 2; i <= p-5; i++) {
		if (record[i] == 0)prime[ttt++] = i;
	}
	input_int(n);
	range0(i, n) {
		int a, b;
		scanf("%d %d", &a, &b);
		dfs(a, b,inf);
		if (ans == 1)printf("YES\n");
		else printf("NO\n");
		ans = 0;
	}
}