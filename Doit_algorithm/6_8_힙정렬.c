#include <stdio.h>
#include <stdlib.h>
void swap(int* arr, int x, int y) {
	int temp = *(arr + x);
	*(arr + x) = *(arr + y);
	*(arr + y) = temp;
}
void heapSort(int* arr, int r, int n) {
	// 재귀 종료 조건 : heap 배열에 root 만 남았을 때 정렬 완료
	if (n == 1) {
		return;
	}

	int lastParent = (n / 2) - 1; // heapify 시작 지점
	int maxIndex;
	
	// 최대 힙 구성 (Bottom-up)
	if (r == 0) {
		// bottom-up 이므로 root 까지 올라가면서 자식들 중 최대 값을 구해 부모와 비교하여 필요 시 swap
		for (int i = lastParent; i >= r;i--) {
			if (2 * i + 1 <= n - 1 && 2 * i + 2 <= n - 1) {
				if (*(arr + 2 * i + 1) >= *(arr + 2 * i + 2)) {
					maxIndex = (2 * i + 1);
				}
				else {
					maxIndex = (2 * i + 2);
				}
			}
			else if (2 * i + 1 <= n - 1) {
				maxIndex = (2 * i + 1);
			}

			if (*(arr + maxIndex) > *(arr + i)) {
				swap(arr, i, maxIndex);
			}
		}
	}
	else { // top-down 깨진 heap 체크 파트
		// 부분 heap 의 시작점(i : like root) 에서 부터 자식이 있는 부모까지 내려가면서 heap 구성
		int i = lastParent;

		while (2 * i + 1 <= n - 1 || 2 * i + 2 <= n - 1) {
			if (2 * i + 1 <= n - 1 && 2 * i + 2 <= n - 1) {
				if (*(arr + 2 * i + 1) >= *(arr + 2 * i + 2)) {
					maxIndex = (2 * i + 1);
				}
				else {
					maxIndex = (2 * i + 2);
				}
			}
			else if (2 * i + 1 <= n - 1) {
				maxIndex = (2 * i + 1);
			}

			if (*(arr + maxIndex) > *(arr + i)) {
				swap(arr, i, maxIndex);
			}
			i++;
		}
	}

	// 최대 힙 완성(확인 완료)
	printf("최대힙 완성 직후\n");
	for (int i = 0;i < 5;i++) {
		printf("%d ", *(arr + i));
	}
	printf("\n");
	// root 를 마지막 leaf 와 교체
	swap(arr, 0, n - 1);
	printf("swap 후 정리 체크\n");
	for (int i = 0;i < 8;i++) {
		printf("%d ", *(arr + i));
	}
	printf("\n");

	// 마지막 leaf 를 제외한 원소들로 다시 heap 구성(오름차순)
	heapSort(arr, 0, n - 1); 
}
int main() {
	int N;
	scanf_s("%d", &N);
	int* arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0;i < N;i++) {
		scanf_s("%d", arr + i);
	}
	heapSort(arr, 0, N);
	for (int i = 0;i < N;i++) {
		printf("%d ", *(arr + i));
	}
	return 0;
}