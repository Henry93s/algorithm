#include <stdio.h>
void numberingTriangle(int N) {
	int i, j, h;
	int space = 0;
	int print = 0;

	for (i = 1;i <= N;i++) {
		for (j = 1;j <= space;j++) {
			printf("  ");
		}
		for (h = 1;h <= N * 2 - 1 - (space * 2);h++) { // �� ���� ���� ���� : N * 2 - 1, �糡 space ���� : space * 2
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