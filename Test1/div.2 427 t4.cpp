#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<limits.h>
#include<queue>
#include<time.h>
#include<stack>
#include<map>
//#include"segment tree.h"
#define range(i, s, e) for (int i = s; i < int(e); i++)
#define range0(i, e) for (int i = 0; i < int(e); i++)
#define input_int(n) int n;scanf("%d",&n);
typedef long long ll;
int inf = 0x3f3f3f3f;
using namespace std;
char in[10000];
int save[5010][5010];//储存从a-b是几回文
int ans[5010];
bool cmpsave[5010][5010][2];
int strcmp_(int mid, int len_, int t) {//t为奇偶判断
	if (cmpsave[mid][len_ - 1][t] != 1)return 0;
	if (t == 1) {
		if (in[mid - len_] != in[mid + len_]) {
			cmpsave[mid][len_][t] = 0;
			return 0;
		}
		cmpsave[mid][len_][t] = 1;
		return 1;
	}
	else {
		if (in[mid +1- len_] != in[mid + len_]) {
			cmpsave[mid][len_][t] = 0;
			return 0;
		}
		cmpsave[mid][len_][t] = 1;
		return 1;
	}
	return 1;
}
int judge(int s, int e) {
	int len = e - s + 1;
	if (len == 1) {
		save[s][e] = 1;
		ans[1]++;
		return 0;
	}
	int t;
	if (len % 2 == 1) {
		t = 1;
	}
	else t = 0;
	int mid = (s + e) / 2;
	if (strcmp_(mid, len / 2, t) != 1)return 0;
	save[s][e] = save[mid + 1][e] + 1;
	ans[save[mid + 1][e] + 1]++;
	return 0;
}
void final_treat() {
	for (int a = 1; ans[a] != 0; a++) {
		for (int b = a + 1; ans[b] != 0; b++) {
			ans[a] += ans[b];
		}
	}
}//搞阿子搞
int main() {
	for (int i = 0; i <= 5000; i++) {
		cmpsave[i][0][0] = cmpsave[i][0][1] = 1;
	}
	scanf("%s", in);
	int len = strlen(in);
	int k = 1;
	for (int k = 1; k <= len; k++) {
		for (int a = 0; a + k - 1 < len; a++) {
			int b = a + k - 1;
			judge(a, b);
		}
	}
	final_treat();
	range(i, 1, len + 1)printf("%d ", ans[i]);
}