#include <stdio.h>
void numberingTriangle(int N) {
	int i, j, k;
	int size;
	int print = 1;

	for (i = 1;i <= N;i++) {
		size = i;
		if (i % 2 == 1) { // Ȧ�� ������ �� i ������� ���
			for (j = i;j < i + size;j++, print++) {
				printf("%d ", print);
			}
			printf("\n");
		}
		else { // ¦�� ������ �� ���� i + size(���� ����) ���� ���� ���
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