#include<stdio.h>
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
int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int year1, y2, m1, m2, d1, d2;
int leap_year(int year) {
	if (year % 400 == 0)return 1;
	else if (year % 100 == 0)return 0;
	else if (year % 4 == 0)return 1;
	return 0;
}
void next_year() {
	d1++;
	if (d1 > day[m1]) {
		d1 = 1;
		m1++;
	}
	if (m1 > 12) {
		m1 = 1;
		year1++;
		if (leap_year(year1) == 1)day[2] = 29;
		else day[2] = 28;
	}
}
int cal() {
	int re = 0;
	while (year1 != y2 || m1 != m2 || d1 != d2) {
		re++;
		next_year();
	}
	return re;
}

int flag = 0;
void fail() {
	flag = 1;
	printf("liang qing ruo shi jiu chang shi you qi zai zhao zhao mu mu");
}
int main() {
	
	scanf("%d-%d-%d", &year1, &m1, &d1);
	scanf("%d-%d-%d", &y2, &m2, &d2);
	if (year1 > y2)fail();
	if (year1 == y2 && m1 > m2)fail();
	if (year1 == y2 && m1 == m2 && d1 > d2)fail();
	if (flag == 0) {
		if (leap_year(year1) == 1)day[2] = 29;
		else day[2] = 28;
		printf("%d",cal());
	}
}