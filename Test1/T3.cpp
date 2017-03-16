#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
int S, T, N, Q;
int X, Y, Z;
void change(long long int *A) {//discard
	for (int i = X; i <= Y; i++) {
		A[i] += Z;
	}
}
long long int cal(long long int *A) {//only use 1 times//alreday finished
	long long int B = 0;
	for (int i = 1; i < N + 1; i++) {
		if (A[i - 1] < A[i])B = B - S*abs(A[i] - A[i - 1]);
		if (A[i - 1] > A[i])B = B + T*abs(A[i] - A[i - 1]);
		//printf("%lld\n",B); 
	}
	return B;
}
void caldiff(long long int *A, long long int *di) {//calculate difference
	for (int i = 0; i < N; i++) {
		di[i] = A[i + 1] - A[i];
	}
}
long long int cal4(long long int d) {
	long long int i = 0;
	if (d > 0) i = (-S*d);
	else i = (-T*d);//d<0
	//printf("i=%d\n", i);
	return i;
}
long long int cal3(long long int *di) {
	long long int t = 0, y = 0;//t-原改变 y-修改之后改变
	if (Z == 0) { return 0; }
	if (X == 0) {
		t += cal4(di[Y]);
		di[Y] -= Z;
		y += cal4(di[Y]);
		return (y - t);
	}//no use
	if (Y == N) {
		t += cal4(di[X - 1]);
		di[X - 1] += Z;
		y += cal4(di[X - 1]);
		return (y - t);
	}
	t += cal4(di[Y]);
	t += cal4(di[X - 1]);
	di[Y] -= Z;
	di[X - 1] += Z;
	y += cal4(di[Y]);
	y += cal4(di[X - 1]);
	return (y - t);
}
int main() {
	long long int  B = 0, P = 0;
	long long int *A = (long long int*)malloc(sizeof(long long int) * 210000);
	long long int *di = (long long int*)malloc(sizeof(long long int) * 210000);//di[i]means the diffience between A[i+1] to A[i]
	long long int *p = (long long int*)malloc(sizeof(long long int) * 210000);
	scanf("%d %d %d %d", &N, &Q, &S, &T);
	for (int i = 0; i <= N; i++) {
		scanf("%lld", &A[i]);
	}
	caldiff(A, di);
	B = cal(A);
	for (int i = 0; i < Q; i++) {
		scanf("%d %d %d", &X, &Y, &Z);
		if (X > Y)swap(X, Y);
		if (X > N )continue;
		if (Y > N)Y = N;
		P = cal3(di);
		B += P;
		//printf("P=%lld\n", P);
		//printf("%lld\n", B);
		p[i] = B;
	}
	for (int i = 0; i < Q; i++) {
		printf("%lld\n", p[i]);
	}
	free(A);
	free(di);
	free(p);
}