#include <stdio.h>
int main(void) {
	int a, b; // ������ �� �ڸ��� a �� �� �ڸ��� b �� ����
	scanf_s("%d %d", &a, &b);

	int num1 = a * (b % 10); // �� �ڸ��� ���� �� 3�ܰ�� ���� ���� ����
	int num2 = a * (b % 100 / 10);
	int num3 = a * (b / 100);
	int answer = num1 + num2 * 10 + num3 * 100;

	printf("%d \n%d \n%d \n%d ", num1, num2, num3, answer);

	return 0;
}