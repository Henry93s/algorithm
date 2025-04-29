#include <stdio.h>
#include <stdlib.h>
// ���� �������� �ð����⵵ : O(n2)
// -> �ڷ� �迭�� ��� ��Ҹ� �տ������� ���ʴ�� �̹� ���ĵ� �迭 �κа� �� �� ����
int main() {
	int n;
	scanf_s("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	
	int i;
	for (i = 0;i < n;i++) {
		scanf_s("%d", arr + i);
	}

	int j, k;
	int temp;
	for (i = 1;i < n;i++) { // ������ ������ ù��° �ε������� ��� ���ϸ鼭 �ּҰ� swap
		for (j = i;j > 0;j--) {
			if (arr[j] < arr[j - 1]) {
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}

		for (k = 0;k < n;k++) {
			printf("%d ", arr[k]);
		}
		printf("\n");
	}

	return 0;
}