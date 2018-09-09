#include<stdio.h>
#include <stdlib.h> 
#include<algorithm>
#include<limits.h>
#include<time.h>
#include<iostream>
#include<functional>
#include<vector>
#include<queue>
#include<string.h>
#include<stack>
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
inline void read(int &x) {//only read int
	static char c;
	for (c = getchar(); !('0' <= c && c <= '9'); c = getchar());
	for (x = 0; '0' <= c && c <= '9'; x = x * 10 + c - 48, c = getchar());
}
inline int BigRand()
{
	return RAND_MAX * rand() + rand();
}
struct node
{
	ll ai, bi, si,id;
	vector<ll>need;
}pro[22];
int n;
inline bool cmp(node A, node B)
{
	return A.ai < B.ai;
}

ll st[1200000];
ll max_ = 0;
ll pow_[22] = { 0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576 };
inline void solu(ll stat, int t, ll sum)
{
	if (sum > max_)max_ = sum;
	if (st[stat] >= sum)return;
	ll f[21];
	for (int i = 1; i <= n; i++) {
		f[i] = (((stat&pow_[i]) != 0) ? 1 : 0);
	}
	for (int i = 1; i <= n; i++)
	{
		if (f[pro[i].id] == 1)continue;
		else {
			int flag = 0;
			for (int o = 0; o < pro[i].need.size(); o++) {
				if (f[pro[i].need[o]] != 1) {
					flag = 1;
					break;
				}
			}
			if (flag == 1)continue;
			ll sco = sum + t * pro[i].ai + pro[i].bi;
			st[stat] = sco;
			solu(stat|(1<<(pro[i].id-1)),t+1,sco);
		}
	}
}

int main()
{
	for (int i = 0; i < 1200000; i++) {
		st[i] = LLONG_MIN;
	}
	scanf("%d", &n);
	for (int q = 1; q <= n; ++q)
	{
		scanf("%lld %lld %lld", &pro[q].ai, &pro[q].bi, &pro[q].si);
		pro[q].id = q ;
		for (int i = 0; i < pro[q].si; ++i) {
			ll t;
			scanf("%lld", &t);
			pro[q].need.push_back(t);
		}
	}
	//sort(pro+1, pro + n+1, cmp);
	solu(0, 1, 0);

	printf("%lld\n", max_);
}