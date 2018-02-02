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
using namespace std;
#define range(i, s, e) for (int i = (s); i < int(e); i++)
#define range0(i, e) for (int i = 0; i < int(e); i++)
#define input_int(n) int n;scanf("%lld",&n);
#define input_int2(n,m) int n;int m;scanf("%lld %lld",&n,&m);
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
struct SAVE {
	int num[28];
	int have;
	int max() {
		int max_ = 0;
		for (int i = 0; i < 26; i++)
			remax(max_, num[i]);
		return max_;
	}
	SAVE() {
		for (int i = 0; i < 28; i++)num[i] = 0;
	}
};
int n, m;
char date[310000];
vector<int>edge[310000];
SAVE save[310000];
int use[310000];
int inf_flag=0;
SAVE dfs(int i) {
	if (save[i].have == 1) {
		return save[i];
	}
	else {
		use[i] = 1;
		SAVE t=*new SAVE();
		t.have = 1;
		for (int o = 0; o < edge[i].size(); o++) {
			if (use[edge[i][o]] == 1) {
				inf_flag = 1;
				break;//如果有环,所有步骤全部终止,直接返回
			}
			SAVE t2 = dfs(edge[i][o]);
			for (int p = 0; p < 26; p++) {
				if (t2.num[p] > t.num[p])t.num[p] = t2.num[p];
			}
		}
		t.num[date[i] - 'a']++;
		save[i] = t;
		//save[i].have = 1;
		use[i] = 0;
		return t;
	}
	
}
int main() {
	scanf("%d %d", &n, &m);
	scanf("%s", &date[1]);
	range0(i, m) {
		int a, b;
		scanf("%d %d", &a, &b);
		edge[a].push_back(b);
	}
	int max_ = 0;
	for (int i = 1; i <= n; i++) {
		SAVE t=dfs(i);
		remax(max_, t.max());
		if (inf_flag == 1)break;
	}
	if (inf_flag == 1)printf("-1");
	else printf("%d", max_);
}