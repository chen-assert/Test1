#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<limits.h>
#include<time.h>
#include<iostream>
#include<functional>
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
inline void read(int &x) {//only read int
	static char c;
	for (c = getchar(); !('0' <= c&&c <= '9'); c = getchar());
	for (x = 0; '0' <= c&&c <= '9'; x = x * 10 + c - 48, c = getchar());
}
int *parent = NULL;
void init_union(int n) {
	if (parent != NULL) {
		delete[] parent;
		parent = NULL;
	}
	parent = new int[n + 1];
	for (int i = 0; i <= n + 1; i++) {
		parent[i] = i;
	}
}
int find(int i) {
	if (parent[i] == i)return i;
	else return parent[i] = find(parent[i]);
}
void merge(int a1, int a2) {
	//int b1 = find(a1);
	//int b2 = find(a2);
	//parent[b1]=parent[b2];
	parent[find(a1)] = parent[find(a2)];
}
/*int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	init_union(n);
	int z, x, y;
	for (int i = 1; i <= m; i++) {
		read(z); read(x); read(y);
		if (z == 1) {
			merge(x, y);
		}
		else {
			printf(find(x) == find(y) ? "Y\n" : "N\n");
		}
	}
}*/