#include <stdio.h>
#include <string.h>
int findStr1(char* arr) { // "KOI" ���ڿ��� �� �� ���ԵǾ� �ִ��� ã�´�.
	int sum = 0;
	int i, j;
	for (i = 0;i < strlen(arr);) {
		if (arr[i] == 'K' && (i + 2) < strlen(arr)) {
			if (strncmp("KOI", arr + i, 3) == 0) {
				sum += 1;
				i += 2;
			}
			else {
				i++;
			}
		}
		else {
			i++;
		}
	}
	return sum;
}
int findStr2(char* arr2) { // "IOI" ���ڿ��� �� �� ���ԵǾ� �ִ��� ã�´�.
	int sum = 0;
	int i, j;
	for (i = 0;i < strlen(arr2);) {
		if (arr2[i] == 'I' && (i + 2) < strlen(arr2)) {
			if (strncmp("IOI", arr2 + i, 3) == 0) {
				sum += 1;
				i += 2;
			}
			else {
				i++;
			}
		}
		else {
			i++;
		}
	}
	return sum;
}

// �Է��� �� ���̰� 10000�� ������ ���ĺ� �빮�� ���ڿ��� �־�����.
// �ش� ���ڿ����� ���� 3���� ���ڰ� "IOI" �̰ų� "KOI" �� ���ڿ��� �� ������ ã��.
int main() {
	char arr[10001];
	scanf_s("%s", arr, 10001);

	printf("%d\n", findStr1(arr));
	printf("%d", findStr2(arr));

	return 0;
}