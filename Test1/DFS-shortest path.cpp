#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<string.h>
#include<limits.h>
int n, m, c1, c2;
int peonumber[520], pass[520];
int road[520][520];
int minlength=INT_MAX;
int maxpeople;
int snumber;
void dfs(int s, int people, int length) {
	if (length>minlength)return;
	if (s == c2) {
		if (length<minlength) {
			minlength = length;
			maxpeople = people;
			snumber = 1;
			return;
		}
		else {//length=minlength
			if (people > maxpeople)maxpeople = people;
			snumber++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (i == s)continue;
		if (road[s][i] == -1)continue;
		if (pass[i] == 1)continue;
		pass[i] = 1;
		dfs(i, people + peonumber[i], length + road[s][i]);
		pass[i] = 0;
	}
	return;
}
int main() {
	memset(road, -1, sizeof(int) * 520 * 520);
	//printf("%d",road[1][1]);
	scanf("%d %d %d %d", &n, &m, &c1, &c2);
	for (int i = 0; i<n; i++)scanf("%d", &peonumber[i]);
	for (int i = 0; i<m; i++) {
		int t1, t2,t3;
		scanf("%d %d %d", &t1, &t2,&t3);
		road[t1][t2] = road[t2][t1] = t3;
	}
	dfs(c1, peonumber[c1], 0);
	printf("%d %d", snumber, maxpeople);
}