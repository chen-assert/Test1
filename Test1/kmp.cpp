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
#include<functional>
//#include"segment tree.h"
//#include<windows.h>
#define range(i, s, e) for (int i = (s); i < int(e); i++)
#define range0(i, e) for (int i = 0; i < int(e); i++)
#define input_int(n) int n;scanf("%d",&n);
#define INF 0x3f3f3f3f
#define INF2 2147483647
typedef unsigned long long ull;
using namespace std;
char s1[(int)1e6 + 10], s2[(int)1e6 + 10];
ull hashs1[1000010];//下标表示最右侧位置
ull hashs2[1000010];//下标表示后缀数组长度
int main() {
	input_int(n);
	range0(q, n) {
		scanf("%s %s", s1, s2);
		int sum = 0;
		int lens1 = strlen(s1);
		int lens2 = strlen(s2);
		int len = min(strlen(s1), strlen(s2));
		for (int long_ = 1; long_ <= lens2; long_++) {
			hashs2[long_] = hashs2[long_ - 1] * 131 + s2[lens2-long_];
		}
		for (int long_ = 1; long_<=len; long_++) {
			for (int start = lens1 - 1; start >= long_-1; start--) {//当long_==1时遍历到首端
				hashs1[start] = hashs1[start] * 131 + s1[start - long_ + 1];
				if (hashs1[start] == hashs2[long_]) {
					sum += long_;
					sum %= (unsigned int)1e9 + 7;
				}
			}
		}
		printf("%d\n", sum);
		memset(hashs1, 0, sizeof(ull)*(lens1+5));
		memset(hashs2, 0, sizeof(ull)*(lens2+5));
	}
}