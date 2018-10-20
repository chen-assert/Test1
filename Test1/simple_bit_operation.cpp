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
int main() {
	input_int2(n, s);
	int *array = new int(n);
	range0(i, n)scanf("%d", &array[i]);
	for (int i = 1; i <= (1 << (n - 1)); i++) {
		int sum = 0;
		for (int o = 0; o < n; o++) {
			if ((1<<o)&i)sum += array[o];
		}
		if (sum == s) {
			for (int o = 0; o < n; o++) {
				int flag = 0;
				if ((1 << o)&i) {
					printf(" %d ", array[o]);
				}
			}
			printf("=%d\n", s);
		}
	}
}