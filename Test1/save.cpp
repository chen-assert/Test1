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
bool *record;//save whether this is a prime
int *primes;//save the prime list
int num = 0;
void pre_treat(int n) {
	//欧拉筛法
	//是我自己写的吗?
	//已经看不懂了
	n += 10;
	record = new bool[n];
	primes = new int[n];
	memset(record, 0, sizeof(bool)*n);
	memset(primes, 0, sizeof(int)*n);
	record[0] = record[1] = 1;
	for (int i = 2; i <= n / 2 + 1; i++) {
		if (record[i] == 0)primes[num++] = i;
		for (int o = 0; o < num && primes[o] * i <= n; o++) {
			record[primes[o] * i] = 1;//合数标为1，同时，prime[o]是合数i*prime[o]的最小素因子
			if (i%primes[o] == 0) break;//即比一个合数大的质数和该合数的乘积可用一个更大的合数和比其小的质数相乘得到
										//what????
		}
	}
	primes[num++] = n + 100;
}
struct COUNTER{
	int num;
	int shuliang;
};
int s[50010], e[50010];
int save[(int)1e6 + 10];
int ans[(int)1e7+10];
int n, m;
void add(int x) {
	ans[x]++;
}
void bianli(vector<COUNTER>&counter,int sum,int np) {
	if (np >= counter.size()) {
		if (record[sum]==0) {
			add(sum);
		}
		return;
	}
	else {
		bianli(counter, sum, np + 1);
		for (int i = 1; i <= counter[np].shuliang; i++) {
			sum *= counter[np].num;
			bianli(counter, sum, np+1);
		}
	}
}
void find_factor(int i) {
	vector<COUNTER>counter;
	int f = 0;
	while (i >= primes[f]) {
		if (i%primes[f] == 0) {
			i /= primes[f];
			COUNTER count = { primes[f],1 };
			while (i%primes[f] == 0) {
				i /= primes[f];
				count.shuliang++;
			}
			counter.push_back(count);
		}
		f++;
	}
	bianli(counter, 1,0);
}
ll out[(int)1e7 + 10];
void xx() {
	range(i,1, 1e7 + 5) {
		out[i] = ans[i] + out[i - 1];
	}
}
int main() {
	clock_t t1 = clock();
	pre_treat(1e7);
	clock_t t2 = clock();
	scanf("%d", &n);
	range0(i, n) {
		read(save[i]);
	}
	scanf("%d", &m);
	range0(i, m) {
		read(s[i]);
		int t ;
		read(t);
		if (t > 1e7+2)e[i] = 1e7+2;
		else e[i] = t;
	}
	range0(i, n) {
		find_factor(save[i]);
	}
	xx();
	range0(i, m) {
		printf("%lld\n", out[e[i]]-out[s[i]-1],0);
	}
	//考虑用区间和
}