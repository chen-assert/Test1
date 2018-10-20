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
char in[100];
string sstr[25];
int weight[30];
int main() {
	range0(i, 30)weight[i] = 10;
	int m, n;
	scanf("%d,%d", &m, &n);
	range0(i, n) {
		scanf("%s", in);
		string strin = in;
		int len = strlen(in);
		sstr[i * 2] = strin.substr(0, (len - 1) / 2);
		sstr[i * 2 + 1] = strin.substr((len - 1) / 2 + 1, (len - 1) / 2);
	}
	for (int a = 0; a < m*m; a++) {
		for (int b = a + 1; b < m*m; b++) {
			if (a%m <= a / m || b % m <= b / m)continue;
			int sum1 = 0, sum2 = 0;
			weight[a / m] = weight[a % m] = 9;
			range0(i, n) {
				int left = 0, right = 0;
				range0(o, sstr[i * 2].length()) {
					left += weight[sstr[i * 2][o] - 'A'];
					right += weight[sstr[i * 2 + 1][o] - 'A'];
				}
				if (left < right) {
					sum1 *= 3;
					sum1 += 0;
				}
				else if (left == right) {
					sum1 *= 3;
					sum1 += 1;
				}
				else {
					sum1 *= 3;
					sum1 += 2;
				}
			}
			weight[a / m] = weight[a % m] = 10;
			weight[b / m] = weight[b % m] = 9;
			range0(i, n) {
				int left = 0, right = 0;
				range0(o, sstr[i * 2].length()) {
					left += weight[sstr[i * 2][o] - 'A'];
					right += weight[sstr[i * 2 + 1][o] - 'A'];
				}
				if (left < right) {
					sum2 *= 3;
					sum2 += 0;
				}
				else if (left == right) {
					sum2 *= 3;
					sum2 += 1;
				}
				else {
					sum2 *= 3;
					sum2 += 2;
				}
			}
			weight[b / m] = weight[b % m] = 10;
			if (sum1 == sum2) {
				printf("%c%c=%c%c\n", a / m + 'A', a % m + 'A', b / m + 'A', b% m + 'A');
			}
		}
	}
}