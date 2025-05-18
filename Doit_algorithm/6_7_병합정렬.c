#include <stdio.h>
#include <stdlib.h>
void swap(int* arr, int x, int y) {
	int temp = *(arr + x);
	*(arr + x) = *(arr + y);
	*(arr + y) = temp;
}
// merge : 모든 재귀("분할") 이 끝나고 병합 작업을 수행한다.
void merge(int* arr, int left, int mid, int right) {
	// 대소 비교 후 담을 임시 배열 및 배열 인덱스 관리 변수 생성
	// 
	// 오답 노트 1 : 임시 배열 크기는 right - left + 1 갯수 파악
	int* tempArr = (int*)malloc(sizeof(int) * (right - left + 1));
	int tempIndex = 0;
	// left, right 는 별도의 인덱스 관리 변수 생성
	int leftIndex = left;
	int rightIndex = mid + 1;

	// 왼쪽과 오른쪽 데이터의 비교 진행 -> 우선순위 값을 tempArr 앞에 배치
	while (leftIndex <= mid && rightIndex <= right) {
		if (*(arr + leftIndex) < *(arr + rightIndex)) {
			*(tempArr + tempIndex) = *(arr + leftIndex);
			leftIndex++; 
		} else {
			*(tempArr + tempIndex) = *(arr + rightIndex);
			rightIndex++;
		}
		tempIndex++;
	}

	// 위에서 break 되었을 때 아직 남아있는 잔여 원소를 tempArr 에 넣어 병합 정렬을 완성함
	while (leftIndex <= mid) {
		*(tempArr + tempIndex) = *(arr + leftIndex);
		leftIndex++; tempIndex++;
	}
	while (rightIndex <= right) {
		*(tempArr + tempIndex) = *(arr + rightIndex);
		rightIndex++; tempIndex++;
	}

	// debugging code
	int tempStart = 0;
	for (int i = tempStart;i < tempIndex;i++) {
		printf("%d ", *(tempArr + i));
	}
	printf("\n");

	// 정렬된 임시 배열을 arr 기존 배열에 복사
	// 
	// 오답 노트 2 : merge 함수 인자를 확인 시 시작점이 left 이므로 
	//				 arr 의 0 이 아닌, 시작점은 left 에 복사를 시작해야함!!
	for (int i = tempStart;i < tempIndex;i++) {
		*(arr + left + i) = *(tempArr + i);
	}
}


// mergeSort 데이터의 분할 후 정복이므로 해당 함수에는 재귀("분할") 작업을 정의
void mergeSort(int* arr, int left, int right) {
	// 재귀 함수 종료 조건 : 데이터 묶음이 2개 이상일 때 계속 분할 및 정복
	if (left < right) {
		// 중간 분할 지점 mid 정의
		int mid = left + (right - left) / 2;

		// 왼쪽, 오른쪽 부분 모두 mid 지점을 기준으로 쪼개서 분할(재귀) 수행
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		// 분할 작업이 모두 종료되어 재귀 -> 되돌아오면 병합 시작
		// 병합 방향 : 밑에서부터 위라고 생각)
		merge(arr, left, mid, right);
	}
}

int main() {
	int N;
	printf("입력받을 원소의 개수 : ");
	scanf_s("%d", &N);
	int* arr = (int*)malloc(sizeof(int) * N);

	printf("%d 개 원소 입력(공백 구분): ", N);
	for (int i = 0;i < N;i++) {
		scanf_s("%d", arr + i);
	}

	mergeSort(arr, 0, N - 1);

	for (int i = 0;i < N;i++) {
		printf("%d ", *(arr + i));
	}

	free(arr);
	return 0;
}