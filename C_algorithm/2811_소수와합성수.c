#include <stdio.h>
// for �ݺ������� �Է� ���� �� 10���������� ���� �� ���� ���� �ð� 1�ʸ� �ʰ��ϰ� �ȴ�.
// -> ���� �ʿ� : ����� ���� �� �������� �̿�
// a * b = n (a > 1, b > 1) �� �� a �� b�� n �� ����̴�.
// --> a �� b �� ���� �� �ʸ� Ȯ���ص� n �� �ռ������� �� �� ����
/*
void isPrime(int n) {
	int i;
	int cnt = 0;
	for (i = 1;i <= n;i++) {
		if (n % i == 0) {
			cnt++;
		}
	}
	if (cnt == 2) {
		printf("prime number\n");
	}
	else if (cnt == 1) {
		printf("number one\n");
	}
	else {
		printf("composite number \n");
	}
}
*/
void isPrime(int n) {
	if (n < 2) { 
		printf("number one\n");
		return;
	}
	for (int i = 2;i <= n / i;i++) {
		if (n % i == 0) {
			printf("composite number \n");
			return;
		}
	}
	printf("prime number\n");
	return;
}
int main() {
	int n;
	int arr[5];
	for (int i = 0;i < 5;i++) {
		scanf_s("%d", &arr[i]);
		isPrime(arr[i]);
	}
	return 0;

}