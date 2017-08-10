#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<limits.h>
#include<queue>
#include<time.h>
#include<stack>
//#include<windows.h>
#define range(i, s, e) for (int i = s; i < int(e); i++)
#define range0(i, e) for (int i = 0; i < int(e); i++)
#define input_int(n) int n;scanf("%d",&n);
typedef unsigned long long ull;
using namespace std;
#define MAXLEN 1050000
#define multi 150
int finder_len,strlen_;
char str[MAXLEN];
ull t[MAXLEN] = { 1 };//t[n]==multi**n 
struct data {
	ull hash_val = 0;
	int num;
	friend bool operator<(data& d1, data& d2) {
		return d1.hash_val < d2.hash_val;
	}
}hash_table[MAXLEN];
void input() {
	scanf("%d\n", &finder_len);
	range0(i, MAXLEN) {
		if (scanf("%c", str + i) == EOF)break;
	}
	strlen_ = (int)strlen(str);
}
ull hash_(int x, int len) {
	int seed = multi;
	ull Hash = 0;
	range0(i, len) {
		Hash = Hash * seed + *(str+x+i);
	}
	return Hash;
}
ull hash_fast(int x, int len) {
	int seed = multi;
	ull Hash = hash_table[x - 1].hash_val;
	Hash -= t[len - 1] * (*(str + x -1));
	Hash = Hash * seed + *(str + x + len-1);
	return Hash;
}
int main() {
	input();
	for (int i = 1; i <= finder_len; i++) t[i] = t[i - 1] * multi;
	hash_table[0].num = 0;
	hash_table[0].hash_val = hash_(0, finder_len);
	for (int i = 1; i < strlen_ - finder_len + 1; i++) {
		hash_table[i].num = i;
		hash_table[i].hash_val = hash_fast(i, finder_len);
	}
	sort(hash_table, hash_table + strlen_-finder_len+1);
	int sum = 1;
	char *maxstr = str;
	int max = 1;
	range(i, 1, strlen_ - finder_len + 1) {
		if (hash_table[i].hash_val == hash_table[i - 1].hash_val) {
			sum++;
		}
		else {
			if (sum > max) {
				max = sum;
				maxstr = str + hash_table[i - 1].num;
			}
			sum = 1;
		}
	}
	if (sum > max) {
		max = sum;
		maxstr = str + hash_table[strlen_-finder_len - 1].num;
	}
	range0(i, finder_len) {
		printf("%c", *(maxstr + i));
	}
	printf(" %d", max);
}