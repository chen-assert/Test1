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
int strcmp_(int mid, int len_,int t) {//t为奇偶判断
	if (t == 1) {
		for (int i = 1; i <= len_; i++) {
			if (in[mid - i] != in[mid + i])return 0;
		}
	}
	else {
		for (int i = 1; i <= len_; i++) {
			if (in[mid + 1 - i] != in[mid + i])return 0;
		}
	}
	return 1;
}
int judge(int s,int e,int k) {
	int len = e - s + 1;
	int t;
	if (len % 2 == 1) {
		t = 1;
	}
	else t = 0;
	int mid = (s + e) / 2;
	if (strcmp_(mid, len / 2, t) == 0)return 0;
	if (t == 1) {
		if (save[s][mid - 1] >= k - 1 && save[mid + 1][e] >= k - 1)return 1;
	}
	else {
		if (save[s][mid] >= k - 1 && save[mid + 1][e] >= k - 1)return 1;
	}
	return 0;
}
int t[5000];
queue<int>s_;
queue<int>e_;
int main() {
	t[1] = 1;
	for (int i = 2; i <= 50; i++) {
		t[i] = 2 * t[i - 1];
	}
	scanf("%s", in);
	int len = strlen(in);
	char t = in[0];
	int tt = 0;
	range0(i,len) {
		if (in[i] != t)tt = 1;
	}
	if (tt = 1) {
		for (int k = 1; k <= 1; k++) {
			for (int a = 0; a < len; a++) {
				for (int b = a; b < len; b++) {
					if (save[a][b] < k - 1)continue;
					if (judge(a, b, k) == 1) {
						save[a][b] = k;
						s_.push(a);
						e_.push(b);
						ans[k]++;
					}
				}
			}
			if (ans[k] == 0)break;
		}
		int k = 1;
		while (s_.empty() != 1) {
			int t = s_.size();
			k++;
			range0(i, t) {
				int a = s_.front();
				int b = e_.front();
				s_.pop();
				e_.pop();
				if (judge(a, b, k) == 1) {
					save[a][b] = k;
					s_.push(a);
					e_.push(b);
					ans[k]++;
				}
			}
		}
		range(i, 1, len + 1)printf("%d ", ans[i]);
	}
	else {
		range(a,1,len+1){
			
		}
	}
}