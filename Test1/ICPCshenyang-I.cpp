#include<stdio.h>
#include <stdlib.h> 
#include<algorithm>
#include<limits.h>
#include<time.h>
#include<iostream>
#include<functional>
#include<vector>
#include<queue>
#include<string.h>
#include<stack>
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
inline void read(int &x) {//only read int
	static char c;
	for (c = getchar(); !('0' <= c && c <= '9'); c = getchar());
	for (x = 0; '0' <= c && c <= '9'; x = x * 10 + c - 48, c = getchar());
}
int BigRand()
{
	return RAND_MAX * rand() + rand();
}
char tc[4];

inline void hex2bin(char c)
{
	for (int i = 0; i != 4; ++i)
	{
		tc[3 - i] = c & 1;
		c = c >> 1;
	}
}
int M, L;
struct node
{
	int ascii;
	char str[12];
};
struct tn {
	tn *left, *right;
	int ascii;
};
tn* create_tree(node *base) {
	tn* root = new tn();
	for (int i = 0; i < L; i++) {
		tn *nt = root;
		for (int o = 0; o < strlen(base[i].str); o++) {
			if (base[i].str[o] == '0') {
				//left
				if (nt->left == NULL) {
					nt->left = new tn();
				}
				nt = nt->left;
			}
			else {
				//right
				if (nt->right == NULL) {
					nt->right = new tn();
				}
				nt = nt->right;
			}
		}
		nt->ascii = base[i].ascii;
	}
	return root;
}
char raw[200010];
vector<char>passed;

inline void readraw()
{
	int i = 0;
	getchar();
	while ((raw[i] = getchar())) {
		if (raw[i] == '\n')break;
		++i;
	}
}

char tmp[16];
int pput(tn* root,int n) {
	tn* np = root;
	while(np->left != NULL || np->right != NULL) {
		if (passed[n] == 0) {
			np = np->left;
		}
		else {
			np = np->right;
		}
		n++;
	}
	printf("%c",np->ascii);
	return n;
}
int main()
{
	//std::ios_base::sync_with_stdio(false);
	//std::cin.tie(0);
	//srand((unsigned int)(time(NULL)));
	int T;
	scanf("%d", &T);
	for (int ca = 0; ca != T; ++ca)
	{
		//读取
		passed.clear();
		scanf("%d %d", &M, &L);
		char *ans = new char[M + 1]{};
		//memset(ans, 0, sizeof(ans));
		node *base = new node[L]{};
		for (int i = 0; i != L; ++i)
			scanf("%d %s", &base[i].ascii, &base[i].str);
		readraw();//读取到 raw[]
		//处理
		int len = strlen(raw);
		memset(tmp, 0, sizeof(tmp));//清空临时数组
		int addr = 0;
		int calc = 0;//bit 计数器
		for (int i = 0; i < len; ++i)
		{
			//hex2bin(raw[i]);//存储到 tc[]
			//start hex
			if (raw[i] <= '9' && raw[i] >= '0')
				hex2bin(raw[i] - '0');
			else if (raw[i] <= 'f' && raw[i] >= 'a')
				hex2bin(raw[i] - 'a' + 10);
			else
				hex2bin(raw[i] - 'A' + 10);
			for (int j = 0; j != 4; ++j)
			{
				tmp[addr] = tc[j];
				addr = (addr + 1) % 16;
			}
			calc += 4;
			if (calc >= 9)
			{
				int addr2 = (addr - calc + 16) % 16;
				calc %= 9;
				int one = 0;
				for (int j = 0; j < 8; ++j) {
					if (tmp[(addr2 + j) % 16] == 1)++one;
				}
				if ((one % 2 == 0 && tmp[(addr2 + 8) % 16] == 1) || (one % 2 == 1 && tmp[(addr2 + 8) % 16] == 0))
				{
					for (int j = 0; j < 8; ++j)
						passed.push_back(tmp[(addr2 + j) % 16]);
					//valid
				}
				else
				{
					//invalid
					//drop
				}
			}
		}
		tn* root = create_tree(base);
		delete[]base;
		int n = 0;
		range0(i, M) {
			n=pput(root,n);
		}
		printf("\n");
	}

	return 0;
}