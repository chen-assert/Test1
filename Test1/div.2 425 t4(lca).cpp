#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<limits.h>
#include<queue>
#include<time.h>
#include<stack>
#include<map>
#include<cctype>
//#include"segment tree.h"
//#include<windows.h>
#define range(i, s, e) for (int i = s; i < int(e); i++)
#define range0(i, e) for (int i = 0; i < int(e); i++)
#define input_int(n) int n;scanf("%d",&n);
#define INF 0x3f3f3f3f
typedef unsigned long long ull;
using namespace std;
int parent[500010];
int visited[500010];
int head[500010];
int qhead[500010];
int ans[500010];
int rank_[500010];
struct NODE {
	int to;
	int last;
}node[1000010];
struct QUERY {
	int to;			//to ��ʾ·��/ѯ��ָ��
	int last;		//last �γ�������
}search_[1000010];
int find(int i) {
	if (parent[i] == i)return i;
	else return parent[i] = find(parent[i]);
}
void merge(int a1, int a2) {
	parent[a1] = parent[a2];
}
void add(int a, int b, int t) {//��ӵ�·��Ϣ
	node[t].last = head[a];
	node[t].to = b;
	head[a] = t;
}
void qadd(int a, int b, int t) {//���ѯ����Ϣ
	search_[t].last = qhead[a];
	search_[t].to = b;
	qhead[a] = t;
}
void tarjan(int u, NODE *node, QUERY *search, int from) {
	//merge��findΪ���鼯�ϲ������Ͳ��Һ��� 
	for (int v = head[u]; v != 0; v = node[v].last) {	                //��������u�ӽڵ�v
		if (node[v].to == from)continue;
		tarjan(node[v].to, node, search, u);                    //�������±���
		merge(node[v].to, u);                                //�ϲ�v��u��
		visited[node[v].to] = 1;                        //���v�ѱ����ʹ�
	}
	for (int e = qhead[u]; e != 0; e = search_[e].last) {				//�������к�u��ѯ�ʹ�ϵ��e
		if (visited[search_[e].to] == 1) {
			//ans[e / 2] = find(search_[e].to);		//u, e�������������Ϊfind(e);
			ans[e / 2] = abs(rank_[find(search_[e].to)] - rank_[u]) + abs(rank_[find(search_[e].to)] - rank_[search_[e].to]);
		}
	}
}
void find_rank(int u, int from, int now_rank) {//Ԥ��ѯ���ڵ�rank
	rank_[u] = now_rank;
	for (int v = head[u]; v != 0; v = node[v].last) {
		if (node[v].to == from)continue;
		find_rank(node[v].to, u, now_rank + 1);
	}
}
int main() {
	input_int(n);
	input_int(q);
	for (int i = 1; i <= n; i++)parent[i] = i;
	for (int i = 2; i <= n; i++) {
		int t;
		scanf("%d", &t);
		add(t, i, i * 2);
		add(i, t, i * 2 + 1);
	}
	find_rank(1, 1, 1);
	range0(i, q) {
		input_int(a);
		input_int(b);
		input_int(c);
		qadd(a, b, i * 6 + 6);
		qadd(b, a, i * 6 + 1 + 6);
		qadd(a, c, i * 6 + 2 + 6);
		qadd(c, a, i * 6 + 3 + 6);
		qadd(b, c, i * 6 + 4 + 6);
		qadd(c, b, i * 6 + 5 + 6);
		//get ans[3*i+3]\[3*i+4]\[3*i+5]
	}
	tarjan(1, node, search_, 1);
	range0(i, q) {
		sort(&ans[3 * i + 3], &ans[3 * i + 6]);
		//printf("%d-%d-%d\n", ans[3 * i + 3], ans[3 * i + 4], ans[3 * i + 5]);
		int dif = ans[3 * i + 5] - ans[3 * i + 4];
		int t = ans[3 * i + 3] + dif;
		t /= 2;
		int a = ans[3 * i + 5] - t;
		printf("%d\n", a+1);
	}
}