#include<stdio.h>
#include<stdlib.h> 
#include<algorithm>
#include<limits.h>
#include<time.h>
#include <math.h>  
#include<iostream>
#include<functional>
#include<fstream> 
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<string> 
#include<map>
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
map<string, int>m;

struct XX {
	int num;
	string name;
};
bool cmp(XX a, XX b) {
	if (a.num != b.num) {
		return a.num > b.num;
	}
	else {
		int t = a.name.compare(b.name);
		return t < 0;
		int len = min(a.name.length(), b.name.length());
		for (int i = 0; i < len; i++) {
			char ca = a.name[i];
			char cb = b.name[i];
			if (ca <= 'Z') {
				ca += 'a' - 'A';
			}
			if (cb <= 'Z') {
				cb += 'a' - 'A';
			}
			if (ca != cb)return ca < cb;
		}
		return false;
	}
}
vector<int>list[1000000];
int listnum = 0;
int main() {
	input_int(n);
	string in;
	std::getline(std::cin, in);
	//m.insert(pair<string, int>("xxx", 0));
	range0(i, n) {
		int count = 0;
		std::getline(std::cin, in);
		std::string pattern2 = "_paper_count\"\\s*:\\s*([^\"]*)";
		std::regex express2(pattern2);
		std::regex_token_iterator<std::string::const_iterator> begin2_2(in.cbegin(), in.cend(), express2, 1);
		count = std::atoi(begin2_2->str().c_str());
		/*if (count == 0) {
			std::string pattern3 = "citing_paper_count\"\\s*:\\s*\"([^\"]*)\"";
			std::regex express3(pattern3);
			std::regex_token_iterator<std::string::const_iterator> begin2_3(in.cbegin(), in.cend(), express2, 1);
			count = std::atoi(begin2_3->str().c_str());
		}*/
		std::string pattern1 = "_name\"\\s*:\\s*\"([^\"]*)\"";
		std::regex express1(pattern1);
		std::regex_token_iterator<std::string::const_iterator> begin2_1(in.cbegin(), in.cend(), express1, 1);
		for (auto iter = begin2_1; iter != std::sregex_token_iterator(); iter++)
		{
			string str = iter->str();
			//std::cout << str << std::endl;
			if (m.find(str) == m.end()) {
				m.insert(pair<string, int>(str, listnum++));
			}
			list[m[str]].push_back(count);
		}
	}
	vector<XX>vec;
	for (auto iter = m.begin(); iter != m.end(); iter++)
	{
		sort(list[iter->second].begin(), list[iter->second].end(), greater<int>());
		int o = 0;
		for (o = 0; o < list[iter->second].size(); o++) {
			if (o + 1 > list[iter->second][o])break;
		}
		vec.push_back({ o,iter->first });
	}
	sort(vec.begin(), vec.end(), cmp);
	for (std::vector<XX>::iterator iter = vec.begin(); iter != vec.end(); iter++)
	{
		printf("%s %d\n", (*iter).name.c_str(), (*iter).num);
	}
}