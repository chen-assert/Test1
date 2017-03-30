#include<stdio.h>
#include<algorithm>
using namespace std;
void print_arr(int *p, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", p[i]);
	}
	printf("\n");
}
void fill_arr(int *p,int start,int size) {
	int i = start;
	for ( ; i < size; i++) {
		p[i] = start;
		start++;
	}
}
int main() {
	int *a = (int*)malloc(sizeof(int) * 5);
	if (a == NULL) {
		printf("your malloc is not succeed!");
		return 0;
	}
	fill_arr(a, 0, 5);
	print_arr(a, 5);
	a = (int*)realloc(a,sizeof(int) * 10);
	if (a == NULL) {
		printf("your realloc is not succeed!");
		return 0;
	}
	fill_arr(a, 5, 10);
	print_arr(a, 10);
	free(a);
	return 0;
}