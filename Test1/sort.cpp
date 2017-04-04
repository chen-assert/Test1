#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
#include<math.h>
using namespace std;
//void bsort(int *N, int n) {
//    for (int x = 0; x<n - 1; x++) {
//        for (int y = n - 2; y >= x; y--) {
//            if (N[y + 1]<N[y])swap(N[y + 1], N[y]);
//        }
//    }
//}
void isort(int *N, int s, int e) {
	for (int i = s + 1; i <= e; i++) {
		int temp = i;
		while (temp != s) {
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
											//printf("%s = %d%s", "rand = ", r, " ");
	swap(N[s], N[r]);
	int b = N[s];
	int rs = e;//right search 
	int ls = s;//left search
	int k = s;
	while (1) {//base number place one time
		while (ls != rs&&N[rs] > b) {
			rs--;
		}
		if (ls == rs)break;
		N[k] = N[rs];
		k = rs;
		ls++;
		//if (ls == rs)break; //Commented BB
		while (ls != rs&&N[ls] < b) {
			ls++;
		}
		if (ls == rs)break;
		N[k] = N[ls];
		k = ls;
		rs--;
		//if (ls == rs)break; //Commented BB
	}
	N[ls] = b;
	if (ls == e) {
		qsort(N, s, ls - 1);
		return;
	}
	qsort(N, s, ls);
	qsort(N, ls + 1, e);
	return;
}
void mergearray(int *N, int s, int mid, int e, int *t) {
	int s1 = s;
	int s2 = mid + 1;
	int i = 0;
	while (i <= e - s) {
		if ((N[s1] <= N[s2] && s1<=mid)||s2>e) {
			t[i++] = N[s1++];
			
		}
		else {
			t[i++] = N[s2++];
			
		}
	}
	for (int i = 0; i <= (e - s); i++) {
		N[i + s] = t[i];
	}
	return;
}
void msort(int *N, int s, int e, int *t) {
	if (s < e) {
		int mid = (s + e) / 2;
		msort(N, s, mid, t);
		msort(N, mid + 1, e, t);
		mergearray(N, s, mid, e, t);
	}
}
int main() {
	srand((unsigned)time(NULL));
	int n;
	scanf("%d", &n);
	int *number = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &number[i]);
		//number[i] = 10;
	}
	//qsort(number, 0, n - 1);
	int *t = new int[n];
	if (t == NULL) {
		printf("new fail");
		return -1;
	}

	msort(number, 0, n - 1, t);
	for (int i = 0; i < n; i++) {
		printf("%d ", number[i]);
	}
	printf("\n");
}