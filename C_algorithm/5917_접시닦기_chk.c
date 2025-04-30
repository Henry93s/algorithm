#include <stdio.h>
#include <stdlib.h>
void Wait(int* stack, int dish, int* index1) {
	stack[++(*index1)] = dish;
	return;
}
void Wash(int* stack1, int* stack2, int* index1, int* index2, int n) {
	int data = stack1[(*index1)--];
	stack2[++(*index2)] = data;
	return;
}
void Dry(int* stack2, int* stack3, int* index2, int* index3, int n) {
	int data = stack2[(*index2)--];
	stack3[++(*index3)] = data;
	return;
}
int main() {
	int n, t;
	scanf_s("%d %d", &n, &t);
	
	int* stack1 = (int*)malloc(sizeof(int) * n); // ��� ���� ���� 2�� �׽�Ʈ��
	int index1 = -1;
	int* stack2 = (int*)malloc(sizeof(int) * n); // �Ĵ� ���� ����
	int index2 = -1;
	int* stack3 = (int*)malloc(sizeof(int) * n); // ���� ���� ����
	int index3 = -1;

	int i;
	for (i = n - 1;i >= 0;i--) {
		Wait(stack1, i + 1, &index1);
	} // wait ���� ���� �Ϸ� -> �������� ����


	int cnt; // 1 �Ǵ� 2 ���(wash �Ǵ� dry ���� Ƚ��)
	int j;
	int op, dish; // ��ɰ� ������ ��

	for (i = 0;i < t;i++) {
		scanf_s("%d %d", &op, &dish);
		for (j = 1;j <= dish;j++) {
			// ���� ����ŭ ��� ���� ����
			if (op == 1) {
				Wash(stack1, stack2, &index1, &index2, n);
			}
			else if (op == 2) {
				Dry(stack2, stack3, &index2, &index3, n);
			}
		}
	}


	// ���� ��� stack3 (dry �� ����) ���
	for (i = n - 1;i > -1;i--) {
		printf("%d\n", stack3[i]);
	}


	return 0;
}