#include<stdio.h>
#include <stdlib.h> 
#include<algorithm>
#include<limits.h>
#include<time.h>
#include<iostream>
#include<functional>
#include <fstream> 
#include<vector>
#include<queue>
#include<string.h>
#include<stack>
#include <set>
//#include"segment tree.h"
//#include<regex>
//#include<windows.h>
using namespace std;
#define range(i, s, e) for (int i = (s); i < int(e); i++)
#define range0(i, e) for (int i = 0; i < int(e); i++)
#define input_int(n) int n;scanf("%d",&n);
#define input_int2(n,m) int n;int m;scanf("%d %d",&n,&m);
#define remax(max_record,refresh_number) max_record=std::max(max_record,refresh_number)
#define remin(min_record,refresh_number) min_record=std::min(min_record,refresh_number)
#define INF 0x3f3f3f3f
#define INF2 INT_MAX
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef pair<ll, ll> llP;
inline void read(int &x) {//only read int
	static char c;
	for (c = getchar(); !('0' <= c && c <= '9'); c = getchar());
	for (x = 0; '0' <= c && c <= '9'; x = x * 10 + c - 48, c = getchar());
}
int BigRand()
{
	return RAND_MAX * rand() + rand();
}
bool is_hex(char a) {
	return ('a' <= a && a <= 'f') || ('A' <= a && a <= 'F') || ('0' <= a && a <= '9');
}
bool is_tag_char(char a) {
	return ('a' <= a && a <= 'z') || ('0' <= a && a <= '9');
}
bool is_char(char a) {
	return (32 <= a && a <= 127);
}
char in[25600];
stack<string> tag;
#define END {state = 255;valid=false;break;}
int main() {
	while (cin.getline(in, 25600)) {
		int len = strlen(in);
		bool valid = true;
		int i = 0;
		int state = 0;
		int flag = 0;
		while (i < len) {
			if (state == 255)break;
			switch (state) {
			case 0:
				if (in[i] == '>') {
					END;
				}
				if (in[i] == '&') {
					state = 1;
					i++;
					continue;
				}
				if (in[i] == '<') {
					state = 4;
					i++;
					continue;
				}
				if (is_char(in[i])) {
					state = 0;
					i++;
					continue;
				}
				END;
				break;
			case 1:
				if (in[i] == 'x') {
					state = 2;
					i++;
					continue;
				}
				flag = 0;
				if (in[i] == 'a'&&in[i + 1] == 'm'&&in[i + 2] == 'p'&&in[i + 3] == ';') {
					flag = 1;
					i += 4;
				}
				if (in[i] == 'l'&&in[i + 1] == 't'&&in[i + 2] == ';') {
					flag = 1;
					i += 3;
				}
				if (in[i] == 'g'&&in[i + 1] == 't'&&in[i + 2] == ';') {
					flag = 1;
					i += 3;
				}
				if (flag == 1) {
					state = 0;
					continue;
				}
				else {
					END;
				}
				break;
			case 2:
				if (is_hex(in[i]) && is_hex(in[i + 1])) {
					i += 2;
					state = 3;
					continue;
				}
				else {
					END;
				}
				break;
			case 3:
				if (in[i] == ';') {
					i++;
					state = 0;
					continue;
				}
				if (is_hex(in[i]) && is_hex(in[i + 1])) {
					i += 2;
					state = 3;
					continue;
				}
				else {
					END;
				}
				break;
			case 4:
				if (in[i] == '/'&&in[i + 1] == '>') {
					state = 0;
					i += 2;
					continue;
				}
				state = 10;
				continue;
				break;
			case 10:
				int np = i;
				int pop = 0;
				if (in[i] == '/') {
					if (tag.empty())
					{
						END;
					}
					else {
						pop = 1;
						np++;
						i++;
					}
				}
				while (1) {
					if (i >= len) {
						state = 255;
						valid = false;
						break;
					}
					if (in[i] == '/'&&in[i + 1] == '>'&&pop == 0) {
						i += 2;
						state = 0;
						break;
					}
					if (in[i] == '>') {
						if (pop == 0) {
							tag.push(string(in + np, in + i));
							state = 0;
							i++;
							break;
						}
						else {
							if (tag.top() == string(in + np, in + i)) {
								tag.pop();
								state = 0;
								i++;
								break;
							}
							else {
								END;
							}
						}
					}
					if (!is_tag_char(in[i])) {
						state = 255;
						valid = false;
						break;
					}
					i++;
				}
				break;
			}
		}
		if (!tag.empty())valid = false;
		if (valid) printf("valid\n");
		else printf("invalid\n");
		while (!tag.empty())tag.pop();
	}
}