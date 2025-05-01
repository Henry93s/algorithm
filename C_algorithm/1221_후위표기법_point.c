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
	int M; // �� �ԷµǴ� �����ڿ� �ǿ������� ������ ��
	scanf_s("%d", &M);

	char* str = (char*)malloc(sizeof(char) * (1000)); // ���� ǥ��� ���� ��� ������ ����
	// 1000 : ���� ���� ���� ũ��
	while (getchar() != '\n'); // ���� ���� ����
	fgets(str, 1000, stdin); // �ǿ����ڿ� �����ڰ� ���Ե� ���ڿ� �Է¹ޱ�
	/*
		�߰�
		scanf : ���� �Ǵ� ���๮�ڴ� ������� ����
		fgets : ����� ���๮�� ��� �����
	*/

	// ���ڿ����� ������ ���� ���� ����
	// ! strcspn(destination arr, ã�� ����) => ã�� ���ڰ� �ִ� �ε��� ��ȯ
	str[strcspn(str, "\n")] = '\0';

	// stack ���� ����ǥ��� ���� ����
	int* stack = (int*)malloc(sizeof(int) * 1000);
	int stackIndex = -1;
	int a, b; // �ǿ����� ����
	int result; // ���� ��� ����
	int i = 0;
	int temp; // ���ڸ� ���ڷ� �ٲٰ� �������� Ȯ���ϱ� ���� temp ����

	while (1) {
		if (str[i] != 32) { // ����� ��� ����(space)�� ��� �ڵ� �� 32 üũ
			temp = str[i] - '0'; // ���ڸ� ���ڷ� ��ȯ

			if (temp >= 0 && temp <= 9) { // str �� ���ڰ� ������ ���� push
				push(stack, &stackIndex, temp);
			}
			else { // str �� ���ڰ� ���ڰ� �ƴ� ���� (������) stack ���� 2�� ���� 
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