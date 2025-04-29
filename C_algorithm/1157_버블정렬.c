// 버블 정렬 시간복잡도 : O(n2)
// 계속 수열의 처음부터 두 인접한 원소를 비교하여 자리를 바꾸는 과정을 반복하는 정렬
#include <stdio.h>
#include <stdlib.h>
int main() {
	int n;
	scanf("%d", &n);

	int* arr = (int*)malloc(sizeof(int) * n);
	int i;
	for (i = 0;i < n;i++) {
		scanf("%d", arr + i);
	}
	printf("\n");

	int j;
	int temp;
	int k;
	for (i = 0;i < n - 1;i++) {
		for (j = 0;j < n - 1;j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		for (k = 0;k < n;k++) {
			printf("%d ", arr[k]);
		}
		printf("\n");
	}

	return 0;
}