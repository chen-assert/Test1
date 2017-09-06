#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<limits.h>
#include<queue>
#include<time.h>
#include<stack>
#include<map>
#include<iostream>
#include<string.h>
//#include"segment tree.h"
//#include<windows.h>
#define range(i, s, e) for (int i = (s); i < int(e); i++)
#define range0(i, e) for (int i = 0; i < int(e); i++)
#define input_int(n) int n;scanf("%d",&n);
#define INF 0x3f3f3f3f
typedef unsigned long long ull;
using namespace std;
struct TREE {
	int left;
	int right;
	int value;
};
int fro[300];//-1表示这里丢失了
int mid[300];
int beh[300];
int fro_missing_num2[300];
int mid_missing_num2[300];
int beh_missing_num2[300];
int n;
int res = 0;
int flag = 0;
int root;
TREE tree[300];
int get() {
	char t[20];
	scanf("%s", &t);
	if (t[0] == '-')return -1;
	int res = 0;
	for (int i = 0; t[i] != 0; i++) res = res * 10 + t[i] - '0';
	return res;
}
void data_input() {
	scanf("%d", &n);
	range0(i, n) {//in-order
		mid[i] = get();
		if (mid[i] != -1)mid_missing_num2[mid[i]] = 1;
	}
	range0(i, n) {//pre-order
		fro[i] = get();
		if (fro[i] != -1)fro_missing_num2[fro[i]] = 1;
	}
	range0(i, n) {//post-order
		beh[i] = get();
		if (beh[i] != -1)beh_missing_num2[beh[i]] = 1;
	}
}
void output(int root, int pattern) {
	//if (maintree->name == -1)maintree->name = res;
	if (root != -1) {
		if (pattern == 2) { printf("%s%d", flag ? " " : "", tree[root].value); flag = 1; }
		if (tree[root].left != -1)output(tree[root].left, pattern);
		if (pattern == 1) { printf("%s%d", flag ? " " : "", tree[root].value); flag = 1; }
		if (tree[root].right != -1)output(tree[root].right, pattern);
		if (pattern == 3) { printf("%s%d", flag ? " " : "", tree[root].value); flag = 1; }
	}
	return;
}
void level_order(int root) {
	queue<TREE*> q;
	q.push(&tree[root]);
	while (q.empty() != 1) {
		//if (q.front()->name == -1)q.front()->name = res;
		if (q.front()->value != -1) {
			printf("%s%d", flag ? " " : "", q.front()->value); flag = 1;
			if (q.front()->left != -1)q.push(&tree[q.front()->left]);
			if (q.front()->right != -1)q.push(&tree[q.front()->right]);
			q.pop();
		}
		else {
			q.pop();
		}
	}
}
int dfs(int prel, int prer, int inl, int inr, int postl, int postr, int *x) {
	if (prel > prer) {
		*x = -1;
		return 1;
	}
	for (int i = inl; i <= inr; i++) {
		if (fro[prel] != -1 && mid[i] != -1 && fro[prel] != mid[i])continue;
		if (beh[postr] != -1 && mid[i] != -1 && beh[postr] != mid[i])continue;
		if (fro[prel] != -1 && beh[postr] != -1 && fro[prel] != beh[postr])continue;
		tree[i].value = max(fro[prel], max(mid[i], beh[postr]));
		if (tree[i].value == -1) tree[i].value = res;
		*x = i;
		int leftlong = i - inl;
		int rightlong = inr - i;
		if (dfs(prel + 1, prel + leftlong, inl, i - 1, postl, postl + leftlong - 1, &(tree[*x].left)) == 0)continue;
		if (dfs(prel + leftlong + 1, prer, i + 1, inr, postl + leftlong, postr - 1, &(tree[*x].right)) == 0)continue;
		return 1;
	}
	return 0;
}
int ergodic2() {
	if (dfs(0, n - 1, 0, n - 1, 0, n - 1, &root) == 1) {
		return 1;
	}
	else {
		return 0;
	}
}
int main() {
	data_input();
	if (n == 0)return 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (mid_missing_num2[i] == 0 && fro_missing_num2[i] == 0 && beh_missing_num2[i] == 0) {
			cnt++;
			res = i;
		}
	}
	range0(i, n) {
		tree[i].value = mid[i];
		tree[i].left = -1;
		tree[i].right = -1;
	}
		if (cnt >= 2 || ergodic2() == 0) {
		printf("Impossible");
	}
	else {
		flag = 0; output(root, 1); putchar(10);
		flag = 0; output(root, 2); putchar(10);
		flag = 0; output(root, 3); putchar(10);
		flag = 0; level_order(root);
	}
	return 0;
}