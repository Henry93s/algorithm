// 단순 선택 정렬 : 요소들 중에서 가장 작은 값을 찾고 이를 알맞은 위치로 옮겨서 정렬
// 삽입 정렬보다 swap 발생이 적음
#include <stdio.h>
#include <stdlib.h>
void selectionSort(int* arr, int index) {
	int i, j;
	int min, minIndex;
	int temp;

	// 1. 반복문의 첫 위치의 값을 min 으로 임의로 할당
	// 2. 이후 비교하여 min 보다 작은 값이 나올 경우 해당 값으로 min 을 교체
	// 3. 교체된 min 값을 반복문의 첫 위치 값과 swap
	for (i = 0;i < index;i++) {
		min = *(arr + i); // (1)
		minIndex = i; // (1)

		for (j = i + 1;j < index;j++) {
			if (*(arr + j) < min) {
				min = *(arr + j); // (2)
				minIndex = j; // (2)
			}
		}
		
		temp = *(arr + i); // (3)
		*(arr + i) = *(arr + minIndex); // (3)
		*(arr + minIndex) = temp; // (3)
	}
}

int main() {
	int* arr = (int*)malloc(sizeof(int) * 7);
	for (int i = 0;i < 7;i++) {
		scanf_s("%d", (arr + i));
	}

	selectionSort(arr, 7);

	for (int i = 0;i < 7;i++) {
		printf("%d ", *(arr + i));
	}

	return 0;
}