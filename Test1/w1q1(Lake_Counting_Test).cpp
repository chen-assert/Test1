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
#define input_int2(n,m) int n;int m;scanf("%d %d",&n,&m);
#define INF 0x3f3f3f3f
#define INF2 INT_MAX
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
char data_[120][120];
bool save[120][120];
int xlen;
int ylen;
int bfs(int px,int py){
	stack<P>s;
	s.push(P(px, py));
	save[px][py] = 1;
	while (s.empty() != 1) {
		int x = s.top().first;
		int y = s.top().second;
		s.pop();
		for (int xx = x - 1; xx <= x + 1; xx++) {
			for (int yy = y - 1; yy <= y + 1; yy++) {
				if ((xx == x)&&(yy == y))continue;
				if (xx<1 || xx>xlen || yy<1 || yy>ylen) continue;
				if (data_[xx][yy] == 'W' && save[xx][yy]==false) {
					s.push(P(xx, yy));
					save[xx][yy] = 1;
				}
			}
		}
	}
	return 0;
}
int main() {
	scanf("N=%d, M=%d", &ylen, &xlen);
	for (int y = 1; y <= ylen; y++) {
		for (int x = 1; x <= xlen; x++) {
			scanf("%c", &data_[x][y]);
			while (data_[x][y] == ' '|| data_[x][y] == '\n') {
				scanf("%c", &data_[x][y]);
			}
		}
	}
	int num = 0;
	for (int x = 1; x <= xlen; x++) {
		for (int y = 1; y <= ylen; y++) {
			if (save[x][y] == 0 && data_[x][y]=='W') {
				num++;
				bfs(x, y);
			}
		}
	}
	printf("%d", num);
	}