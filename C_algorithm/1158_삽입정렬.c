#include <stdio.h>
#include <stdlib.h>
// 구현 삽입정렬 시간복잡도 : O(n2)
// -> 자료 배열의 모든 요소를 앞에서부터 차례대로 이미 정렬된 배열 부분과 비교 후 삽입
int main() {
	int n;
	scanf_s("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	
	int i;
	for (i = 0;i < n;i++) {
		scanf_s("%d", arr + i);
	}

	int j, k;
	int temp;
	for (i = 1;i < n;i++) { // 수열의 끝에서 첫번째 인덱스까지 계속 비교하면서 최소값 swap
		for (j = i;j > 0;j--) {
			if (arr[j] < arr[j - 1]) {
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}

		for (k = 0;k < n;k++) {
			printf("%d ", arr[k]);
		}
		printf("\n");
	}

	return 0;
}