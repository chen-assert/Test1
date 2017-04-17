#include<stdio.h>
int factorial(int p) {
	if (p == 0)return 1;
	int t = 1;
	for (int i = 1; i <= p; i++) {
		t *= i;
	}
	return t;
}
int main() {
	int input;
	scanf("%d", &input);
	while (input != -1) {
		int max = 0;
		for (int i = 0;; i++) {
			if (factorial(i) > input){
				max = i - 1;
				break;
			}
		}
		int sum = 0;
		for (int i = max; i >= 0; i--) {
			if (sum + factorial(i) <= input)sum += factorial(i);
			if (sum == input) {
				printf("YES\n");
				break;
			}

		}
		if (sum < input)printf("NO\n");
		
		
		
		scanf("%d", &input);
	}
}