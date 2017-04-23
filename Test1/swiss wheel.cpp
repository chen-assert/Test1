#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
using namespace std;
int n, r, q;
struct player {
	int score;
	int ability;
	int number;
};
void round(player *record) {
	for (int i = 0; i < n; i++) {
		if (record[2 * i].ability > record[2 * i + 1].ability)record[2 * i].score++; 
		else record[2*i + 1].score++;
		if (record[2 * i].score < record[2 * i + 1].score) {
			swap(record[2 * i], record[2 * i + 1]);
			continue;
		}
		if (record[2*i].score == record[2*i+1].score) {
			if (record[2 * i].number > record[2 * i + 1].number) {
				swap(record[2 * i], record[2 * i + 1]);
				continue;
			}
		}
		
	}
	
}
bool ggreater(player a,player b) {
	if (a.score == b.score) {
		if (a.number < b.number)return true;
		return false;
	}
	if (a.score > b.score) {
		return true;
	}
	return false;
}
player* merge(player *record) {
	player *record2 = (player*)malloc(sizeof(player) * (2 * n + 10));
	int flag1 = 0, flag2 = 0,flag0=0;
	while (1) {
		if (flag0 == 2*n)break;
		if (flag1 == n) {
			record2[flag0] = record[flag2 * 2 + 1];
			flag0++;
			flag2++;
			continue;
		}
		if (flag2 == n) {
			record2[flag0] = record[flag1 * 2];
			flag0++;
			flag1++;
			continue;
		}
		if (record[flag1 * 2].score == record[flag2 * 2 + 1].score) {
			if (record[flag1 * 2].number < record[flag2 * 2 + 1].number) {
				record2[flag0] = record[flag1 * 2];
				flag0++;
				flag1++;
				continue;
			}
			else {
				record2[flag0] = record[flag2 * 2 + 1];
				flag0++;
				flag2++;
				continue;
			}
		}
		if (record[flag1 * 2].score > record[flag2 * 2 + 1].score) {
			record2[flag0] = record[flag1 * 2];
			flag0++;
			flag1++;
		}
		else {
			record2[flag0] = record[flag2 * 2+1];
			flag0++;
			flag2++;
		}

	}
	free(record);
	return record2;
}
int main() {
	scanf("%d %d %d", &n, &r, &q);
	player *record = (player*)malloc(sizeof(player) * (2 * n+10));
	//player *record2 = (player*)malloc(sizeof(player) * (2 * n + 10));
	for (int i = 0; i<2*n; i++) {
		scanf("%d", &record[i].score);
		record[i].number = i+1;
	}
	for (int i = 0; i<2*n; i++) {
		scanf("%d", &record[i].ability);
	}
	sort(record, record+2*n, ggreater);//½µÐò
	/*for (int i = 0; i<2*n; i++) {
		printf("%d %d %d\n", record[i].score,record[i].ability,record[i].number);
	}
	printf("\n");*/
	for (int i = 0; i < r; i++) {
		round(record);
		record=merge(record);
	}
	/*for (int i = 0; i<2 * n; i++) {
		printf("%d %d %d\n", record[i].score, record[i].ability, record[i].number);
	}*/
	printf("%d", record[q - 1].number);
	free(record);
}