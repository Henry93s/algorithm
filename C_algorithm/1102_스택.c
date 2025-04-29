// 스택 : 후입선출의 자료 구조(Last-In-Fast-Out)
#include <stdio.h>
#include <stdlib.h>
int main() {
	int n;
	scanf_s("%d", &n);

	int* arr = (int*)malloc(sizeof(int) * n); // 자료구조 공간 할당.
	// 스택의 최대 명령수가 100 이므로 모두 i(insert) 를 수행하더라도 공간이 부족하지 않음.
	int arrIndex = -1;
	int data;
	char op; // i, o, c 명령어

	for (int k = n;k > 0;k--) {
		scanf_s(" %c", &op); // 문자 scanf 시 %c 서식문자 앞에 공백을 주어 NULL 문자 버퍼 제거
		switch (op)
		{
		case 'i': // push
			scanf_s(" %d", &data);
			arr[++arrIndex] = data;
			break;
		case 'o': // pop
			if (arrIndex == -1) {
				printf("empty\n");
			}
			else {
				printf("%d\n", arr[arrIndex]);
				arrIndex--;
			}
			break;
		case 'c': // print cnt == arrIndex + 1
			printf("%d\n", arrIndex + 1);
			break;
		default:
			break;
		}
	}

	return 0;
}