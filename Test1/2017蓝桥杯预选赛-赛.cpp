#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<limits.h>
#include<time.h>
#include<iostream>
#include<functional>
#include<vector>
#include<queue>
#include<string.h>
//#include<windows.h>
#define range(i, s, e) for (int i = (s); i < int(e); i++)
#define range0(i, e) for (int i = 0; i < int(e); i++)
#define input_int(n) int n;scanf("%d",&n);
#define input_int2(n,m) int n;int m;scanf("%d %d",&n,&m);
#define remax(max_record,refresh_number) max_record=std::max(max_record,refresh_number)
#define remin(min_record,refresh_number) min_record=std::min(min_record,refresh_number)
#define INF 0x3f3f3f3f
#define INF2 INT_MAX
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
/*
http://bjutacm.openjudge.cn/lianxi/lq17D/
*/
ll s[100] = { 0,0,0,9,189,2889,38889,488889,5888889,68888889,788888889,8888888889,98888888889 };
//这代表了sum[1-9][1-99][1-999]......
//懒得直接计算了
ll pow_[100] = { 1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000 };
//一堆垃圾代码
char in[100];
int main() {
	memset(in, 0, sizeof(char) * 100);
	scanf("%s", in);
	ll sum = 0;
	int len = strlen(in);
	sum = s[len];
	sum += (in[0] - '0')*pow_[len - 2];
	if (in[1] == '0') {
		sum -= pow_[len - 2];
		int t = 0;
		for (int o = 2; o < len; o++) {
			t *= 10;
			t += in[o] - '0';
		}
		t++;
		//printf("t=%d\n", t);
		sum += t;
	}
	//处理该位为0时的情况
	//写完就再也看不懂了
	in[0]--;
	for (int i = 2; i < len; i++) {
		for (int o = 0; o < i; o++) {
			/*if (o != i - 1) {
				sum += (in[o] - '0')*pow_[len - o - 2];
			}
			else {
				sum += (in[o] - '0' + 1)*pow_[len - o - 2];
			}*/
			sum += (in[o] - '0')*pow_[len - o - 2];
			//这都什么玩意?!
		}
		sum += pow_[len - i - 1];
		if (in[i] == '0') {
			sum -= pow_[len - i - 1];
			int t = 0;
			for (int o = i + 1; o < len; o++) {
				t *= 10;
				t += in[o] - '0';
			}
			t++;
			sum += t;
		}
	}
	printf("%lld", sum);
}