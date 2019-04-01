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
using namespace std;
int next_[1100000];
int _next[256];
int pattern_len;
char str[1100000];
void GetNext(char *start)
{
	int len = pattern_len;//get the length  

	for (int i = 0; i < 256; i++)
		_next[i] = -1;

	for (int i = 0; i < len; i++)
		_next[start[i]] = i;
}
int SundaySearch(char *dest, char *pattern, int len1, int len2)
{
	GetNext(pattern);

	int destLen = len1;
	int patternLen = len2;

	//if (destLen == 0) return 0;
	int sum = 0;
	for (int i = 0; i <= destLen - patternLen;)
	{
		int j = i;//dest[j]  
		int k = 0;//pattern[k]  

		for (; k < patternLen && j < destLen && dest[j] == pattern[k]; j++, k++)
			;//do nothing  

		if (k == patternLen)//great! find it!  
		{
			sum++;

		}
		if (i + patternLen < destLen)
			i += (patternLen - _next[dest[i + patternLen]]);
		else
			return sum;

	}
	return sum;
}
int strcmp_(char *a, char *b, int start, int len) {//返回已匹配个数
	range(i, start, len) {
		if (a[i] != b[i])return i;
	}
	return len;
}

// 构造 pattern 的最大匹配数表
void kmp_get_next(char *pattern) {
	//next[0]恒为-1 and next[1]表示第一个字符的匹配值
	memset(next_, 0, sizeof(int)*(pattern_len + 1));
	next_[0] = -1;
	int maxLength = 0;
	for (int i = 1; i < pattern_len; i++) {
		while (maxLength > 0 && pattern[maxLength] != pattern[i]) {
			maxLength = next_[maxLength - 1]; // ①
		}
		if (pattern[i] == pattern[maxLength]) {
			maxLength++; // ②
		}
		next_[i] = maxLength;
	}
}


int kmp(char *str, char *pattern, int strlen, int patternlen) {
	//pattern 是要匹配的字符串
	kmp_get_next(pattern);
	int sum = 0;//本次计算的模式匹配次数
	int t = 0;
	for (int b = 0; b < strlen - patternlen + 1;) {
		t = strcmp_(pattern, str + b, next_[t], patternlen);
		if (t == 0) {
			b++;
		}
		else {
			b += t - next_[t];
		}
		if (t == patternlen) {
			sum++;
		}
	}
	return sum;
}
void input() {
	scanf("%d\n", &pattern_len);
	range0(i, 1100000) {
		if (scanf("%c", str + i) == EOF)break;
	}
}
int main() {
	input();
	int strlen_ = (int)strlen(str);
	char *maxstr = str;
	int max = 0;
	for (int a = 0; a < strlen_ - pattern_len + 1; a++) {
		int sum = 0;
		char *pattern = str + a;
		sum = SundaySearch(str, pattern, strlen_, pattern_len);
		//sum = kmp(str, pattern, strlen_, pattern_len);
		if (sum > max) {
			max = sum;
			maxstr = pattern;
		}
	}
	range0(i, pattern_len) {
		printf("%c", *(maxstr + i));
	}
	printf(" %d", max);
}