#include <stdio.h>
#include <stdlib.h>
void swap(int* arr, int a, int b) {
	int temp = *(arr + a);
	*(arr + a) = *(arr + b);
	*(arr + b) = temp;
}
void quickSort(int* arr, int left, int right) {
	// 피벗은 데이터 묶음의 첫 번째 원소로 지정
	int pivot = *(arr + left);
	int pivotIndex = left;
	// 매개변수로 받아온 시작, 끝점을 변수로 저장
	int leftStart = left;
	int rightStart = right;

	// 배열 좌우 포인터 정의
	int l = left + 1;
	int r = right;

	// left 와 right 가 엇갈릴 때까지 반복
	// "엇갈릴 때까지 반복 이유" : 엇갈리기 전까지 새로운 피벗 기준으로 작은 값 묶음과 큰 값 묶음을 "분할"&"정렬" 할 수 없다.
	while (l <= r) {
		// l 좌 포인터가 데이터 묶음 끝점보다 작거나 같고, 좌 포인터 배열 값이 피벗보다 작거나 같을 동안 우측으로 이동
		while (l <= right && *(arr + l) <= pivot) {
			l++;
		}
		// r 우 포인터가 데이터 묶음 끝점보다 크거나 같고, 우 포인터 배열 값이 피벗보다 크거나 같을 동안 좌측으로 이동
		while (r >= left + 1 && *(arr + r) >= pivot) {
			r--;
		}
		// "좌 포인터가 찾은 피벗보다 큰 값" 과 "우 포인터가 찾은 피벗보다 작은 값" swap 후 다시 엇갈릴 때까지 반복
		if (l < r) {
			swap(arr, l, r);
			l++;
			r--;
		}
	}

	// 엇갈렸을 때 "피벗을 기준"으로 피벗보다 "작은 값은 무조건 우 -> 좌로 이동한 우 포인터"
	swap(arr, pivotIndex, r); // 피벗을 swap 시 [분할] 작업이 완료
	// 디버깅 테스팅
	for (int i = leftStart; i <= rightStart; i++) {
		printf("%d ", *(arr + i));
	}
	printf("\n");

	// 분할 후 정렬할 왼쪽 데이터 묶음
	// "우 -> 좌 로 이동한 우 포인터" == "방금 swap 과정으로 pivotIndex" 와 같으므로 
	// 데이터 묶음 시작점이 "새로운 우 포인터" 보다 작으면, quickSort(arr, "새 좌 포인터", "새 우 포인터") 로 재귀 함수 호출
	if (leftStart < r - 1) {
		quickSort(arr, leftStart, r - 1);
	}
	// 분할 후 정렬할 오른쪽 데이터 묶음
	// "우 -> 좌 로 이동한 우 포인터" == "방금 swap 과정으로 pivotIndex" 와 같으므로 
	// "새로운 우 포인터" 가 데이터 묶음 끝점보다 작으면, quickSort(arr, "새 좌 포인터", "새 우 포인터") 로 재귀 함수 호출
	if (r + 1 < rightStart) {
		quickSort(arr, r + 1, rightStart);
	}
}

int main() {
	int N;
	printf("배열 데이터 개수: ");
	scanf_s("%d", &N);
	int* arr = (int*)malloc(sizeof(int) * N);
	
	printf("배열 요소 입력: ");
	for (int i = 0;i < N;i++) {
		scanf_s("%d", arr + i);
	}

	quickSort(arr, 0, N - 1);

	for (int i = 0;i < N;i++) {
		printf("%d ", *(arr + i));
	}

	free(arr);
	return 0;
}