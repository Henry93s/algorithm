#include <stdio.h>
void danPrint(int n, int m) {
	if (n == 10) { // 9�ܱ��� ������ ����
		return;
	}
	if (m == 10) { // �ϳ��� ���� ������ ���๮�ڸ� �ְ� ���� �÷��� ���
		printf("\n");
		danPrint(n + 1, 1); // ���� �� ����Լ� ȣ��
	}
	printf("%d * %d = %d\n", n, m, n * m);
	danPrint(n, m + 1); // ���� �ܿ��� ���� ���� �ǿ����� ���� �� ����Լ� ȣ��
}

int main() {
	danPrint(2, 1); // 2 * 1 ���� ����ϱ� ���� ������ ����Լ� ȣ��

	return 0;
}