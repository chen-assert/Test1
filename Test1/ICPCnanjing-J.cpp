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
int BigRand()
{
	return RAND_MAX * rand() + rand();
}
struct node {
	int x, y, v, num;
};
bool *record;
int sfi2[12500000];
int sfinum = 0;
void pre_treat2(int n) {
	n += 10;
	record = new bool[n];
	memset(record, 0, sizeof(bool)*n);
	for (int i = 2; i < 5000; i++) {
		for (int o = 1; o*i*i < n; o++) {
			record[o*i*i] = 1;
		}
		//printf("%d\n", i);
	}

	for (int i = 1; i < n; i++) {
		//if (record[i] == 0)sfi.push_back(i);
		if (record[i] == 0)sfi2[sfinum++] = i;
	}
	return;
}
int sum[(int)2e7 + 10];
ll summ[(int)2e7 + 10];
int main() {
	pre_treat2(2e7);
	input_int(t);
	int len = sfinum;
	for (register int i = 0; i < 5000; i++) {
		for (register int o = i;; o++) {
			int t = sfi2[i] * sfi2[o];
			if (t > (int)2e7)break;
			if (i == o)sum[t]++;
			else sum[t] += 2;
		}
	}
	summ[0] = sum[0];
	for (int i = 1; i <= (int)2e7; i++) {
		summ[i] = sum[i] + summ[i - 1];
	}
	range0(i, t) {
		input_int(n);
		printf("%lld\n", summ[n]);
	}
	return 0;
}