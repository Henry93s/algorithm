// ���� ���� �ð����⵵ : O(n2)
// ��� ������ ó������ �� ������ ���Ҹ� ���Ͽ� �ڸ��� �ٲٴ� ������ �ݺ��ϴ� ����
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