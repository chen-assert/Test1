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
#include <set>
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
struct TRACE
{
	ll x;
	ll y;
	bool operator<(const struct TRACE & right)const   //ÖØÔØ<ÔËËã·û
	{
		if (this->y != right.y)
			return this->y > right.y;
		else
		{
			return this->x < right.x;
		}
	}
}trace[50010];
set<TRACE> save;
ll check(int x, int y) {
	TRACE n = { x,y };
	std::set<TRACE>::iterator itl, itr;
	itl = itr = save.upper_bound(n);
	itl--;
	ll r = 0;
	r += n.x - ((*itl).x);
	r += n.y - ((*itr).y);
	return r;
}
int main() {
	ll sum = 0;
	input_int(n);

	save.insert({ 20000010,0 });
	save.insert({ 0, 20000010 });
	range0(i, n) {
		input_int2(x, y);
		trace[i] = { x,y };
	}
	for (int i = n - 1; i>=0; i --) {
		sum += check(trace[i].x, trace[i].y);
		save.insert({ trace[i].x,trace[i].y });
	}
	printf("%lld", sum);
}