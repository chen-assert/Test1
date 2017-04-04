#include<stdio.h>
#include<algorithm>
using namespace std;
int expect=0;
int price[1000];
int sale[1000];
int preduce[1000];//positive
int reduce = 0;
int minoutput = 255;
int cost=0;
int i = 0;
struct FIND{
	int price;
	int	profit;
};
int abs(int n) {
	if (n < 0){
		return -n;
	}
	else return n;
}
int research(int subsidy) {
	FIND find;
	cost = price[0] - subsidy;
	int x = cost;//now tentative price
	int d = 0;//express price segment
	find.price = cost;
	find.profit = 0;
	while (1) {
		for (/*x=price[d]*/; x < price[d + 1]; x++) {
			int profit = (sale[d] - (x - price[d])*preduce[d])*(x - cost);//very confused
			//printf("%d--%d\n", x, profit);
			if (profit > find.profit || (profit == find.profit) && x == expect) {
				find.profit = profit;
				find.price = x;
			}
		}
		d++;
		if (d == i - 1)break;
	}
	while (1) {
		int profit = (sale[d] - (x - price[d])*preduce[d])*(x - cost);
		//printf("%d--%d\n", x, profit);
		if (profit > find.profit || (profit == find.profit) && x == expect) {
			find.profit = profit;
			find.price = x;
		}
		x++;
		if (sale[d] - (x - price[d])*preduce[d] <= 0)break;
	}
	if (find.profit> 0) {
		//printf("%d--%d\n", subsidy, find.price);
		if (find.price == expect) {
			if (abs(subsidy) < abs(minoutput)) {
				minoutput = subsidy;
			}
		}
		return 1;
	}
	return 0;//stop research
}
int main() {
	scanf("%d", &expect);
	while (1) {
		scanf("%d %d", &price[i], &sale[i]);//if date is out-of-order, we may need to sort them
		if (price[i] == -1) break;
		i++;
	}//total i date
	scanf("%d", &reduce);
	for (int t = 0; t < i - 1; t++) {
		preduce[t] = (sale[t] - sale[t + 1]) / (price[t + 1] - price[t]);
	}
	preduce[i - 1] = reduce;
	for (int x = price[0] - 1;/*may have problem*/; x--) {
		int t=research(x);
		if (t == 0)break;
	}
	if (minoutput == 255)printf("NO SOLUTION");
	else printf("%d", minoutput);
	return 0;
}