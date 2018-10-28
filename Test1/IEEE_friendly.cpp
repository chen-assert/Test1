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
#include<string> 
#include<map>
//#include"segment tree.h"
#include<regex>
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
int n;
int in[100010];
int mod = (int)1e9 + 7;
int dfs(int pos, int num, int sum) {
	if (pos == n)return 1;
	/*if((n-pos)*num+sum>in[n-1]){
		return 0;
	}
	
	for (int i = pos+1;i<n; i++) {
		if ((i-pos+1)*num+sum>in[i]) {
			return 0;
		}
		if ((i - pos + 1)*num + sum == in[i]) {
			return dfs(i,num,in[i]-num);
		}
	}*/
	int re = 0;
	for (int i = num; sum + i <= in[pos]; i++) {
		if ((n - pos)*i + sum > in[n - 1])break;
		re = (re + dfs(pos + 1, i, sum + i)) % mod;
	}
	return re;
}
int main() {
	scanf("%d", &n);
	range0(i, n) {
		scanf("%d", &in[i]);
	}
	int min = in[n - 1];
	for (int i = n - 1; i >= 0; i--) {
		if (in[i] < min)min = in[i];
		else in[i] = min;
	}
	printf("%d", dfs(0, 0, 0) % mod);
}