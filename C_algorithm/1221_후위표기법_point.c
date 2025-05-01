#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void push(int stack[], int* stackIndex, int data) {
	stack[++(*stackIndex)] = data;
	return;
}
int pop(int stack[], int* stackIndex) {
	int data = stack[(*stackIndex)--];
	return data;
}
int calculate(int a, int b, char op) {
	int result;

	switch (op)
	{
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		result = a / b;
		break;
	default:
		break;
	}
	return result;
}
int main() {
	int M; // 총 입력되는 연산자와 피연산자의 개수의 합
	scanf_s("%d", &M);

	char* str = (char*)malloc(sizeof(char) * (1000)); // 후위 표기법 연산 결과 데이터 스택
	// 1000 : 띄어쓰기 공백 포함 크기
	while (getchar() != '\n'); // 개행 문자 제거
	fgets(str, 1000, stdin); // 피연산자와 연산자가 포함된 문자열 입력받기
	/*
		추가
		scanf : 공백 또는 개행문자는 저장되지 않음
		fgets : 공백과 개행문자 모두 저장됨
	*/

	// 문자열에서 마지막 개행 문자 제거
	// ! strcspn(destination arr, 찾을 문자) => 찾을 문자가 있는 인덱스 반환
	str[strcspn(str, "\n")] = '\0';

	// stack 으로 후위표기법 연산 구현
	int* stack = (int*)malloc(sizeof(int) * 1000);
	int stackIndex = -1;
	int a, b; // 피연산자 변수
	int result; // 연산 결과 변수
	int i = 0;
	int temp; // 문자를 숫자로 바꾸고 숫자인지 확인하기 위한 temp 변수

	while (1) {
		if (str[i] != 32) { // 디버깅 결과 공백(space)의 경우 코드 값 32 체크
			temp = str[i] - '0'; // 문자를 숫자로 변환

			if (temp >= 0 && temp <= 9) { // str 의 문자가 숫자일 때는 push
				push(stack, &stackIndex, temp);
			}
			else { // str 의 문자가 숫자가 아닐 때는 (연산자) stack 에서 2개 문자 
				b = pop(stack, &stackIndex);
				a = pop(stack, &stackIndex);
				result = calculate(a, b, str[i]);
				push(stack, &stackIndex, result);

				if (i == strlen(str) - 1) {
					break;
				}
			}
		}
		i++;
	}

	printf("%d", stack[0]);

	free(str);
	free(stack);

	return 0;
}