#include <stdio.h>
#include <stdlib.h>
void swap(int* arr, int a, int b) {
	int temp = *(arr + a);
	*(arr + a) = *(arr + b);
	*(arr + b) = temp;
}
void quickSort(int* arr, int left, int right) {
	// �ǹ��� ������ ������ ù ��° ���ҷ� ����
	int pivot = *(arr + left);
	int pivotIndex = left;
	// �Ű������� �޾ƿ� ����, ������ ������ ����
	int leftStart = left;
	int rightStart = right;

	// �迭 �¿� ������ ����
	int l = left + 1;
	int r = right;

	// left �� right �� ������ ������ �ݺ�
	// "������ ������ �ݺ� ����" : �������� ������ ���ο� �ǹ� �������� ���� �� ������ ū �� ������ "����"&"����" �� �� ����.
	while (l <= r) {
		// l �� �����Ͱ� ������ ���� �������� �۰ų� ����, �� ������ �迭 ���� �ǹ����� �۰ų� ���� ���� �������� �̵�
		while (l <= right && *(arr + l) <= pivot) {
			l++;
		}
		// r �� �����Ͱ� ������ ���� �������� ũ�ų� ����, �� ������ �迭 ���� �ǹ����� ũ�ų� ���� ���� �������� �̵�
		while (r >= left + 1 && *(arr + r) >= pivot) {
			r--;
		}
		// "�� �����Ͱ� ã�� �ǹ����� ū ��" �� "�� �����Ͱ� ã�� �ǹ����� ���� ��" swap �� �ٽ� ������ ������ �ݺ�
		if (l < r) {
			swap(arr, l, r);
			l++;
			r--;
		}
	}

	// �������� �� "�ǹ��� ����"���� �ǹ����� "���� ���� ������ �� -> �·� �̵��� �� ������"
	swap(arr, pivotIndex, r); // �ǹ��� swap �� [����] �۾��� �Ϸ�
	// ����� �׽���
	for (int i = leftStart; i <= rightStart; i++) {
		printf("%d ", *(arr + i));
	}
	printf("\n");

	// ���� �� ������ ���� ������ ����
	// "�� -> �� �� �̵��� �� ������" == "��� swap �������� pivotIndex" �� �����Ƿ� 
	// ������ ���� �������� "���ο� �� ������" ���� ������, quickSort(arr, "�� �� ������", "�� �� ������") �� ��� �Լ� ȣ��
	if (leftStart < r - 1) {
		quickSort(arr, leftStart, r - 1);
	}
	// ���� �� ������ ������ ������ ����
	// "�� -> �� �� �̵��� �� ������" == "��� swap �������� pivotIndex" �� �����Ƿ� 
	// "���ο� �� ������" �� ������ ���� �������� ������, quickSort(arr, "�� �� ������", "�� �� ������") �� ��� �Լ� ȣ��
	if (r + 1 < rightStart) {
		quickSort(arr, r + 1, rightStart);
	}
}

int main() {
	int N;
	printf("�迭 ������ ����: ");
	scanf_s("%d", &N);
	int* arr = (int*)malloc(sizeof(int) * N);
	
	printf("�迭 ��� �Է�: ");
	for (int i = 0;i < N;i++) {
		scanf_s("%d", arr + i);
	}

	quickSort(arr, 0, N - 1);

	for (int i = 0;i < N;i++) {
		printf("%d ", *(arr + i));
	}

	free(arr);
	return 0;
}