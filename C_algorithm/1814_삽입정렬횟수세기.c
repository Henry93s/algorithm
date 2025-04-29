// ���� ���� �ð����⵵ : O(n2)
// ��� ������ ó������ �� ������ ���Ҹ� ���Ͽ� �ڸ��� �ٲٴ� ������ �ݺ��ϴ� ����
#include <stdio.h>
#include <stdlib.h>
int MoveInsertionCnt(int arr[], int n) {
	int i, j, temp;
	int cnt = 0; // cnt : ���������� ����Ǿ� �о�� �̵��� �߻��� �� ���� ��Ʋ�
	// �� �� �� �̵��ߴ����� ���� ����
	int k;
	for (i = 1;i < n;i++) {
		for (j = i;j > 0;j--) {
			if (arr[j] < arr[j - 1]) {
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;

				cnt += j - (j - 1);
			}
		}
	}
	return cnt;
}
int main() {
	int n;
	scanf_s("%d", &n);

	int* arr = (int*)malloc(sizeof(int) * n);
	int i;
	for (i = 0;i < n;i++) {
		scanf_s("%d", arr + i);
	}
	printf("\n");

	printf("%d\n", MoveInsertionCnt(arr, n));
	return 0;
}