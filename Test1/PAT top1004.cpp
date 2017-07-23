#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<limits.h>
#include<queue>
#include<time.h>
#include<stack>
#define range(i, s, n) for (int i = s; i < int(n); i++)
#define range0(i, n) for (int i = 0; i < int(n); i++)
#define input_int(n) int n;scanf("%d",&n);
//#include<windows.h>
using namespace std;
void tra(char *t, int *o) {
	for (char *i = t; *i != '\0'; i++) {
		if (*i <= '9' && *i >= '0') {
			o[*i - '0']++;
			continue;
		}
		if (*i <= 'z' && *i >= 'a') {
			o[*i - 'a' + 10]++;
			continue;
		}
		if (*i <= 'Z' && *i >= 'A') {
			o[*i - 'A' + 36]++;
			continue;
		}
	}
}
int n;
int min_ = 0x3f3f3f3f;
int need[100];
int have[120][100];
int dfs(int s) {
	range0(i, 62) {
		if (need[i] > 0)goto label1;
	}
	{
		int extra = 0;
		range0(i, 62)extra -= need[i];
		if (extra == 0) {
			printf("Yes 0");
			exit(0);
		}
		if (extra < min_)min_ = extra;
		return 0;
	}
label1:
	for (int i = s + 1; i < int(n); i++) {
		range0(b, 62) {
			if (need[b] > 0 && have[i][b] > 0) {
				range0(c, 62) {
					if (have[i][c] > 0)need[c] -= have[i][c];
				}
				dfs(i);
				range0(c, 62) {
					if (have[i][c] > 0)need[c] += have[i][c];
				}
				break;
			}
		}
	}
	return 0;
}
int main() {
	char t[1200];
	scanf("%s", t);
	tra(t, need);
	scanf("%d", &n);
	range0(i, n) {
		scanf("%s", t);
		tra(t, have[i]);
	}
	int nhave[100] = { 0 };
	int missing = 0;
	range0(i, n) {
		range0(b, 62) {
			nhave[b] += have[i][b];
		}
	}
	range0(i, 62) {
		missing += max(0, need[i] - nhave[i]);
	}
	if (missing != 0) {
		printf("No %d", missing);
		return 0;
	}
	dfs(-1);
	printf("Yes %d", min_);
}
