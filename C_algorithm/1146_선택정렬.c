#include <stdio.h>
#include <stdlib.h>
// ���� ���� �ð����⵵ : O(n2)
// �־��� �������� �ּҰ��� ã�� �ش� ������ �� ���� ���� �ڸ��� �ٲ� ��,
// �� ���� ���� �� ������ ������ ���� ������� �ݺ� ����
int main() {
	int n; // ������ ���� n
	scanf_s("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);

	int i; // ���� ������ �Է�
	for (i = 0;i < n;i++) {
		scanf_s("%d", &arr[i]);
	}

	int j;
	int temp; // ã�� �ּҰ��� ������ ���� �� ���� �� swap
	int k, min_index; // ���� �� �������� ����� ���� k
	// ���� �������� ã�� �ּҰ��� ���� �ε��� min_index
	for (i = 0;i < n - 1;i++) { // ���� �������� �ּҰ��� ã�� �� �� �� ������ �� �� ������ ���� �񱳰� ���ʿ��� : n - 1
		min_index = i;
		for (j = i;j < n;j++) {
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
		
		for (k = 0; k < n;k++) { // ���İ����� �� �ܰ躰 ����� ����Ѵ�.
			printf("%d ", arr[k]);
		}
		printf("\n");
	}

	return 0;
}