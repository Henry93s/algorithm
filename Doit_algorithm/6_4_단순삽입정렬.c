// 단순 삽입 정렬 : 아직 정렬되지 않은 부분의 첫 번째 요소를 정렬된 부분과 비교하여 뒤로 밀면서 알맞은 위치 찾기
// swap 과정이 불필요하나, shift 이동 과정이 필요함.
// 평균 O(n^2) 시간 복잡도
// 어느 정도 정렬이 되어 있는 요소들에 한해서 o(n) 에 가까운 시간복잡도로 구현이 가능함
#include <stdio.h>
#include <stdlib.h>
void insertion(int* arr, int index) {
	int i, j, k;
	int key;

	// 1. 자료의 모든 요소를 앞에서부터 반복문 진행
	// 2. 아직 정렬되지 않은 부분의 첫 번째 요소 인덱스를 key 값으로 지정
	// 3. 비교 시작점부터 첫 번째 요소까지 비교하면서 요소들을 뒤로 shift, 알맞은 위치에서는 insertion
	for (i = 0;i < index;i++) { // (1)
		key = *(arr + i); // (2)
		for (j = i;j > 0 && *(arr + j - 1) > key;j--) { // 앞쪽 요소(j - 1)가 더 클 동안 계속 뒤로 shift
			*(arr + j) = *(arr + j - 1); // 뒤로 shift
		}
		// 앞쪽 요소(j - 1)가 더 작거나 같으면 j 인덱스에 key 값을 삽입
		*(arr + j) = key;

		for (k = 0;k < index;k++) {
			printf("%d ", *(arr + k));
		}
		printf("\n");
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

	printf("\n");
	for (i = 0;i < 7;i++) {
		printf("%d ", *(arr + i));
	}

	return 0;
}

