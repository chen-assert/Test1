#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<limits.h>
#include<queue>
#include<time.h>
#include<stack>
#include<map>
#include<iostream>
//#include"segment tree.h"
//#include<windows.h>
#define range(i, s, e) for (int i = (s); i < int(e); i++)
#define range0(i, e) for (int i = 0; i < int(e); i++)
#define input_int(n) int n;scanf("%d",&n);
#define INF 0x3f3f3f3f
typedef unsigned long long ull;
using namespace std;
int price[28];
int flag = 0;
map<string, int>user;
struct R {
	string name;
	int month;
	int day;
	int hour;
	int minute;
	string statue;
	int last;
};
int cmp1(R a, R b) {
	if (a.month == b.month) {
		if (a.day == b.day) {
			if (a.hour == b.hour) {
				if (a.minute == b.minute) {
					//蛤?
					return 666;
				}
				return a.minute < b.minute;
			}
			return a.hour < b.hour;
		}
		return a.day < b.day;
	}
	return a.month < b.month;
}
int cmp2(vector<R> *a, vector<R>*b) {
	return a[0][0].name < b[0][0].name;
}
double cal_price(int on, int off, vector<R> *operate) {
	if (flag == 0) {
		printf("%s %02d\n", operate[0][0].name.c_str(), (*operate)[0].month);
		//如果没有任何有效通话记录就什么都不用输出...服了
		flag = 1;
	}
	printf("%02d:%02d:%02d ", operate[0][on].day, operate[0][on].hour, operate[0][on].minute);
	printf("%02d:%02d:%02d ", operate[0][off].day, operate[0][off].hour, operate[0][off].minute);
	printf("%d ", (operate[0][off].day - operate[0][on].day) * 24 * 60 + (operate[0][off].hour - operate[0][on].hour) * 60 + (operate[0][off].minute - operate[0][on].minute));
	double now_price = 0;
	range(i, operate[0][on].day * 24 + operate[0][on].hour, operate[0][off].day * 24 + operate[0][off].hour) {
		now_price += price[i % 24] * 60.0 / 100.0;
	}
	now_price -= operate[0][on].minute* price[operate[0][on].hour] / 100.0;
	now_price += operate[0][off].minute* price[operate[0][off].hour] / 100.0;
	printf("$%.2lf\n", now_price);
	return now_price;
}
int main() {
	range0(i, 24) {
		cin >> price[i];
		price[24] += price[i];
	}
	input_int(n);
	char t;
	int cnt = 1;
	R trecord;
	string name;
	vector<R> *record[1010];
	range0(i, n) {
		cin >> trecord.name >> trecord.month >> t >> trecord.day >> t >> trecord.hour >> t >> trecord.minute >> trecord.statue;
		if (user[trecord.name] == 0) {
			user[trecord.name] = cnt;
			record[user[trecord.name]] = new(vector<R>);
			record[user[trecord.name]][0].push_back(trecord);
			cnt++;
		}
		else {
			record[user[trecord.name]][0].push_back(trecord);
		}
	}
	range(i, 1, cnt) {
		sort(record[i][0].begin(), record[i][0].end(), cmp1);
	}
	sort(&record[1], &record[cnt], cmp2);
	range(i, 1, cnt) {
		//printf("%s %02d\n", record[i][0][0].name.c_str(), record[i][0][0].month);
		int on = -1, off = -1;
		double sum = 0;
		flag = 0;
		range0(a, record[i][0].size()) {
			if ((*record[i])[a].statue == "on-line") {
				on = a;
			}
			if (record[i][0][a].statue == "off-line") {
				off = a;
				if (on != -1) {
					sum += cal_price(on, off, record[i]);
					on = -1;
				}
			}
		}
		if (sum != 0) {
			printf("Total amount: $%.2lf\n", sum);
		}
	}
}