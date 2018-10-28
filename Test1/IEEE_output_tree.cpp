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
/*
HDBEAFCG
HDEBFGCA
EGCFABDH
*/
char pre[1000];
char mid[1000];
char beh[1000];
struct tree {
	tree *root;
	tree *left;
	tree *right;
	char name;
};
struct newtree {
	tree* tnode;
	int dep;
	int wid;
};
int maxdep;
vector<newtree>list[1000];
tree *generate(int start, int end, tree *root, int target) {
	if (start > end)return NULL;
	int local = 0;
	tree *main;
	main = (tree*)malloc(sizeof(tree));
	*main = { root, NULL,NULL,pre[target] };
	if (start == end)return main;
	for (int i = start; i <= end; i++) {
		if (mid[i] == pre[target]) {
			local = i;
			break;
		}
	}
	int q = local - start;
	int h = end - local;
	//printf("%d", local);
	main->left = generate(start, local - 1, main, target + 1);
	main->right = generate(local + 1, end, main, target + q + 1);
	return main;
}
int cal(tree *maintree, int wid, int dep) {
	if (maintree == NULL)return 0;
	if (dep > maxdep)maxdep = dep;
	int lwid = cal(maintree->left, wid, dep + 1);
	list[dep].push_back({ maintree,dep,wid+lwid});
	int rwid = cal(maintree->right, wid+lwid+1, dep + 1);
	return lwid + 1 + rwid;
}
char out[100000];
void output(tree *maintree) {
	cal(maintree, 0, 0);
	range0(i, maxdep+1) {
		memset(out, ' ', sizeof(char)*list[i][list[i].size()-1].wid);
		out[list[i][list[i].size() - 1].wid + 1] = 0;
		range0(o, list[i].size()) {
			out[list[i][o].wid] = list[i][o].tnode->name;
		}
		printf("%s\n", out);
	}
}
int main() {
	while (scanf("%s", &mid) != EOF) {
		scanf("%s", &pre);
		for (int i = 0; i < 1000; i++)list[i].clear();
		maxdep = 0;
		int start = 0;
		int end = strlen(mid) - 1;
		tree *maintree = generate(start, end, NULL, start);//Éú³É
		output(maintree);//Êä³öÊ÷
	}
}