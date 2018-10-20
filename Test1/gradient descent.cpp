#include<stdio.h>
#include <stdlib.h> 
#include<algorithm>
#include<limits.h>
#include<time.h>
#include<iostream>
#include<functional>
#include <fstream> 
#include<vector>
#include<queue>
#include<string.h>
#include<stack>
#include <set>
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
int BigRand()
{
	return RAND_MAX * rand() + rand();
}
typedef pair<double, double> cor;
int main() {
	//(x-3)^2+(y-4.5)^2
	//x^2-6x+y^2-9y
	cor xy(0, 0);
	double a = 0.05;
	range0(i, 100) {
		printf("i=%d x=%lf y=%lf t=%lf\n", i, xy.first, xy.second, pow((xy.first - 3), 2) + pow((xy.second - 4.5),2));
		cor diff(2 * xy.first - 6, 2 * xy.second - 9);
		xy.first -= diff.first*a;
		xy.second -= diff.second*a;
	}
}