#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<math.h>
#include<time.h>
#include<vector>
#include<string.h>
#include<stack>
inline int max_(int a, int b) {
	if (a > b)return a;
	return b;
}
inline int min_(int a, int b) {
	if (a < b)return a;
	return b;
}
using namespace std;
int n;
struct PROJECT {
	int profit;
	int time;
	int deadline;
	int latest_start_day;
};
int maxvalue;
PROJECT project[80];
bool cmp(PROJECT a, PROJECT b) {
	return a.latest_start_day < b.latest_start_day;
}
int flag[80];
int dfs(int day, int value, int projectnum,int magicflag) {
	register int magic = 0;
	register int i;
	if(magicflag==0)i = max_(projectnum - 2, 0);
	else i = projectnum+1;
	for (; i < min_(n,projectnum+10); i++) {//guess
		if (flag[i] == 1)continue;
		//if (magic == 6)break;
		if (project[i].latest_start_day >= day) {
			flag[i] = 1;
			if(i<projectnum)dfs(day + project[i].time, value + project[i].profit, i,1);
			else dfs(day + project[i].time, value + project[i].profit, i, 0);
			flag[i] = 0;
			magic++;
		}
		else {
			continue;
		}
	}
	if (value > maxvalue)maxvalue = value;
	return 0;
}
int dfs2(int day, int value) {
	for (int i = 0; i < n; i++) {
		if (flag[i] == 1)continue;
		if (project[i].latest_start_day >= day) {
			flag[i] = 1;
			dfs2(day + project[i].time, value + project[i].profit);
			flag[i] = 0;
		}
		else {
			continue;
		}
	}
	if (value > maxvalue)maxvalue = value;
	return 0;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &project[i].profit, &project[i].time, &project[i].deadline);
		project[i].latest_start_day = project[i].deadline - project[i].time;
	}
	sort(project, project + n, cmp);
	dfs(0, 0, -1,0);
	//dfs2(0, 0);
	printf("%d", maxvalue);
}