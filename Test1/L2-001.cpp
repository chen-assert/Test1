#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<limits.h>
#include<time.h>
#include<iostream>
#include<functional>
#include<vector>
#include<queue>
#include<string.h>
//#include<regex>
//#include<windows.h>
#define range(i, s, e) for (int i = (s); i < int(e); i++)
#define range0(i, e) for (int i = 0; i < int(e); i++)
#define input_int(n) int n;scanf("%d",&n);
#define input_int2(n,m) int n;int m;scanf("%d %d",&n,&m);
#define remax(max_record,refresh_number) max_record=std::max(max_record,refresh_number)
#define remin(min_record,refresh_number) min_record=std::min(min_record,refresh_number)
#define INF 0x3f3f3f3f
#define INF2 INT_MAX
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
int n, m, s, d;
int num[510];
struct ROUTE {
	int point;//目标
	int length;
};
struct CITY {
	int nowposition;
	int slength;
	bool operator >(const CITY a) const{
		if (slength > a.slength)return true;
		else return false;
	}
	CITY(int num,int slength) {
		this->nowposition = num;
		this->slength = slength;
	}
};
int main() {
	scanf("%d %d %d %d", &n, &m, &s, &d);
	range0(i, n) {
		scanf("%d", &num[i]);
	}
	vector<ROUTE> r[510];
	range0(i, m) {
		int a, b, l;
		scanf("%d %d %d", &a, &b, &l);
		r[a].push_back({ b,l });
		r[b].push_back({ a,l });
	}
	priority_queue<CITY,vector<CITY>,greater<CITY>> city;
	city.push(*new CITY( s,0 ));
	CITY np = city.top();
	int minlen[510];
	int route[510];
	int peo[510];
	memset(minlen, INF, sizeof(int) * 510);
	memset(route, INF, sizeof(int) * 510);
	memset(peo, INF, sizeof(int) * 510);
	minlen[s] = 0;
	route[s] = 1;
	peo[s] = num[s];
	vector<int>trace[510];
	//trace[s].push_back(s);
	while (np.slength < minlen[d]&&!city.empty()) {
		np = city.top();
		city.pop();
		for (int i = 0; i < r[np.nowposition].size(); i++) {
			int point = r[np.nowposition][i].point;
			int length = r[np.nowposition][i].length;
			if (np.slength + length < minlen[point]) {
				minlen[point] = np.slength + length;
				route[point] = route[np.nowposition];
				trace[point].assign(trace[np.nowposition].begin(), trace[np.nowposition].end());
				trace[point].push_back(np.nowposition);
				peo[point] = num[point] + peo[np.nowposition];
				city.push(*new CITY(point, np.slength + length));
			}
			else if (np.slength + length == minlen[point]) {
				route[point] = route[np.nowposition]+route[point];
				if (num[point] + peo[np.nowposition] > peo[point]) {
					trace[point].assign(trace[np.nowposition].begin(), trace[np.nowposition].end());
					trace[point].push_back(np.nowposition);
					peo[point] = num[point] + peo[np.nowposition];
				}
				else {
					//do nothing
				}
				//不用再push了
			}
			else if (np.slength + length > minlen[point]) {
				//do nothing
			}
		}
	}
	printf("%d %d\n", route[d], peo[d]);
	for (int i = 0; i < trace[d].size(); i++) {
		printf("%d ", trace[d][i]);
	}
	printf("%d", d);
}