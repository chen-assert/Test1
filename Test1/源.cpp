#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<iostream>
#include<vector>
struct qs {
	int time;
	int pass;
};
struct ans {
	int ques;
	int stime;
};
using namespace std;
int main() {
	int T;
	scanf("%d", &T);
	for (int x = 0; x < T; x++) {
		int m, n, q;
		scanf("%d %d %d", &n, &m, &q);
		qs **people = (qs**)malloc((n + 1) * sizeof(qs*));
		for (int i = 0; i <= n; i++) {
			people[i] = (qs*)malloc((m + 1) * sizeof(qs));
			for (int o = 0; o <= m; o++)people[i][o] = { 0,0 };
		}
		for (int y = 0; y < q; y++) {
			int p, t, r, s;
			scanf("%d %d %d %d", &p, &t, &r, &s);
			if (people[p][r].pass == 1)continue;
			if (s == 0) people[p][r].time += 20;
			if (s == 1) {
				people[p][r].time += t;
				people[p][r].pass = 1;
			}
		}
		ans *peoans = (ans*)malloc((n + 1) * sizeof(ans));
		for (int i = 0; i <= n; i++)peoans[i] = { 0,0 };
		for (int i = 1; i <= n; i++) {
			for (int o = 1; o <= m; o++) {
				if (people[i][o].pass == 1) {
					peoans[i].ques += 1;
					peoans[i].stime += people[i][o].time;
				}
			}
		}
		int rank = 1;
		for (int i = 2; i <= n; i++) {
			if (peoans[i].ques == peoans[1].ques) {
				if (peoans[i].stime < peoans[1].stime) {
					rank++;
				}
			}
			if (peoans[i].ques > peoans[1].ques) {
				rank++;
			}
		}
		printf("%d %d %d\n", rank,peoans[1].ques,peoans[1].stime);
		free(peoans);
		for (int i = 0; i <= n; i++) free(people[i]);
		free(people);
	}
}