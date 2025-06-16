#include <stdio.h>

 int main() {
	int N, M;
	int temp;

	scanf_s("%d %d", &N, &M);
	if (N > M) {
		temp = N;
		N = M;
		M = temp;
	}

	int min, max;
	max = 0;
	int i = N;
	for(i = N;i >= 1; i--) {
		if (N % i == 0 && M % i == 0) {
			max = i;
			break;
		}
	}
	printf("%d\n", max);

	i = N;
	while (i % N != 0 || i % M != 0) {
		i++;
	}
	min = i;
	printf("%d", min);
	
	return 0;
}