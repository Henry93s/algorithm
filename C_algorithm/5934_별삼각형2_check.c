#include <stdio.h>
void LeftSide(int n) { // ���� ���� ������ �ﰢ�� ��� �Լ�
	int i, j;
	for (i = 0;i < n;i++) {

	}

}
void RightSide(int n) { // ������ ���� �ﰢ�� ����Լ� (LeftSide ���� �߾� * print��)
	int i, j;

}
int main() {
	int n;
	scanf_s("%d", &n);

	if (n < 1 || n > 100 || n % 2 != 0) {
		printf("INPUT ERROR!\n"); // �־��� ������ 100������ ���� ������ �ƴ� �� ���� ��� �� ���α׷� ����
	}
	else {
		LeftSide(n);
		RightSide(n);
	}

	return 0;
}