#include<stdio.h>
#include<stdlib.h> 
#include<algorithm>
#include<limits.h>
#include<time.h>
#include<iostream>
#include<functional>
#include<fstream> 
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<string.h> 
#include<string> 
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
struct party {
	ll num;
	ll seats;
	vector<int>re;
}p[60];
ll arr[2][3][7][2];
void flash() {
	range0(i, 2) {
		range0(o, 3) {
			range0(p, 7) {
				if (arr[i][o][p][1] > arr[i][o][p][0]) {
					arr[i][o][p][0] = arr[i][o][p][1];
				}
				arr[i][o][p][1] = arr[i][o][p][0];
			}
		}
	}
}
int main() {
	ll part;
	ll need_seat;
	int first = 0;
	//char temp[100000];
	string temp2;
	while (1) {
		//scanf("%d %lld\n", &part, &need_seat);
		cin >> part >> need_seat;
		if (part == 0 && need_seat == 0) break;
		getline(cin, temp2);
		for (int i = 0; i < part; i++) {
			p[i].re.clear();
			//scanf("%lld:", &p[i].seats);
			//gets_s(temp, 100000);
			getline(cin, temp2);
			int j = 0;
			ll s = 0;
			for (j = 0; temp2[j] != ':'; j++) {
				s *= 10;
				s += temp2[j] - '0';
			}
			p[i].seats = s;
			ll count = 0;
			for (; temp2[j] != ';'; j++) {
				if (isdigit(temp2[j])) {
					p[i].re.push_back(temp2[j] - '0');
					count++;
				}
			}
			p[i].num = count / 3;
		}
		range0(z, 2) {
			range0(x, 3) {
				range0(c, 7) {
					arr[z][x][c][0] = 0;
					arr[z][x][c][1] = 0;
				}
			}
		}
		range0(i, part) {
			range0(o, p[i].num) {
				int n1 = p[i].re[o * 3];
				int n2 = p[i].re[o * 3 + 1];
				int n3 = p[i].re[o * 3 + 2];
				range0(z, 2) {
					range0(x, 3) {
						range0(c, 7) {
							if (z + n1 <= 1 && x + n2 <= 2 && c + n3 <= 6) {
								if (arr[z][x][c][0] + p[i].seats > arr[z + n1][x + n2][c + n3][1])
									arr[z + n1][x + n2][c + n3][1] = arr[z][x][c][0] + p[i].seats;
							}
						}
					}
				}
			}
			flash();
		}
		range0(z, 2) {
			range0(x, 3) {
				range0(c, 7) {
					if (arr[z][x][c][0] >= need_seat) {
						printf("%d %d %d\n", 1 - z, 2 - x, 6 - c);
						goto lab;
					}
				}
			}
		}
		printf("0 0 0\n");
	lab:;
	}
	return 0;
}