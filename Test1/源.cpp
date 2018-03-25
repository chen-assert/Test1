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
int user[1010][1010];
vector<int> user2[1010];
vector<int> like2[1010];
vector<int> data_[1010];
int use_user[1010];
int use_like[1010];
int find(int like,int d) {
	if (use_like[like] == 1)return 0;
	use_like[like] = 1;
	for (int i = 0; i < like2[like].size(); i++) {
		data_[d].push_back(like2[like][i]);
		for (int o = 0; o < user2[like2[like][i]].size(); o++) {
			find(user2[like2[like][i]][o], d);
		}
	}
	return 1;
}
int main() {
	int n;
	scanf("%d", &n);
	range(i, 1, n + 1) {
		int p;
		scanf("%d:",&p);
		range0(o, p) {
			int t;
			scanf("%d", &t);
			user[i][t] = 1;
			user2[i].push_back(t);
			like2[t].push_back(i);
		}
	}
	int d = 0;
	for (int i = 1; i <= 1000; i++) {
		d += find(i, d);
	}
	for (int i = 0; i < 1000; i++) {
		sort(data_[i].begin(), data_[i].end());
		std::vector<int>::iterator it;
		it = std::unique(data_[i].begin(), data_[i].end());
		data_[i].resize(std::distance(data_[i].begin(), it));
	}
	vector<int>out;
	for (int i = 0; i <1000; i++) {
		if (data_[i].size() != 0)out.push_back(data_[i].size());
	}
	sort(out.begin(), out.end(),greater<int>());
	printf("%d\n", out.size());
	for (vector<int>::iterator it = out.begin(); it != out.end(); it++) {
		printf("%d", *it);
		if (it != out.end())printf(" ");
	}
}