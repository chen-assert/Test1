#include<stdio.h>
#include<stdlib.h> 
#include<algorithm>
#include<limits.h>
#include<time.h>
#include <math.h>  
#include<iostream>
#include<functional>
#include<fstream> 
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<string.h> 
#include<string> 
#include<map>
//#include"segment tree.h"
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
typedef pair<ll, ll> llP;
inline void read(int &x) {//only read int
	static char c;
	for (c = getchar(); !('0' <= c && c <= '9'); c = getchar());
	for (x = 0; '0' <= c && c <= '9'; x = x * 10 + c - 48, c = getchar());
}
int size_, p, s, l, k;
struct shortcut {
	P from;
	P to;
};
map<P, P>shortway;
P pos[12];
int remainpeo = 0;
int nextpeo = 0;
int step_(int player) {
	if (pos[player].second % 2 == 1) {
		pos[player].first++;
		if (pos[player].first == size_ + 1) {
			pos[player].second++;
			pos[player].first--;
		}
	}
	else {
		pos[player].first--;
		if (pos[player].first == 0) {
			pos[player].second++;
			pos[player].first++;
		}
	}
	if (pos[player].first == 1 && pos[player].second == size_ + 1) {
		return 1;
	}
	else {
		return 0;
	}
}
int next_(int player, int step) {
	if (remainpeo == 0)return 0;
	for (int i = 0; i < step;) {
		if (pos[player].second % 2 == 1) {
			int min_ = min(step - i,size_+1- pos[player].first);
			i += min_;
			pos[player].first += min_;
			if (pos[player].first == size_ + 1) {
				pos[player].second++;
				pos[player].first--;
			}
		}
		else {
			int min_ = min(step - i, pos[player].first-0);
			i += min_;
			pos[player].first -= min_;
			if (pos[player].first == 0) {
				pos[player].second++;
				pos[player].first++;
			}
		}
		if ((pos[player].first == 1 && pos[player].second == size_ + 1) || pos[player] == P(0, size_)) {
			return 1;
		}
	}
	/*for (int i = 0; i < step; i++) {
		if (i == step)break;
		if (step_(player) == 1) {
			return 1;
		}
	}*/
	while (shortway.find(pos[player]) != shortway.end()) {
		pos[player] = shortway.find(pos[player])->second;
		if ((pos[player].first == 1 && pos[player].second == size_ + 1) || pos[player] == P(0, size_)) {
			return 1;
		}
	}
	if ((pos[player].first == 1 && pos[player].second == size_ + 1) || pos[player] == P(0,size_)) {
		return 1;
	}
	else {
		return 0;
	}
}
int main() {
	range0(i, 10) {
		pos[i] = P(0, 1);
	}
	scanf("%d", &size_);
	scanf("%d", &p);
	remainpeo = p;
	scanf("%d", &s);
	int fx, fy, ax, ay;
	range0(i, s) {
		scanf("%d %d %d %d", &fx, &fy, &ax, &ay);
		shortway.insert(std::pair<P, P>(P(fx, fy), P(ax, ay)));
	}
	scanf("%d", &l);
	range0(i, l) {
		scanf("%d %d %d %d", &fx, &fy, &ax, &ay);
		shortway.insert(std::pair<P, P>(P(fx, fy), P(ax, ay)));
	}
	scanf("%d", &k);
	range0(i, k) {
		//if (remainpeo == 0)break;
		input_int2(t1, t2);
		if (next_(nextpeo, t1 + t2) == 1) {
			remainpeo--;
			printf("%d winner\n", p-remainpeo);
		}
		//printf("step-%d player-%d x-%d y-%d\n", i,nextpeo + 1,pos[nextpeo].first, pos[nextpeo].second);
		if (remainpeo == 0)break;
		nextpeo = (nextpeo + 1) % p;
		while (pos[nextpeo] == P(1, size_ + 1)) {
			nextpeo = (nextpeo + 1) % p;
		}
	}
	range0(i, p) {
		if (pos[i] != P(1, size_ + 1)) {
			printf("%d %d %d\n", i+1, pos[i].first, pos[i].second);
		}
	}
}