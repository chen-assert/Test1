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
#include<regex>
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
int main() {
	string temp;
	ifstream fin("C:\\Users\\jingr\\Desktop\\work\\sh\\out.txt");
	ofstream fout("C:\\Users\\jingr\\Desktop\\work\\sh\\process.txt", std::ofstream::app);
	char str[10000];
	int n = 0;
	while (fin.getline(str, 10000)) {
		n++;
		if (n % 1000 == 0)cout << (double)n/(double)2000000 << endl;
		temp = str;
		regex a("realname");
		regex b("idcard");
		regex c("teacherNumber");
		bool match1 = regex_search(temp, a);
		bool match2 = regex_search(temp, b);
		bool match3 = regex_search(temp, c);
		if (match1 || match2 || match3)
		{
			//fout << str;
			//cout << temp.substr(6,100)<<endl;
			fout << temp.substr(6, 100) << endl;

			if (match2) {
				//cout << "\"password\" : \""<<temp.substr(temp.size()-9,6)<<"\","<<endl;
				fout << "\"password\" : \"" << temp.substr(temp.size() - 9, 6) << "\"," << endl;

			}
		}
	}
	fin.close();
	fout.close();
}