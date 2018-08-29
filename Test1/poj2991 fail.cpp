#include<stdio.h>
#include<algorithm>
#include<limits.h>
#include<iostream>
//#include<functional>
#include<vector>
#include<queue>
#include<string.h>
#include<stack>
#include<math.h>
//#include<time.h>
//#include<regex>
//#include<windows.h>
const double PI = 3.14159265358979323846264338327950288;
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
inline void read(int &x) {//only read int
	static char c;
	for (c = getchar(); !('0' <= c && c <= '9'); c = getchar());
	for (x = 0; '0' <= c && c <= '9'; x = x * 10 + c - 48, c = getchar());
}
struct NODE {
	char mode;
	NODE* left;
	NODE* right;
};
void test() {
	printf("%lf", sin(30/180.0*PI));
	exit(0);
}
double ang[30010];			//第n个节点向右偏移的角度
double vx[30010], vy[30010];//假设首节点坐标为(0,0)时,该部分的向量和
double angc[30010];			//右儿子比左儿子向右偏移的角度
int len[10010];
void change(int num, int s, double ca, int l, int r) {
	if (s <= r && s >= l) {
		if (l == r)return;
		int chl = num * 2;
		int chr = num * 2 + 1;
		int mid = (l + r) / 2;
		change(chl, s, ca, l, mid);
		change(chr, s, ca, mid + 1, r);
		if (s<=mid)angc[num] += ca;
		double s = sin(angc[num]);
		double c = cos(angc[num]);
		vx[num] = vx[chl] + vx[chr] * c + vy[chr] * s;
		vy[num] = vy[chl] - vx[chr] * s + vy[chr] * c;
	}
}
void init(int num,int l,int r) {//节点编号  [l,r]区间
	angc[num] = 0;
	ang[num] = 0;
	vx[num] = 0; 
	//感觉这里有问题
	if (r == l) {
		vy[num] = len[l];
		return;
	}
	int mid = (l + r) / 2;
	init(num * 2, l, mid);
	init(num * 2 + 1, mid + 1, r);
	vy[num] = vy[num * 2] + vy[num * 2 + 1];
	return;
}
int n, c;
int save[20020];
void solve1() {

}
int main() {
	//solve1();
	while (scanf("%d %d", &n, &c) != EOF) {
		range0(i, n)read(len[i+1]);
		init(1, 1, n);
		range0(i, 2 * c)read(save[i]);
		range0(i, c) {
			//input_int2(s, a);
			double na = (180.0- save[i*2+1])/180.0*PI;
			double ca = na - ang[save[i * 2]];
			ang[save[i*2]] = na;
			change(1, save[i*2],ca,1,n);
			printf("%.2lf %.2lf\n",vx[1],vy[1]);
		}
		puts("");
		scanf(" ");
	}
}