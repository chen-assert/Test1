#include<stdio.h>
#include<stdlib.h> 
#include<algorithm>
#include<limits.h>
#include<time.h>
#include <math.h>  
#include<iostream>
#include<functional>
#include<fstream> 
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<string.h> 
#include<string> 
#include<map>
//#include"segment tree.h"
//#include<regex>
//#include<windows.h>
using namespace std;
#define range(i, s, e) for (int i = (s); i < int(e); i++)
#define range0(i, e) for (int i = 0; i < int(e); i++)
#define input_int(n) int n;scanf("%d",&n);
#define input_int2(n,m) int n;int m;scanf("%d %d",&n,&m);
#define remax(max_record,refresh_number) max_record=std::max(max_record,refresh_number)
#define remin(min_record,refresh_number) min_record=std::min(min_record,refresh_number)
#define INF 0x3f3f3f3f
#define INF2 INT_MAX
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<ll, ll> llP;
inline void read(int &x) {//only read int
	static char c;
	for (c = getchar(); !('0' <= c && c <= '9'); c = getchar());
	for (x = 0; '0' <= c && c <= '9'; x = x * 10 + c - 48, c = getchar());
}
int in[220000];
int another[220000];
int n;
ll min_ = INF;
ll cal(int s) {
	ll r = 0;
	range0(i, n) {
		r += abs(in[i]-another[i+s]);
	}
	return r;
}
int main() {
	scanf("%d", &n);
	range0(i, n) {
		scanf("%d", &in[i]);
	}
	sort(in, in + n);
	double avg = 0;
	range0(i, n) {
		avg += (double)in[i] / (double)n;
	}
	range0(i, n + 400) {
		another[i] = (int)avg - n / 2 + i-200;
	}
	for (int i = 0; i < 400; i++) {
		ll t = cal(i);
		if (t < min_)min_ = t;
	}
	int mid = in[n / 2];
	range0(i, n + 400) {
		another[i] = (int)mid - n / 2 + i-200;
	}
	for (int i = 0; i < 400; i++) {
		ll t = cal(i);
		if (t < min_)min_ = t;
	}
	printf("%lld", min_);
}

