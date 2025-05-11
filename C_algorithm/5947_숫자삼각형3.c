#include <stdio.h>
void numberingTriangle(int N) {
	int i, j, h;
	int size = 1;
	int print;

	for (i = 1;i <= N;i++) {
		print = 1;
		for (j = 1;j <= size;j++) {
			printf("%d ", print++);
		}
		printf("\n");

		if (i < N / 2 + 1) { // 1 2 3 4 ... 까지 윗 삼각형 부분
			size++;
		}
		else { // 아래 삼각형 부분 처리
			size--;
		}
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