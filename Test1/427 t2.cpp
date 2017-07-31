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
int main() {
	int k = 0;
	scanf("%d", &k);
	char in[100010];
	scanf("%s", in);
	int len = strlen(in);
	int sum = 0;
	range0(i, len) {
		sum += (in[i]-'0');
	}
	sort(in,in+len);
	for (int i = 0; i < len; i++) {
		if (sum >= k) {
			printf("%d", i);
			return 0;
		}
		sum += ('9' - in[i]);
	}
	printf("%d", len);
	return 0;
}