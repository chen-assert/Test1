#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<limits.h>
#include<queue>
#include<time.h>
#include<stack>
//#include<windows.h>
#define range(i, s, e) for (int i = s; i < int(e); i++)
#define range0(i, e) for (int i = 0; i < int(e); i++)
#define input_int(n) int n;scanf("%d",&n);
#define INF 0x3f3f3f3f
typedef unsigned long long ull;
using namespace std;
vector<int>con[110000];
int walked[3][110000];
int step[3][110000];
int dfs(int a, int b, int sign) {
	if (walked[sign][a] == 1)return INF;
	//if (a == b) return 1;
	if (step[sign][a] != INF)return step[sign][a];
	walked[sign][a] = 1;
	int min_ = INF;
	range0(i, con[a].size()) {
		min_ = min(min_, dfs(con[a][i], b, sign)+1 );
	}
	step[sign][a] = min_;
	walked[sign][a] = 0;
	return min_;
}
void find(int a,int b,int sign ) {
	int pos = a;
	while (pos != b) {
		walked[sign][pos] = -1;
		int j = 0;
		range0(i, con[pos].size()) {
			if (step[sign][con[pos][i]] == step[sign][pos] - 1) {
				j = 1;
				pos = con[pos][i];
			}
			if (j == 1)break;
		}
		if (j == 0) {
			printf("ERROR!");
		}
		}
	walked[sign][b] = -1;
	return;
}
int search(int a, int b, int n) {
	int ans = 0;
	range(i, 1, n + 1) {
		if (walked[a][i] == -1 && walked[b][i] == -1)ans++;
	}
	return ans;
}
int main() {
	input_int(n);
	input_int(q);
	for (int i = 2; i <= n; i++) {
		int t;
		scanf("%d", &t);
		con[i].push_back(t);
		con[t].push_back(i);
	}
	range0(i, q) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		int ans[3] = { 0,0,0 };
		memset(walked, 0, sizeof(int) * 110000 * 3);
		memset(step, 0x3f, sizeof(int) * 110000 * 3);
		step[0][b] = 1;
		dfs(a, b, 0);
		find(a, b,0);
		step[1][c] = 1;
		dfs(b, c, 1);
		find(b, c,1);
		step[2][c] = 1;
		dfs(a, c, 2);
		find(a, c,2);
		ans[0] = search(0, 1, n);
		ans[1] = search(1, 2, n);
		ans[2] = search(0, 2, n);
		sort(ans, ans + 3);
		printf("%d\n", ans[2]);
	}
}