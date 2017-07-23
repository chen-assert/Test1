#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<limits.h>
#include<queue>
#include<time.h>
#include<stack>
//#include<windows.h>
using namespace std;
bool used[20000];
struct edge {
	int to;
	int cap;
	int revnum;
};
vector<edge>node[20000];
int trans(char in[]) {
	return (in[0] - 'A') * 26 * 26 + (in[1] - 'A') * 26 + (in[2] - 'A');
}
void add_edge(int s, int e, int cap) {
	edge temp = { e,cap,(int)node[e].size() };
	node[s].push_back(temp);
	temp = { s,0,(int)node[s].size() - 1 };
	node[e].push_back(temp);
	return;
}
int dfs(int s, int e, int maxflow) {
	if (s == e)return maxflow;
	used[s] = 1;
	for (int i = 0; i < node[s].size(); i++) {
		edge &inode = node[s][i];
		if (used[inode.to] == 1)continue;
		if (inode.cap != 0) {
			int flow = dfs(inode.to, e, min(maxflow, inode.cap));
			if (flow == 0) {
				/*failed to find a route*/
				continue;
			}
			inode.cap -= flow;
			node[inode.to][inode.revnum].cap += flow;
			return flow;
		}
	}
	return 0;
}
int solve(int start, int end) {
	int max_flow = 0;
	while (1) {
		memset(used, 0, sizeof(used));
		int flow = dfs(start, end, 0x7f7f7f7f);
		if (flow == 0)break;
		max_flow += flow;
	}
	return max_flow;
}
int main() {
	char ss[5], ee[5];
	int n;
	scanf("%s %s %d", ss, ee, &n);
	int start = trans(ss);
	int end = trans(ee);
	int cap;
	for (int i = 0; i < n; i++) {
		scanf("%s %s %d", ss, ee, &cap);
		add_edge(trans(ss), trans(ee), cap);
	}
	printf("%d", solve(start, end));
}