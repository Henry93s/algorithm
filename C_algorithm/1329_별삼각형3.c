#include <stdio.h>
void drawingTriangle(int N) {
	int star = 1;
	int space = 0;

	int i, j;
	for (i = 1;i <= N / 2 + 1;i++) { //  + 1 : 중심까지
		for (int j = 0;j < space;j++) {
			printf(" ");
		}
		space++;
		for (int j = 0;j < star;j++) {
			printf("*");
		}
		star += 2;
		printf("\n");
	}

	int k;
	space -= 2;
	star -= 4;
	for (k = i;k <= N;k++) {
		for (int j = 0;j < space;j++) {
			printf(" ");
		}
		space--;
		for (int j = 0;j < star;j++) {
			printf("*");
		}
		star -= 2;
		printf("\n");
	}
	return;
}

int main() {
	int N;

	scanf_s("%d", &N);
	if (N <= 0 || N > 100 || N % 2 == 0) {
		printf("INPUT ERROR!");
		return 0;
	}

	drawingTriangle(N);
	return 0;
}