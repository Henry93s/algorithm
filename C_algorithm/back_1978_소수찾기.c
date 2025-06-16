#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	scanf_s("%d", &N);
	int* arr = (int*)malloc(sizeof(int) * N);

	for (int i = 0;i < N;++i) {
		scanf_s("%d", (arr + i));
	}

	int j;
	int is_prime;
	int cnt = 0;
	for (int i = 0; i < N;++i) {
		is_prime = 1;
		j = 2;
		if (*(arr + i) == 1) {
			is_prime = 0;
		}
		else {
			while (j < *(arr + i)) {
				if (*(arr + i) % j == 0) {
					is_prime = 0;
					break;
				}
				j++;
			}
		}

		if (is_prime == 1) {
			cnt++;
		}
	}

	printf("%d", cnt);

	return 0;
}