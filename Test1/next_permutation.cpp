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
int save[10010];
int n, m;
void increase() {
	int t = n;
	priority_queue<int, vector<int>, greater<int> > que_min;
	priority_queue<int, vector<int>, less<int> > que_max;
	que_min.push(save[n]);
	que_max.push(save[n]);
	t--;
	while (que_max.top()<save[t]) {
		que_max.push(save[t]);
		que_min.push(save[t]);
		t--;
	}
	que_min.push(save[t]);
	int max_ = que_max.top();
	que_max.pop();
	while (!que_max.empty()&&que_max.top() > save[t]) {
		max_ = que_max.top();
		que_max.pop();
		if (que_max.empty())break;
	}
	save[t] = max_;
	int tt = t;
	for (int i = tt + 1; i <= n; i++) {
		int o = que_min.top();
		que_min.pop();
		if (o == max_) {
			i--;
			continue;
		}
		else {
			save[++t] = o;
		}
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &save[i]);
	}

	for (int i = 1; i <= m; i++) {
		increase();
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", save[i]);
	}
}