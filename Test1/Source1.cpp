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
int size_, p, s, l,k;
struct shortcut {
	P from;
	P to;
};
map<P, P>shortway;
P pos[12];
int next(int player,int ) {

}
int main() {
	range0(i, 10) {
		pos[i] = P(0, 1);
	}
	scanf("%d", &size_);
	scanf("%d", &p);
	scanf("%d", &s);
	int fx, fy, ax, ay;
	range0(i, s) {
		scanf("%d %d %d %d", &fx, &fy, &ax, &ay);
		shortway.insert(P(fx, fy), P(ax, ay));
	}
	scanf("%d", &l);
	range0(i, l) {
		scanf("%d %d %d %d", &fx, &fy, &ax, &ay);
		shortway.insert(P(fx, fy), P(ax, ay));
	}
	scanf("%d", &k);
	range0(i, k) {

	}
}