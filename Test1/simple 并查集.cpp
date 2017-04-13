using namespace std;
#include<cstring>
//#include<vector>
#include<cstdio>
//#include<iostream>
#include<algorithm>

long long Q[150001];
int n, m;
int parent[150001];
int find(int i) {
	if (parent[i] == i)return i;
	else return parent[i]=find(parent[i]);
}
void merge(int a1,int a2) {
	//parent[a1]=find(a2);
	parent[a1] = parent[a2];
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	int a1, a2;
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &a1, &a2);
		merge(find(a1), find(a2));
	}
	for (int i = 1; i <= n; i++) {
		(Q[find(i)])++;
		//printf("%d--parent--%d\n", i, find(i));
	}
	long long s = 0;
	for (int i = 1; i <= n; i++) {
		//printf("%lld\n", Q[i]);
		s += (Q[i] * (Q[i] - 1)) / 2;
	}
	if (s == m)printf("YES");
	else printf("NO");
}