#include<stdio.h>
#include<stdlib.h> 
#include<algorithm>
#include<limits.h>
#include<time.h>
#include<math.h>  
#include<iostream>
#include<fstream> 
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<string> 
#include<map>
#include<regex>
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
struct PRO {
	int arr;
	int bur;
	int bur2;
	int num;
	int end;
	int rest = 0;
}pro[5];
struct cmp {

};
int type = 0;
int main() {
	printf("1.FIFS\n2.TIME ROBIN\n3.\n");
	scanf("%d", &type);
	switch (type) {
	case 1: {
		range0(i, 5) {
			scanf("%d", &pro[i].arr);
			pro[i].num = i;
		}
		range0(i, 5) {
			scanf("%d", &pro[i].bur);
		}

		int flag = 0;
		int nt = 0;
		queue<int> sta;
		int us = 0;
		while (1) {
			if (flag == 5)break;
			range0(i, 5) {
				if (nt >= pro[i].arr&&pro[i].rest == 0) {
					sta.push(i);
					pro[i].rest = 1;
				}
			}
			if (us == 0 && !sta.empty()) {
				int t = sta.front();
				sta.pop();
				us = pro[t].bur;
				pro[t].end = nt + pro[t].bur;
				flag++;
			}
			if (us > 0)us--;
			nt++;
		}
		break;
	}
	case 2: {
		input_int(slice);
		range0(i, 5) {
			scanf("%d", &pro[i].bur);
			pro[i].bur2 = pro[i].bur;
		}

		int flag = 0;
		int nt = 0;
		for (int i = 0;; i = (i + 1) % 5) {
			if (flag == 5)break;
			if (pro[i].rest == 0) {
				int t = min(pro[i].bur2, slice);
				pro[i].bur2 -= t;
				nt += t;
				if (pro[i].bur2 == 0) {
					pro[i].rest = 1;
					flag++;
					pro[i].end = nt;
				}
			}
		}
		break;
	}
	case 3: {
		range0(i, 5) {
			scanf("%d", &pro[i].arr);
			pro[i].num = i;
		}
		range0(i, 5) {
			scanf("%d", &pro[i].bur);
		}

	}
	}


	double avg = 0;
	range0(i, 5) {
		avg += (double)(pro[i].end - pro[i].arr - pro[i].bur) / 5;
		printf("%d ", pro[i].end - pro[i].arr - pro[i].bur);
	}
	printf("%lf", avg);
	getchar();
}