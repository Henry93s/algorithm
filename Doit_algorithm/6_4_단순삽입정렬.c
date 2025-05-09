// 단순 삽입 정렬 : 자료 배열의 첫 비교 시작점까지 차례대로 이미 정렬된 배열 부분과 비교 후 삽입
// 선택 정렬보다 swap 발생이 많음.
// 단, 어느 정도 정렬이 되어 있는 요소들에 한해서 o(n) 시간복잡도로 구현이 가능함
#include <stdio.h>
#include <stdlib.h>
void insertion(int* arr, int index) {
	int i, j;
	int temp;

	// 1. 자료의 모든 요소를 앞에서부터 반복문 진행
	// 2. 비교 시작점 + 1 부터 첫 번째 요소까지 차례대로 이미 정렬된 배열 부분과 비교 후 swap 진행 
	for (i = 0;i < index - 1;i++) { // (1)
		for (j = i + 1;j > 0;j--) { // (2) 
			if (*(arr + j) < *(arr + (j - 1))) {
				temp = *(arr + j);
				*(arr + j) = *(arr + (j - 1));
				*(arr + (j - 1)) = temp;
			}
		}
	}

	return;
}

int main() {
	int* arr = (int*)malloc(sizeof(int) * 7);
	int i;
	 
	for (i = 0;i < 7;i++) {
		scanf_s("%d", arr + i);
	}

	insertion(arr, 7);

	for (i = 0;i < 7;i++) {
		printf("%d ", *(arr + i));
	}

	return 0;
}

