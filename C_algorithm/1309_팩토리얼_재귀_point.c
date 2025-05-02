#include <stdio.h>
// �������� ��� ���� int ������ ���� ��� long long ���
long long factorial(int n) {
	if (n == 0) {
		return 1; // 1 �� ��ȯ�ؾ� ������ ��ȯ�� �������
		// ��� ���� �� �ִ�.
		// ����Լ��� ���� return ���� '����' �� ���� ���Լ����� ��������
		// ���Լ��� �����͵��� �����ͼ� ������ �����Ѵ�.
	}
	else {
		if (n != 1) {
			printf("%d! = %d * %d!\n", n, n, n - 1);
		}
		else {
			printf("%d! = %d\n", n, n);
		}
		// ��� �Լ� ȣ��
		return n * factorial(n - 1);
	}
}
int main() {
	int n; 
	scanf_s("%d", &n);

	// �������� ��� ���� int ������ ���� ��� long long ���
	printf("%lld", factorial(n)); // long long ���� ��½� ���Ĺ��� %lld ���
	return 0;
}