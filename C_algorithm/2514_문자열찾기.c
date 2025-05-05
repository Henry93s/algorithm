#include <stdio.h>
#include <string.h>
int findStr1(char* arr) { // "KOI" 문자열이 몇 개 포함되어 있는지 찾는다.
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
int findStr2(char* arr2) { // "IOI" 문자열이 몇 개 포함되어 있는지 찾는다.
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

// 입력은 한 줄이고 10000자 이하의 알파벳 대문자 문자열이 주어진다.
// 해당 문자열에서 연속 3개의 문자가 "IOI" 이거나 "KOI" 인 문자열이 몇 개인지 찾기.
int main() {
	char arr[10001];
	scanf_s("%s", arr, 10001);

	printf("%d\n", findStr1(arr));
	printf("%d", findStr2(arr));

	return 0;
}