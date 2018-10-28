#include<stdio.h>
#include<math.h>
#include<stdlib.h> 
#include<algorithm>
#include<limits.h>
#include<time.h>
#include<iostream>
#include<functional>
#include<fstream> 
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<string.h> 
#include<string> 
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
struct course {
	int a, b;
	int use;
}c[500];
bool cmp(course a, course b) {
	if (a.b == b.b)return a.a < b.a;
	else return a.b < b.b;
}
int main() {
	int n;
	while (1) {
		scanf("%d", &n);
		if (n == 0)break;
		range0(i, n) {
			scanf("%d %d", &c[i].a, &c[i].b);
			//c[i].use = 0;
		}
		int max_ = 0;
		sort(c, c + n, cmp);
		for (int i = 0; i <= 4; i++) {
			range0(i, n)c[i].use = 0;
			int t = i;
			int nc = 0;
			while (t<=1010) {
				lable:;
				for (int o = 0; o < n; o++) {
					if (c[o].use==0&&t >= c[o].a&&t < c[o].b) {
						c[o].use = 1;
						t += 5;
						nc++;
						goto lable;
					}
				}
				t += 5;
			}
			if (nc > max_)max_ = nc;
		}
		printf("%d\n", max_);
	}
}