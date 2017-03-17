#include<stdio.h>
#include<string.h>
int a = 0;
char c(char w) {
	int q = w;
	q = q + a;
	if (q > 'z')q -= 26;
	w = q;
	return w;
}
int main() {
	
	scanf("%d", &a);
	a = a % 26;
	char q[10000] = { 0 };
	int p = 0;
	//getchar();//Ïû³ý/n
	scanf("%s", q);
	p = strlen(q);
	for (int i = 0; i < p; i++) {
		q[i] = c(q[i]);
	}
	printf("%s", q);
}