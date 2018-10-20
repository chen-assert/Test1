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
int BigRand()
{
	return RAND_MAX * rand() + rand();
}
struct EX {
	int from;
	int to;
	ll rate;
	int way;
};
vector<EX> exlist[81000];
map<string, int>m;
llP save[81000];
int pairnum = 0;
ll MOD = 998244353;
ll pow_(ll a, ll b) {
	ll r = 1, base = a;
	while (b) {
		if (b & 1) r =(r* base)%MOD;
		base = (base*base)%MOD;
		b >>= 1;
	}
	return r;
}
ll gcd(ll a, ll b) {
	if (a%b == 0)
		return b;
	return gcd(b, a%b);
}
void bfs(int a, int b) {
	queue<int>que;
	save[a].first = 1;
	save[a].second = 1;
	que.push(a);
	while (!que.empty()) {
		int t = que.front();
		que.pop();
		for (int o = 0; o < exlist[t].size(); o++) {
			if (save[exlist[t][o].to].first != -1)continue;
			if (exlist[t][o].way == 1) {
				save[exlist[t][o].to].first = (save[t].first * exlist[t][o].rate) % (MOD*MOD);
				save[exlist[t][o].to].second = (save[t].second);
				ll tt = gcd(save[exlist[t][o].to].first, save[exlist[t][o].to].second);
				save[exlist[t][o].to].first /= tt;
				save[exlist[t][o].to].second /= tt;
			}
			else {
				save[exlist[t][o].to].second = (save[t].second * exlist[t][o].rate) % (MOD);
				save[exlist[t][o].to].first = (save[t].first);
				ll tt = gcd(save[exlist[t][o].to].first, save[exlist[t][o].to].second);
				save[exlist[t][o].to].first /= tt;
				save[exlist[t][o].to].second /= tt;
			}
			que.push(exlist[t][o].to);
			if (exlist[t][o].to == b)return;
		}
	}
}
int main() {
	input_int(n);
	char in1[60], in2[60];
	string sin1, sin2;
	ll rate;
	range0(i, n) {
		scanf("%s %s %lld", in1, in2, &rate);
		sin1 = in1;
		sin2 = in2;
		if (m.find(sin1) == m.end()) {
			m.insert(std::pair<string, int>(sin1, pairnum++));
		}
		if (m.find(sin2) == m.end()) {
			m.insert(std::pair<string, int>(sin2, pairnum++));
		}
		exlist[m[sin1]].push_back({ m[sin1], m[sin2], rate ,1});
		exlist[m[sin2]].push_back({ m[sin2], m[sin1], rate ,2});
	}
	input_int(q);
	range0(i, q) {
		scanf("%s %s", in1, in2);
		sin1 = in1;
		sin2 = in2;
		if (m.find(sin1) == m.end()) {
			m.insert(std::pair<string, int>(sin1, pairnum++));
		}
		if (m.find(sin2) == m.end()) {
			m.insert(std::pair<string, int>(sin2, pairnum++));
		}
		range0(i, pairnum) {
			save[i].first = -1;
			save[i].second = -1;
		}
		bfs(m[sin1], m[sin2]);
		if (save[m[sin2]].first==-1) {
			printf("%d\n" ,-1);
		}
		else {
			printf("%lld\n", ((save[m[sin2]].first*pow_(save[m[sin2]].second,MOD-2))) % MOD);
		}
	}
}