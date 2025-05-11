// 버블 정렬 : 이웃한 두 요소의 대소 관계를 비교하여 교환을 반복함.
// 평균 O(n^2) 시간 복잡도
#include <stdio.h>
#include <stdlib.h>
void bubbleSort(int* arr, int index) {
	int i, j;
	int temp;
	printf("\n");
	for (i = index - 1;i > 0;i--) { 
		// 2중 반복문 구성 : 단일 for 문 이였을 경우 스왑 직후에 대한 그 다음 swap 이 발생하지 않을 수 있음
		for (j = i;j > 0;j--) {
			if (*(arr + j) < *(arr + j - 1)) { // 이웃한 두 요소를 비교하고 swap 진행
				temp = *(arr + j);
				*(arr + j) = *(arr + j - 1);
				*(arr + j - 1) = temp;
			}
		}

		for (int k = 0;k < 7;k++) {
			printf("%d ", *(arr + k));
		}
		printf("\n");
	}
}

int main() {
	int* arr = (int*)malloc(sizeof(int) * 7);
	for (int i = 0;i < 7;i++) {
		scanf_s("%d", arr + i);
	}

	bubbleSort(arr, 7);

	for (int i = 0;i < 7;i++) {
		printf("%d ", *(arr + i));
	}
	printf("\n");

	free(arr);
	return 0;
}