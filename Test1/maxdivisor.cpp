#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int maxdivisor(int a, int b) {
	vector<int> q;
	if (a > b) {
		q.push_back(a);
		q.push_back(b);
	}
	else {
		q.push_back(b);
		q.push_back(a);
	}
	while (1) {
		int t = q.at(0) % q.at(1);
		if (t == 0) {
			return q.at(1);
		}
		q.push_back(t);
		q.erase(q.begin());
	}
	return -1;
}
int main() {
	int x, y;
	int ans = 0;
	scanf("%d %d", &x, &y);
	for (int a = x; a <= y; a += x) {
		for (int b = x; b <= y; b += x) {
			int k = maxdivisor(a, b);
			int p = a*b / k;
			if (k == x&&p == y)ans++;
		}
	}
	cout << ans;
}