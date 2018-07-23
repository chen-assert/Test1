#include<stdio.h>
#include<algorithm>
#include<limits.h>
#include<time.h>
#include<iostream>
#include<functional>
#include<vector>
#include<queue>
#include<string.h>
#include<stack>
#include<string>
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
struct str
{
	int sum;
	int seq;
	int n;
};
int main() {
	vector<str> vec;
	input_int(k);
	range0(i, k) {
		int t[200010];
		input_int(n);
		int sum = 0;
		range0(o, n) {
			scanf("%d", &t[o]);
			sum += t[o];
		}
		range0(o, n) {
			vec.push_back({ sum-t[o], i, o });
		}
	}
	sort(vec.begin(), vec.end(), [&](const str &a, const str &b) {
		return a.sum < b.sum; }
	);
	int len = vec.size();
	for (int i = 0; i < len-1; i++) {
		if (vec[i].sum == vec[i + 1].sum) {
			if (vec[i].seq == vec[i + 1].seq) {
				continue;
			}
			printf("YES\n");
			printf("%d %d\n%d %d", vec[i].seq+1, vec[i].n+1, vec[i+1].seq+1, vec[i+1].n+1);
			return 0;
		}
	}
	printf("NO");
}