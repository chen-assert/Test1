#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<limits.h>
#include<queue>
#include<time.h>
#include<stack>
#define range(i, s, e) for (int i = s; i < int(e); i++)
#define range0(i, e) for (int i = 0; i < int(e); i++)
#define input_int(n) int n;scanf("%d",&n);
//#include<windows.h>
using namespace std;
//need hash?
int next_[1100000];
int len;
char str[1100000];
int strcmp_(char *a, char *b, int start, int len) {
	range(i, start, len) {
		if (a[i] != b[i])return a[i] - b[i];
	}
	return 0;
}
void get_next(char *start) {
	//memset
	
	range0(a, len) {
		char *end = start +a;
		for (int b = a; b > 0; b--) {
			if (strcmp_(start, end - b+1, 0, b) == 0) {
				next_[a] = b;
				break;
			}
		}
	}
}
int main() {
	scanf("%d", &len);
	scanf("%s", str);
	get_next(str);
	range0(i, 7)printf("%d ", next_[i]);
}