#include <stdio.h>
#include <stdlib.h>
// 선택 정렬 시간복잡도 : O(n2)
// 주어진 수열에서 최소값을 찾고 해당 수열의 맨 앞의 값과 자리를 바꾼 후,
// 맨 앞의 값을 뺀 나머지 수열을 같은 방법으로 반복 실행
int main() {
	int n; // 수열의 길이 n
	scanf_s("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);

	int i; // 수열 데이터 입력
	for (i = 0;i < n;i++) {
		scanf_s("%d", &arr[i]);
	}

	int j;
	int temp; // 찾은 최소값과 나머지 수열 맨 앞의 값 swap
	int k, min_index; // 정렬 각 과정마다 출력을 위한 k
	// 남은 수열에서 찾은 최소값의 수열 인덱스 min_index
	for (i = 0;i < n - 1;i++) { // 남은 수열에서 최소값을 찾는 비교 시 맨 마지막 한 개 남았을 때는 비교가 불필요함 : n - 1
		min_index = i;
		for (j = i;j < n;j++) {
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
		
		for (k = 0; k < n;k++) { // 정렬과정의 각 단계별 결과를 출력한다.
			printf("%d ", arr[k]);
		}
		printf("\n");
	}

	return 0;
}