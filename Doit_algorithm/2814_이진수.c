#include <stdio.h>
#include <string.h>
#include <math.h>
// 2진수를 받아서 10진수로 변환 출력하는 문제
long powNum(int n) { // 2의 제곱수를 구하는 함수
	int i;
	long result = 1;
	if (n != 0) { // 2의 0승일 때를 제외하고 2의 제곱수를 구한다.
		for (i = 0;i < n;i++) {
			result *= 2;
		}
	}
	return result;
}
long transDigit(char n[]) {
	int i;
	long sum = 0;

	for (i = strlen(n) - 1;i >= 0;i--) { // 문자열의 마지막 글자 == 숫자에서 첫 번째 자리
		if (n[i] == '1') {
			sum += powNum(strlen(n) - 1 - i); // 2진수 중 에서 1일 때만 i 승으로 2의 제곱수를 구한다.
		}
	}
	return sum;
}
int main() {
	char n[30]; // 입력받을 30자리 이하의 2진수

	scanf_s("%s", &n, 30);
	printf("%ld", transDigit(n));

	return 0;
}