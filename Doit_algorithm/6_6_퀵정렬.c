// �� ���� : �׷��� ������ ������ "�ǹ�(pivot)" �� �������� �� �׷� ��Ұ� 1���� �� ������ ���� �� ������ �����Ѵ�.
/*
	�ǹ�(pivot) : �ǹ��� ������� ������ �� ������ � �ǹ��� �����ߴ����� ���� ���� �Ǵ� ���� �ӵ��� ������ ��ħ
	
	[���� �� ���� �帧 - �������� ����]
	1. �� '�׷��� �߾ӿ� ��ġ�� ���' �� �ǹ��� ����
	2. �� �׷��� left, right �ε��� ����.
	3. left index ���� left ���� �ǹ����� ������ ��� ����(++)�ϰ�, ũ�ų� ������ ����;
	4. right index ���� right ���� �ǹ����� ũ�� ��� ����(--), �۰ų� ������ ����;
	5. �ǹ� �����Ͱ� �������� �ʾ��� ��(pl <= pr) �׷��� left ���� right ���� swap �ϰ�, pl, pr �����͸� �� ĭ�� �̵�
	6. �������� ��(pl > pr), �ش� �׷��� �� �׷����� ������, �� �׷� �� ���Ұ� 1���� �� ������ quick �Լ� ��� ȣ�� ����)
*/
#include <stdio.h>
#include <stdlib.h>
void quick(int* arr, int left, int right) {
	int pivot = (left + right) / 2; // 1. �� '�׷��� �߾ӿ� ��ġ�� ���' �� �ǹ��� ����
	int pl = left, pr = right; // 2. �� �׷��� left, right �ε��� ����.

	// quick sort �κ� ���� Ȯ���ϱ�
	for (int i = left; i <= right;i++) {
		printf("%d ", *(arr + i));
	}
	printf("\n");

	while (pl <= pr) {
		// 3. left index ���� left ���� �ǹ����� ������ ��� ����(++)�ϰ�, ũ�ų� ������ ����;
		while (*(arr + pl) < *(arr + pivot)) {
			pl++;
		}
		// 4. right index ���� right ���� �ǹ����� ũ�� ��� ����(--), �۰ų� ������ ����;
		while (*(arr + pr) > *(arr + pivot)) {
			pr--;
		}
		
		// 5. �ǹ� �����Ͱ� �������� �ʾ��� ��(pl <= pr) �׷��� left ���� right ���� swap �ϰ�, pl, pr �����͸� �� ĭ�� �̵�
		// �������� ������ swap �� �߻��� ��� �̹� ���ĵ� ������ ���߸� �� ����.
		if (pl <= pr) {
			int temp = *(arr + pl);
			*(arr + pl) = *(arr + pr);
			*(arr + pr) = temp;
			pl++;
			pr--;
		}
	}

	// 6. �������� ��(pl > pr), �ش� �׷��� ���� �۾� ����. 
	// ���� ���� �׷�� ������ �׷��� ��� divide �Ͽ� �����ϱ� ���� ��� ȣ��
	if (left < pr) {
		quick(arr, left, pr);   // ���� �κ� ����
	}
	if (pl < right) {
		quick(arr, pl, right); // ������ �κ� ����
	}
}

int main() {
	int N;
	scanf_s("%d", &N);
	int* arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N;i++) {
		scanf_s("%d", (arr + i));
	}

	quick(arr, 0, N - 1);

	printf("\n\n");
	for (int i = 0; i < N;i++) {
		printf("%d ", *(arr + i));
	}

	return 0;
}
