#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#define test 0
#define reg register
using namespace std;
char in[4][30];//const
int carry[30];
int t[30];//transforem
		  //if t[n]==-1  it means ��n����(ת��ǰ)��δ��ת������
int o[30];//occupation
		  //��Щת��������ѱ�ռ��
int NN;
void dfs1(int n);
void dfs2(int n);
inline void input() {
	scanf("%d", &NN);
	for (int a = 1; a <= 3; a++) {
		scanf("%s", (in[a]) + 1);
	}
	for (int a = 1; a <= 3; a++) {
		for (int b = 1; b <= NN; b++) {
			in[a][b] = in[a][b] - 'A' + 1;
		}
	}
#if (test == 1)
	for (int a = 1; a <= 3; a++) {
		for (int b = 1; b <= NN; b++) {
			printf("%d ", in[a][b]);
		}
		printf("\n");
	}
#endif
}
void check(int n) {
	reg int t1 = 0;
	reg int t2 = t[in[1][n]] + t[in[2][n]] + carry[n];
	if (t2 >= NN) {//��λ
		t1 = 1;
		carry[n - 1] = 1;
		t2 -= NN;
	}
	if (t[in[3][n]] != -1) {
		if (t[in[3][n]] == t2) {//satisfy
			dfs1(n - 1);
			if (t1 == 1)carry[n - 1] = 0;
		}
		else {
			if (t1 == 1)carry[n - 1] = 0;
			return;
		}
	}
	else {
		if (o[t2] == 0) {//�ɽ�������
			o[t2] = 1;
			t[in[3][n]] = t2;
			dfs1(n - 1);
			o[t2] = 0;
			t[in[3][n]] = -1;
			if (t1 == 1)carry[n - 1] = 0;
		}
		else {
			if (t1 == 1)carry[n - 1] = 0;
			return;
		}
	}
}
void dfs2(int n) {
	if (t[in[2][n]] != -1) {
		check(n);
	}
	else {
		for (reg int b = NN - 1; b >= 0; b--) {
			if (o[b] == 0){
				o[b] = 1;
				t[in[2][n]] = b;
				check(n);
				o[b] = 0;
				t[in[2][n]] = -1;
			}
		}
	}
}
void dfs1(int n) {
	if (n == 0) {
		for (int a = 1; a < NN; a++) {
			printf("%d ", t[a]);
		}
		printf("%d\n", t[NN]);
		exit(0);
	}
	{
		//ÿ�����㵽һ��ʱ����鵱ǰ������Ƿ�����֪��(����������ȫ��֪��)������оͽ��м��
		//�����۽�λ�򲻽�λ�������㲻����ֱ�Ӵӵ�ǰ��return;
		//��ţ�� Ч������100+����
		for (int i = 1; i < n; i++) {
			if (t[in[1][i]] != -1 && t[in[2][i]] != -1 && t[in[3][i]] != -1) {
				int t1 = (t[in[1][i]] + t[in[2][i]]) % NN;
				int t2 = t[in[3][i]];
				if (t1 != t2 && t1+1 != t2 && t2!=0)return;
			}
		}
	}
	if (t[in[1][n]] != -1) {
		dfs2(n);
	}
	else {
		for (reg int a = NN - 1; a >= 0; a--) {
			if (o[a] == 0){
				o[a] = 1;
				t[in[1][n]] = a;
				dfs2(n);
				o[a] = 0;
				t[in[1][n]] = -1;
			}
		}
	}
}
int main() {
	for (int i = 0; i < 30; i++)t[i] = -1;
	input();
	dfs1(NN);
}