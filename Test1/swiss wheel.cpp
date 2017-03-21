#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
int n, r, q;
struct player {
	int score;
	int ability;
};
void round() {

}
int main() {
	scanf("%d %d %d", &n, &r, &q);
	player p[2 * n];
	for (int i = 0; i<n; i++) {
		scanf("%d", p[i].score);
	}
	for (int i = 0; i<n; i++) {
		scanf("%d", p[i].ability);
	}
	sort(p[0].score, p[n - 1].score, greater<int>());
}