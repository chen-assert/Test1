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
int n, m;
vector<int>list[100010];
struct NODE {
	int parent;
	int pre_num;
	int sum = 0;
	int sig = 0;
	vector<int>child;
}node[100010];
map<int, int> mm;
int cot = 0;
int build_tree(int pos, int from, int prefrom) {
	int pos2 = cot++;
	node[pos2].parent = from;
	node[pos2].pre_num = pos;
	node[pos2].sum = 0;
	mm.insert(pair<int, int>(pos, pos2));
	for (int i = 0; i < list[pos].size(); i++) {
		if (list[pos][i] == prefrom)continue;
		int t = build_tree(list[pos][i], pos2, pos);
		node[pos2].child.push_back(t);
	}
	return pos2;
}
int cot2 = 1;
void step(int from, int to, int add) {
	int pos = from;
	while (pos != 0) {
		node[pos].sum += add;
		node[pos].sig = cot2;
		pos = node[pos].parent;
	}
	node[pos].sum += add;
	node[pos].sig = cot2;
	int flag = 0;
	pos = to;
	while (pos != 0) {
		if (node[pos].sig == cot2) {
			flag++;
		}
		if (flag > 1) {
			node[pos].sum -= add;
		}
		else if (flag == 1) {
			//
		}
		else {
			node[pos].sum += add;
		}
		pos = node[pos].parent;
	}
	if (node[pos].sig == cot2) {
		flag++;
	}
	if (flag > 1) {
		node[pos].sum -= add;
	}
	else if (flag == 1) {
		//
	}
	else {
		node[pos].sum += add;
	}
	cot2++;
}
int find_max(int from) {
	int max_ = node[from].sum;
	for (int i = 0; i < node[from].child.size(); i++) {
		int t = find_max(node[from].child[i]);
		if (t > max_)max_ = t;
	}
	return max_;
}
int main() {
	scanf("%d %d", &n, &m);
	int t1, t2, t3;
	range0(i, n - 1) {
		scanf("%d %d", &t1, &t2);
		list[t1].push_back(t2);
		list[t2].push_back(t1);
	}
	build_tree(0, -1, -1);
	range0(i, m) {
		scanf("%d %d %d", &t1, &t2, &t3);
		step(mm[t1], mm[t2], t3);
	}
	printf("%d", find_max(0));
}