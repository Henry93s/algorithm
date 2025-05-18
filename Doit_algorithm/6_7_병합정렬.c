#include <stdio.h>
#include <stdlib.h>
void swap(int* arr, int x, int y) {
	int temp = *(arr + x);
	*(arr + x) = *(arr + y);
	*(arr + y) = temp;
}
// merge : ��� ���("����") �� ������ ���� �۾��� �����Ѵ�.
void merge(int* arr, int left, int mid, int right) {
	// ��� �� �� ���� �ӽ� �迭 �� �迭 �ε��� ���� ���� ����
	// 
	// ���� ��Ʈ 1 : �ӽ� �迭 ũ��� right - left + 1 ���� �ľ�
	int* tempArr = (int*)malloc(sizeof(int) * (right - left + 1));
	int tempIndex = 0;
	// left, right �� ������ �ε��� ���� ���� ����
	int leftIndex = left;
	int rightIndex = mid + 1;

	// ���ʰ� ������ �������� �� ���� -> �켱���� ���� tempArr �տ� ��ġ
	while (leftIndex <= mid && rightIndex <= right) {
		if (*(arr + leftIndex) < *(arr + rightIndex)) {
			*(tempArr + tempIndex) = *(arr + leftIndex);
			leftIndex++; 
		} else {
			*(tempArr + tempIndex) = *(arr + rightIndex);
			rightIndex++;
		}
		tempIndex++;
	}

	// ������ break �Ǿ��� �� ���� �����ִ� �ܿ� ���Ҹ� tempArr �� �־� ���� ������ �ϼ���
	while (leftIndex <= mid) {
		*(tempArr + tempIndex) = *(arr + leftIndex);
		leftIndex++; tempIndex++;
	}
	while (rightIndex <= right) {
		*(tempArr + tempIndex) = *(arr + rightIndex);
		rightIndex++; tempIndex++;
	}

	// debugging code
	int tempStart = 0;
	for (int i = tempStart;i < tempIndex;i++) {
		printf("%d ", *(tempArr + i));
	}
	printf("\n");

	// ���ĵ� �ӽ� �迭�� arr ���� �迭�� ����
	// 
	// ���� ��Ʈ 2 : merge �Լ� ���ڸ� Ȯ�� �� �������� left �̹Ƿ� 
	//				 arr �� 0 �� �ƴ�, �������� left �� ���縦 �����ؾ���!!
	for (int i = tempStart;i < tempIndex;i++) {
		*(arr + left + i) = *(tempArr + i);
	}
}


// mergeSort �������� ���� �� �����̹Ƿ� �ش� �Լ����� ���("����") �۾��� ����
void mergeSort(int* arr, int left, int right) {
	// ��� �Լ� ���� ���� : ������ ������ 2�� �̻��� �� ��� ���� �� ����
	if (left < right) {
		// �߰� ���� ���� mid ����
		int mid = left + (right - left) / 2;

		// ����, ������ �κ� ��� mid ������ �������� �ɰ��� ����(���) ����
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		// ���� �۾��� ��� ����Ǿ� ��� -> �ǵ��ƿ��� ���� ����
		// ���� ���� : �ؿ������� ����� ����)
		merge(arr, left, mid, right);
	}
}

int main() {
	int N;
	printf("�Է¹��� ������ ���� : ");
	scanf_s("%d", &N);
	int* arr = (int*)malloc(sizeof(int) * N);

	printf("%d �� ���� �Է�(���� ����): ", N);
	for (int i = 0;i < N;i++) {
		scanf_s("%d", arr + i);
	}

	mergeSort(arr, 0, N - 1);

	for (int i = 0;i < N;i++) {
		printf("%d ", *(arr + i));
	}

	free(arr);
	return 0;
}