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
int save[120];
int n;
int que0() {
	printf("Q");
	range0(o, n) {
		printf(" %d", 0);
	}
	printf("\n");
	fflush(stdout);
	input_int(t);
	return t;
}
int que1(int a1) {
	printf("Q");
	range0(o, n) {
		if (o == a1) {
			printf(" %d", 1);
		}
		else printf(" %d", 0);
	}
	printf("\n");
	fflush(stdout);
	input_int(t);
	return t;
}
int que2(int a1, int a2) {
	printf("Q");
	range0(o, n) {
		if (o == a1 || o == a2) {
			printf(" %d", 1);
		}
		else printf(" %d", 0);
	}
	printf("\n");
	fflush(stdout);
	input_int(t);
	return t;
}
int que4(int a1, int a2, int a3, int a4) {
	printf("Q");
	range0(o, n) {
		if (o == a1 || o == a2 || o == a3 || o == a4) {
			printf(" %d", 1);
		}
		else printf(" %d", 0);
	}
	printf("\n");
	fflush(stdout);
	input_int(t);
	return t;
}
int main() {
	input_int(mmm);
	range0(i, mmm) {
		range0(i, 120)save[i] = -1;
		int num = 0;
		scanf("%d", &n);
		printf("Q");
		range0(i, n) {
			printf(" %d", 0);
		}
		printf("\n");
		fflush(stdout);
		scanf("%d", &num);
		if ((num <= 20 || num >= 80)&&n==100) {
			for (int i = 0; i < 25; i++) {
				int sq = 0;
				printf("Q");
				range0(o, n) {
					if (o <= i * 4 + 3 && o >= i * 4) {
						printf(" %d", 1);
					}
					else printf(" %d", 0);
				}
				printf("\n");
				fflush(stdout);
				scanf("%d", &sq);
				if (sq == num + 4) {
					save[i * 4] = save[i * 4 + 1] = save[i * 4 + 2] = save[i * 4 + 3] = 1;
					continue;
				}
				else if (sq == num) {
					save[i * 4] = save[i * 4 + 1] = save[i * 4 + 2] = save[i * 4 + 3] = 0;
					continue;
				}
				else {
					int ld, rd;
					printf("Q");
					range0(o, n) {
						if (o == i * 4 || o == i * 4 + 1) {
							printf(" %d", 1);
						}
						else printf(" %d", 0);
					}
					printf("\n");
					fflush(stdout);
					input_int(t);
					ld = t - sq;
					rd = sq - num - ld;
					int lld, lrd, rld, rrd;
					if (ld == 2) {
						save[i * 4] = save[i * 4 + 1] = 1;
					}
					else if (ld == 0) {
						save[i * 4] = save[i * 4 + 1] = 0;
					}
					else {
						lld = que1(i * 4);
						lrd = ld - lld;
						if (lld == 1)save[i * 4] = 1;
						else save[i * 4] = 0;
						if (lrd == 1)save[i * 4 + 1] = 1;
						else save[i * 4 + 1] = 0;
					}
					if (rd == 2) {
						save[i * 4 + 2] = save[i * 4 + 3] = 1;
					}
					else if (rd == 0) {
						save[i * 4 + 2] = save[i * 4 + 3] = 0;
					}
					else {
						rld = que1(i * 4 + 2);
						rrd = rd - rld;
						if (rld == 1)save[i * 4 + 2] = 1;
						else save[i * 4 + 2] = 0;
						if (rrd == 1)save[i * 4 + 3] = 1;
						else save[i * 4 + 3] = 0;
					}
				}
			}
		}
		else if ((num <= 40 || num >= 60) && n == 100) {
			for (int i = 0; i < 50; i++) {
				int dd = que2(i * 2, i * 2 + 1);
				int ld, rd;
				if (dd == 2) {
					save[i * 2] = save[i * 2 + 1] = 1;
				}
				else if (dd == 0) {
					save[i * 2] = save[i * 2 + 1] = 0;
				}
				else {
					ld = que1(i * 2);
					rd = dd - ld;
					if (ld == 1)save[i * 2] = 1;
					else save[i * 2] = 0;
					if (rd == 1)save[i * 2 + 1] = 1;
					else save[i * 2 + 1] = 0;
				}
			}
		}
		else {
			range0(i, n-1) {
				printf("Q");
				range0(o, n) {
					if (i == o)printf(" 1");
					else printf(" 0");
				}
				printf("\n");
				fflush(stdout);
				input_int(t);
				if (t == num + 1)save[i] = 1;
				else save[i] = 0;
			}
			int sum = 0;
			range0(i, n-1) {
				if (save[i] == 0)sum++;
			}
			if (sum == num)save[n-1] = 1;
			else save[n-1] = 0;
		}
		fflush(stdout);
		printf("A");
		range0(i, n) {
			printf(" %d", save[i]);
		}
		fflush(stdout);
	}
}