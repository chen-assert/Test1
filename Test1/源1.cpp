#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<limits.h>
#include<queue>
#include<time.h>
#include<stack>
#define range(i, s, n) for (int i = s; i < int(n); i++)
//#include<windows.h>
using namespace std;
struct STU {
	int num;
	int de;
	int cai;
};
bool cmp(STU a,STU b){
	if (a.de + a.cai != b.de + b.cai)return a.de + a.cai > b.de + b.cai;
	if (a.de != b.de)return a.de > b.de;
	return a.num < b.num;
}
int main() {
	vector <STU>stu1, stu2, stu3, stu4;
	int n, l, h;
	scanf("%d %d %d", &n, &l, &h);
	int sum = 0;
	range(i, 0, n) {
		STU tstu = { 0 };
		scanf("%d %d %d", &tstu.num, &tstu.de, &tstu.cai);
		if (tstu.de < l || tstu.cai < l)continue;
		sum++;
		if (tstu.de >= h&&tstu.cai >= h)stu1.push_back(tstu);
		else if (tstu.de >= h)stu2.push_back(tstu);
		else if (tstu.de >= tstu.cai)stu3.push_back(tstu);
		else stu4.push_back(tstu);
	}
	sort(stu1.begin(), stu1.end(), cmp);
	sort(stu2.begin(), stu2.end(), cmp);
	sort(stu3.begin(), stu3.end(), cmp);
	sort(stu4.begin(), stu4.end(), cmp);
	printf("%d\n", sum);
	for (vector<STU>::iterator it = stu1.begin(); it != stu1.end(); it++)printf("%d %d %d\n", it->num, it->de, it->cai);
	for (vector<STU>::iterator it = stu2.begin(); it != stu2.end(); it++)printf("%d %d %d\n", it->num, it->de, it->cai);
	for (vector<STU>::iterator it = stu3.begin(); it != stu3.end(); it++)printf("%d %d %d\n", it->num, it->de, it->cai);
	for (vector<STU>::iterator it = stu4.begin(); it != stu4.end(); it++)printf("%d %d %d\n", it->num, it->de, it->cai);
}