#include <stdio.h>
int main() {
	int n; // 100이하 홀수인 양의 정수 n
	scanf_s("%d", &n);
	if (n <= 0 || n > 100 || n % 2 == 0) {
		printf("INPUT ERROR!");
		return 0;
	}
	
	int op = n;
	int i, j, k, l;
	// 윗 삼각형 ( * 한 개 포함)
	for (i = 1;i <= n / 2 + 1;i++) {
		for (l = 1;l < i;l++) {
			printf(" ");
		}
		for (j = l; j <= n / 2 + 1;j++) {
			printf("*");
		}
		printf("\n");
	}
	
	// 아래 삼각형
	int p = 2;
	for (k = i;k <= n;k++) {
		for (l = 1;l <= n / 2;l++) {
			printf(" ");
		}
		for (j = 1; j <= p;j++) {
			printf("*");
		}
		p++;
		printf("\n");
	}
	
	return 0;
}