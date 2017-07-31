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
struct star {
	int si;
};
int n, q, c;
int output[110][110][12];//x,y,t
int main() {
	scanf("%d %d %d", &n, &q, &c);
	c = c + 1;
	vector <int> star[110][110];//si
	range0(i, n) {
		int xi, yi, si;
		scanf("%d %d %d", &xi, &yi, &si);
		star[xi][yi].push_back(si);
	}
	
	range(a, 1, 101) {
		range(b, 1, 101) {
			size_t len = star[a][b].size();
			for (int t = 0; t<c; t++) {
				int sum = 0;
				for (size_t i = 0; i < len; i++) {
					sum += (star[a][b][i] + t) % c ;
				}
				output[a][b][t] = sum;
			}
		}
	}
	range0(i, q) {
		int ti,x1i,y1i,x2i,y2i;
		scanf("%d %d %d %d %d", &ti, &x1i, &y1i, &x2i, &y2i);
		int sum = 0;
		//int do_[12];
		//memset(&do_, 0, sizeof(int) * 12);
		range(a, x1i, x2i + 1) {
			range(b, y1i, y2i + 1) {
				sum += output[a][b][ti%c];
			}
		}
		printf("%d\n", sum);
	}
}