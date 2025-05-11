#include <stdio.h>
void numberingTriangle(int N) {
	int i, j, h;
	int space = 0;
	int print = 0;

	for (i = 1;i <= N;i++) {
		for (j = 1;j <= space;j++) {
			printf("  ");
		}
		for (h = 1;h <= N * 2 - 1 - (space * 2);h++) { // 맨 윗변 계산식 적용 : N * 2 - 1, 양끝 space 길이 : space * 2
			printf("%d ", print);
		}
		printf("\n");
		space++; print++;
	}

	return;
}
int main() {
	int N;
	scanf_s("%d", &N);
	if (N <= 0 || N > 50 || N % 2 == 0) {
		printf("INPUT ERROR!");
		return 0;
	}

	numberingTriangle(N);

	return 0;
}