#include <stdio.h>
int main(void) {
	int a, b; // 곱셈할 세 자리수 a 와 세 자리수 b 값 선언
	scanf_s("%d %d", &a, &b);

	int num1 = a * (b % 10); // 세 자리수 곱셈 시 3단계로 나눈 곱셈 과정
	int num2 = a * (b % 100 / 10);
	int num3 = a * (b / 100);
	int answer = num1 + num2 * 10 + num3 * 100;

	printf("%d \n%d \n%d \n%d ", num1, num2, num3, answer);

	return 0;
}