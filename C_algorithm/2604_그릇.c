#include <stdio.h>
#include <string.h>
int heightCalculate(char* arr) { // ���� ��� �Լ�
	int sum = 10; // �������� ���ڿ��� ���̴� �ּ� 3�̻��̹Ƿ� ù ��°�� ������ 10cm �� ����
	int i;
	for (i = 1;i < strlen(arr);i++) { // strlen(arr) �� ���鹮���̹Ƿ� �����ϰ� �˻� ����
		if (arr[i - 1] == arr[i]) {
			sum += 5; // ���� ���ڿ� ���� ��ȣ ������ �� �������Ƿ� += 5 ����
		}
		else {
			sum += 10; // ���� ���ڿ� �ٸ� ��ȣ ������ ���� �������� �����Ƿ� += 10 ����
		}
	}
	return sum;
}
// ( �� ) �� �̷���� ���ڿ��� �ް�, ( �Ǵ� ) �� 10 ���� ���, (( �Ǵ� )) �� 15�� ����Ѵ�.
// ���ڿ��� 3�̻� 50����. ���� ���̸� ���.
int main() {
	char arr[51]; // ���ڿ� ���� ����
	scanf_s("%s", arr, 51);

	printf("%d", heightCalculate(arr));

	return 0;
}