// 단순 삽입 정렬 : 선택한 요소를 그보다 더 앞쪽의 알맞은 위치에 삽입하고 밀어내는 작업을 반복하여 정렬
#include <stdio.h>
#include <stdlib.h>
void insertion(int* arr, int index) {
	int i, j;
	int temp;
	int minIndex;

	for (i = 1;i < index;i++) {
		// 1. 시작 요소(두 번째) 와 비교를 시작하는 첫 요소를 min 값으로 지정
		// 2. 시작 요소부터 정렬되지 않은 위치까지의 요소를 비교하고 가장 작은 값을 min 값으로 변경
		// 3. 가장 작은 값의 min 을 각 반복문의 정렬이 되지 않은 첫 위치 값과 swap
		// 4. 나머지 값을 오른쪽 shift
		minIndex = i - 1; // (1)
		for (j = i + 1;j < index;j++) {
			if (*(arr + i) < *(arr + minIndex)) {
				minIndex = i; // (2)
			}
		}


	}
}