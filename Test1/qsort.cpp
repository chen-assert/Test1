#include<stdio.h>www
#include<algorithm>
#include<stdlib.h>
#include<time.h>
using namespace std;
//void bsort(int *N, int n) {
//	for (int x = 0; x<n - 1; x++) {
//		for (int y = n - 2; y >= x; y--) {
//			if (N[y + 1]<N[y])swap(N[y + 1], N[y]);
//		}
//	}
//}
void isort(int *N, int s, int e) {
	for (int i = s + 1; i <= e; i++) {
		int temp = i;
		while (temp!=s) {
			if (N[temp] < N[temp - 1]) {
				swap(N[temp], N[temp - 1]);
			}
			else break;
			temp--;
		}
	}
	return;
}
void qsort(int *N, int s, int e) {//array,start,end
	if (s == e)return;
	if (e - s <= 15) {
		isort(N, s, e);
		return;
	}
	int r = (int)(rand() % (e + 1 - s)) + s;//random base point
	//printf("r=%d\n", r);
	//int r = s;//test
	swap(N[s], N[r]);
	int b = N[s];
	int rs = e;
	int ls = s;
	while (1) {//base number place one time
		while (1) {
			if (N[rs] < b)break;
			rs--;
			if (rs == ls)break;
		}
		if (rs == ls)break;
		if (N[ls] > b) {
			swap(N[ls], N[rs]);
			rs--;
		}
		else ls++;
		if (rs == ls)break;
	}
	swap(N[ls], N[s]);
	if (ls == e) {
		qsort(N, s, ls - 1);
		return;
	}
	qsort(N, s, ls);
	qsort(N, ls + 1, e);
	return;
}
int main() {
	srand((unsigned)time(NULL));
	int n;
	scanf("%d", &n);
	int *number = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i<n; i++) {
		scanf("%d", &number[i]);
		//number[i] = 10;
	}
	qsort(number, 0, n - 1);
	for (int i = 0; i<n; i++) {
		printf("%d ", number[i]);
	}
	printf("\n");
}