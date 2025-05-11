#include <stdio.h>
void numberingTriangle(int N) {
	int i, j, k;
	int size;
	int print = 1;

	for (i = 1;i <= N;i++) {
		size = i;
		if (i % 2 == 1) { // 홀수 라인일 때 i 순서대로 출력
			for (j = i;j < i + size;j++, print++) {
				printf("%d ", print);
			}
			printf("\n");
		}
		else { // 짝수 라인일 때 이전 i + size(가로 길이) 부터 역순 출력
			for (j = print + size - 1;size >= 1;size--, j--, print++) {
				printf("%d ", j);
			}
			printf("\n");
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