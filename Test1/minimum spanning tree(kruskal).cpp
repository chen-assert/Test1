#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<string.h>
#include<limits.h>
#include<algorithm>
using namespace std;
int node[5010];
int n, m;
struct EDGE{
	int a;
	int b;
	int l;
}edge[200010];
bool cmp(EDGE a, EDGE b) {
	return a.l < b.l;
}
inline void flashnode(int n1, int n2) {
	for (int i = 1; i <= n; i++) {
		if (node[i] == n2)node[i] = n1;
	}
}
int *parent = NULL;
void init_union(int n) {
	if (parent != NULL) {
		delete[] parent;
		parent = NULL;
	}
	parent = new int[n + 1];
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
}
int find_(int i) {
	if (parent[i] == i)return i;
	else return parent[i] = find_(parent[i]);
}
void merge(int a1, int a2) {
	parent[find_(a1)] = parent[find_(a2)];
}

int main() {
	parent = NULL;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &edge[i].a, &edge[i].b, &edge[i].l);
	}
	sort(edge, edge + m, cmp);
	for (int i = 1; i <= n; i++)node[i] = i;
	int sum = 0;
	int c = 1;
	init_union(n);
	for (int i = 0; i < m; i++) {
		//int n1 = node[edge[i].a];
		//int n2 = node[edge[i].b];
		int n1 = find_(edge[i].a);
		int n2 = find_(edge[i].b);
		if (n1 != n2) {
			sum += edge[i].l;
			c++;
			//flashnode(n1, n2);//can be rewrite by union find
			merge(n1, n2);
		}
		if (c == n)break;
	}
	printf("%d", sum);
}