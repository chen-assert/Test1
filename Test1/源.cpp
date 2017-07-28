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
typedef unsigned long long ull;
using namespace std;
bool goodletter[500];
char pattern[1000010];
int pattern_len;
int query_len;
char query[1000010];
int test() {
	int j, k;
	for (j = 0, k = 0; (j < pattern_len)&& (k<query_len);) {
		if (pattern[j] == '?') {
			if (goodletter[query[k]] == 1) {
				j++; k++;
				continue;
			}
			else {
				return -1;
			}
		}
		if (pattern[j] == '*') {
			for (int i = k; i <= query_len - (pattern_len - j); i++) {
				if (goodletter[query[i]] == 0)continue;
				else {
					return -1;
				}
			}
			j++;
			k += max((query_len - pattern_len + 1),0);
			continue;
		}
		if (pattern[j] == query[k]) {
			j++; k++;
			continue;
		}
		return -1;
	}
	if (j != pattern_len || k != query_len) {
		if (j == pattern_len - 1 && pattern[j] == '*')return 1;
		else return -1;
	}
	else return 1;
}
int main() {
	char temp = 0;
	while (1) {
		scanf("%c", &temp);
		if (temp == '\n')break;
		goodletter[temp] = 1;
	}
	scanf("%s", &pattern);
	pattern_len = strlen(pattern);

	input_int(n);
	range0(i, n) {
		scanf("%s", query);
		query_len = strlen(query);
		if (test() == 1)printf("YES\n");
		else printf("NO\n");
	}
	//getchar();
}