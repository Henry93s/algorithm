#include <stdio.h>

int main() {
	int N;
	scanf_s("%d", &N);

	int i = 2;
	while (i <= N) {
		if (N % i == 0) {
			printf("%d\n", i);
			N /= i;
		}
		else {
			i++;
		}
	}

	return 0;
}