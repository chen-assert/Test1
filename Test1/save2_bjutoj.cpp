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
int a, b, c, d, n, cc, dd;
int map[4096][4096];
int xx = 2048, yy = 2048;
int step[4096][4096];
struct PP {
	int x;
	int y;
	int st;
};
inline int abs_(int x) {
	if (x > 0)return x;
	else return -x;
}
struct cmp {
	bool operator()(PP a, PP b) {
		return a.st + abs_(c - a.x) + abs_(d - a.y) > b.st + abs_(c - b.x) + abs_(d - b.y);
	}
};
void a_star() {
	priority_queue<PP, vector<PP>, cmp>s;
	s.push({ a - 1,b,0 });
	s.push({ a + 1,b ,0 });
	s.push({ a,b - 1 ,0 });
	s.push({ a,b + 1 ,0 });
	while (!s.empty()) {
		PP zb = s.top();
		s.pop();
		if (step[zb.x + xx][zb.y + yy] <= zb.st + 1)continue;
		if (map[zb.x + xx][zb.y + yy] == 1)continue;
		if (abs(zb.x) > 1010 || abs(zb.y) > 1010)continue;
		step[zb.x + xx][zb.y + yy] = zb.st + 1;
		if (zb.x == c && zb.y == d)return;
		//if (zb.st > step[c+xx][d+yy] + 10)return;
		s.push({ zb.x - 1,zb.y,zb.st + 1 });
		s.push({ zb.x + 1,zb.y,zb.st + 1 });
		s.push({ zb.x,zb.y - 1,zb.st + 1 });
		s.push({ zb.x,zb.y + 1,zb.st + 1 });
	}
	//printf("%d\n",i);
	step[a + xx][b + xx] = 0;
}
int main() {
	range0(i, 4096) {
		memset(step[i], 127, sizeof(int) * 4096);
	}
	scanf("%d %d %d %d %d", &a, &b, &cc, &dd, &n);
	if (cc >= 1005) {
		c = 1005;
	}
	else if(cc<=-1005){
		c = -1005;
	}
	else {
		c = cc;
	}
	if (dd >= 1005) {
		d = 1005;
	}
	else if (dd <= -1005) {
		d = -1005;
	}
	else {
		d = dd;
	}
	int x, y;
	range0(i, n) {
		read(x);
		read(y);
		map[xx + x][yy + y] = 1;
	}
	a_star();
	printf("%d", step[xx + c][yy + d]+abs_(cc-c)+abs_(dd-d));
}