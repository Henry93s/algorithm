#include <stdio.h>
int main() {
	int a, b;
	scanf("%d %d", &a, &b); // �� ���� �ڿ��� ���� ���� �� �Է�

	int i;
	int small, big; // �� ���� �ڿ��� �� ���� ���� ū �� ���� ����
	int maxdiv, minmul; // �ִ������� �ּҰ���� ���� ����
	a > b ? (small = b, big = a) : (small = a, big = b);
	// ���� ���� ū ���� ���� �� ������ ����

	for (i = 1;i <= small;i++) { // �� �ڿ��� �� ���� ������ �����ϸ鼭 
		if (small % i == 0 && big % i == 0) { // �� �ڿ����� i �� ������ ��� ��� �ִ������� ��ü
			maxdiv = i;
		}
	}
	for (i = big;i <= a * b;i++) { // �� �ڿ����� ������ �����ϸ鼭 
		if (i % a == 0 && i % b == 0) { // i �� a �Ǵ� b �� ��� ������ ��� �ּҰ������ �����ϰ� break;
			minmul = i;
			break; // �ּҰ�����̹Ƿ� �� ���� �����ϰ� �ٷ� break;
		}
	}

	printf("%d\n%d\n", maxdiv, minmul);
	return 0;
}