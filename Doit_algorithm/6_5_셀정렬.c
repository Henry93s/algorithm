// 셀 정렬: 정렬한 요소를 나눠 각 그룹 별로 단순 삽입 정렬을 수행하고, 각 그룹을 합치면서 정렬 반복
// => 효과 : 요소의 swap 횟수를 줄일 수 있음.
#include <stdio.h>
#include <stdlib.h>
void shell(int* arr, int index) {
	int i, j;
	int temp;
	
	// (1) 4 정렬 수행
	for (i = 0;i < index / 2;i++) {
		if (*(arr + i) > *(arr + index / 2 + i)) {
			temp = *(arr + i);
			*(arr + i) = *(arr + index / 2 + i);
			*(arr + index / 2 + i) = temp;
		}
	}
	for (i = 0;i < index;i++) {
		printf("%d ", *(arr + i));
	}
	printf("\n\n");


	// (2) 2 정렬 수행
	int cnt = 0;
	int p;
	for (i = 0;cnt < index / 2;i += 2, cnt++) {
		if (*(arr + i) > *(arr + i + 2)) {
			temp = *(arr + i);
			*(arr + i) = *(arr + i + 2);
			*(arr + i + 2) = temp;
		}

		for (p = 0;p < index;p++) {
			printf("%d ", *(arr + p));
		}
		printf("\n");

	}



	return;
}

int main() {
	int* arr = (int*)malloc(sizeof(int) * 8);
	for (int i = 0;i < 8;i++) {
		scanf_s("%d", arr + i);
	}
	shell(arr, 8);
	return 0;
}
