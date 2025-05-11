// 퀵 정렬 : 그룹을 나누는 기준인 "피벗(pivot)" 을 기준으로 각 그룹 요소가 1개가 될 때까지 분할 및 정렬을 수행한다.
/*
	피벗(pivot) : 피벗은 마음대로 선택할 수 있으나 어떤 피벗을 선택했는지에 따라 분할 또는 정렬 속도에 영향을 미침
	
	[분할 및 정렬 흐름 - 오름차순 기준]
	1. 각 '그룹의 중앙에 위치한 요소' 로 피벗을 설정
	2. 각 그룹의 left, right 인덱스 지정.
	3. left index 부터 left 값이 피벗보다 작으면 계속 진행(++)하고, 크거나 같으면 멈춤;
	4. right index 부터 right 값이 피벗보다 크면 계속 진행(--), 작거나 같으면 멈춤;
	5. 피벗 포인터가 교차하지 않았을 때(pl <= pr) 그룹의 left 값과 right 값을 swap 하고, pl, pr 포인터를 한 칸씩 이동
	6. 교차했을 때(pl > pr), 해당 그룹을 두 그룹으로 나누고, 각 그룹 내 원소가 1개가 될 때까지 quick 함수 재귀 호출 수행)
*/
#include <stdio.h>
#include <stdlib.h>
void quick(int* arr, int left, int right) {
	int pivot = (left + right) / 2; // 1. 각 '그룹의 중앙에 위치한 요소' 로 피벗을 설정
	int pl = left, pr = right; // 2. 각 그룹의 left, right 인덱스 지정.

	// quick sort 부분 동작 확인하기
	for (int i = left; i <= right;i++) {
		printf("%d ", *(arr + i));
	}
	printf("\n");

	while (pl <= pr) {
		// 3. left index 부터 left 값이 피벗보다 작으면 계속 진행(++)하고, 크거나 같으면 멈춤;
		while (*(arr + pl) < *(arr + pivot)) {
			pl++;
		}
		// 4. right index 부터 right 값이 피벗보다 크면 계속 진행(--), 작거나 같으면 멈춤;
		while (*(arr + pr) > *(arr + pivot)) {
			pr--;
		}
		
		// 5. 피벗 포인터가 교차하지 않았을 때(pl <= pr) 그룹의 left 값과 right 값을 swap 하고, pl, pr 포인터를 한 칸씩 이동
		// 교차했을 때에도 swap 이 발생할 경우 이미 정렬된 구간을 깨뜨릴 수 있음.
		if (pl <= pr) {
			int temp = *(arr + pl);
			*(arr + pl) = *(arr + pr);
			*(arr + pr) = temp;
			pl++;
			pr--;
		}
	}

	// 6. 교차했을 때(pl > pr), 해당 그룹의 정렬 작업 종료. 
	// 이후 왼쪽 그룹과 오른쪽 그룹을 계속 divide 하여 정렬하기 위한 재귀 호출
	if (left < pr) {
		quick(arr, left, pr);   // 왼쪽 부분 정렬
	}
	if (pl < right) {
		quick(arr, pl, right); // 오른쪽 부분 정렬
	}
}

int main() {
	int N;
	scanf_s("%d", &N);
	int* arr = (int*)malloc(sizeof(int) * N);
	for (int i = 0; i < N;i++) {
		scanf_s("%d", (arr + i));
	}

	quick(arr, 0, N - 1);

	printf("\n\n");
	for (int i = 0; i < N;i++) {
		printf("%d ", *(arr + i));
	}

	return 0;
}
