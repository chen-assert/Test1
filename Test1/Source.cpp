#include<stdio.h>
#include<stdlib.h> 
#include<algorithm>
#include<limits.h>
#include<time.h>
#include<math.h>  
#include<iostream>
#include<fstream> 
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<string> 
#include<map>
#include<regex>
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
bool *record;//save whether this is a prime
int *primes;//save the prime list
int num = 0;
void pre_treat(int n) {
	//欧拉筛法
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
	//primes[num++] = n + 100;
	//这句是干吗的?
}
int main() {
	pre_treat(1000);
	int T;
	cin >> T;
	while (T--) {
		int B, N;
		cin >> B >> N;
		if (record[B] == 0)printf("%d\n", B*N);
		else 
		{
			int last = 1;
			int num = 0;
			int flag = 0;
			int i = 0;
			for (i = 1;num<N; i++) {
				last *= i;
				while (last%B == 0) {
					last /= B;
					num++;
				}
				while (last > B*B) {
					last %= B * B;
				}
				if (num == N) {
					flag = 1;
					break;
				}
			}
			if (flag == 0)printf("%d\n",-1);
			else {
				printf("%d\n",i);
			}
		}
	}
}