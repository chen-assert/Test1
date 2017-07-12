#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<string.h>
#include<limits.h>
#include<algorithm>
using namespace std;
int n, m;
int node[510];
const int inf = INT_MAX;
struct EDGE {
	int a;
	int b;
	int cost;
	//int status;//if status == 1,it means cost=0
}edge[250010];
bool cmp(EDGE a, EDGE b) {
	return a.cost < b.cost;
}
void flashnode(int n1, int n2) {
	for (int i = 1; i <= n; i++) {
		if (node[i] == n2)node[i] = n1;
	}
}
void newnode() {
	for (int i = 1; i <= n; i++) {
		node[i] = i;
	}
}
int check(int x) {
	newnode();
	int sum = 0;
	int c = 1;
	for (int i = 0; i < m; i++) {
		if (edge[i].a == x || edge[i].b == x)continue;
		int n1 = node[edge[i].a];
		int n2 = node[edge[i].b];
		if (n1 != n2) {
			sum += edge[i].cost;
			c++;
			flashnode(n1, n2);
		}
		if (c == n-1)break;
	}
	if (c != n - 1)return inf;
	return sum;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int t3, t4;
		scanf("%d %d %d %d", &edge[i].a, &edge[i].b, &t3,&t4);
		if (t4 == 0) {//road is destroyed
			edge[i].cost = t3;
		}
		else {
			edge[i].cost = 0;
		}
	}
	sort(edge, edge + m,cmp);
	int price[510] = { 0 };
	for (int i = 1; i <= n; i++) {
		//printf("check %d=%d\n",i, check(i));
		price[i] = check(i);
	}
	int max = 0;
	for (int i = 1; i <=n ; i++) {
		if (price[i] > max)max = price[i];
	}
	if (max == 0) {
		printf("0");
		return 0;
	}
	int c = 0;
	for (int i = 1; i <= n; i++) {
		if (price[i] == max) {
			if (c == 0) {
				printf("%d", i);
				c = 1;
			}
			else {
				printf(" %d", i);
			}
		}
	}
}