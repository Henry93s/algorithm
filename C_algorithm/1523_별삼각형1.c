#include <stdio.h>
void PrintTriangle(int n, int m) {
	int i, j;

	switch (m)
	{
	case 1: // ���� ���� �ﰢ�� ���
		for (i = 0;i < n;i++) {
			for (j = 0;j < i + 1;j++) {
				printf("*");
			}
			for (j = 0;j < n - i + 1;j++) {
				printf(" ");
			}
			printf("\n");
		}
		break;
	case 2: // ���� ���� ���ﰢ�� ���
		for (i = 0;i < n;i++) {
			for (j = 0;j < n - i;j++) {
				printf("*");
			}
			for (j = 0;j < i;j++) {
				printf(" ");
			}
			printf("\n");
		}
		break;
	case 3: // �߾� ���� �ﰢ�� ���
		for (i = 0;i < n;i++) { 
			for (j = 0;j < n - i - 1;j++) { // ���� ���� �κ�
				printf(" ");
			}
			for (j = 0;j < 2 * i + 1;j++) { // �߾� * �κ�
				printf("*");
			}
			for (j = 0;j < n - i - 1;j++) { // ���� ���� �κ�
				printf(" ");
			}
			printf("\n");
		}
		break;
	default:
		break;
	}
}
int main() {
	int n; // �ﰢ���� ���� n
	int m; // ����� ���ﰢ���� ���� CASE ���� m

	scanf_s("%d %d", &n, &m);
	if (n < 0 || n > 100 || m < 1 || m > 3) { // �ﰢ�� ũ��� ���� �� ������ ��ġ���� ���� ��� ���� �α� ���
		printf("INPUT ERROR!");
	}
	else {
		PrintTriangle(n, m); // ���� m �� ���� ����ϴ� �Լ� ȣ��
	}

	return 0;
}