#include <stdio.h>
#include <string.h>
#include <math.h>
// 2������ �޾Ƽ� 10������ ��ȯ ����ϴ� ����
long powNum(int n) { // 2�� �������� ���ϴ� �Լ�
	int i;
	long result = 1;
	if (n != 0) { // 2�� 0���� ���� �����ϰ� 2�� �������� ���Ѵ�.
		for (i = 0;i < n;i++) {
			result *= 2;
		}
	}
	return result;
}
long transDigit(char n[]) {
	int i;
	long sum = 0;

	for (i = strlen(n) - 1;i >= 0;i--) { // ���ڿ��� ������ ���� == ���ڿ��� ù ��° �ڸ�
		if (n[i] == '1') {
			sum += powNum(strlen(n) - 1 - i); // 2���� �� ���� 1�� ���� i ������ 2�� �������� ���Ѵ�.
		}
	}
	return sum;
}
int main() {
	char n[30]; // �Է¹��� 30�ڸ� ������ 2����

	scanf_s("%s", &n, 30);
	printf("%ld", transDigit(n));

	return 0;
}