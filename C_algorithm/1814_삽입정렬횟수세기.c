// 버블 정렬 시간복잡도 : O(n2)
// 계속 수열의 처음부터 두 인접한 원소를 비교하여 자리를 바꾸는 과정을 반복하는 정렬
#include <stdio.h>
#include <stdlib.h>
int MoveInsertionCnt(int arr[], int n) {
	int i, j, temp;
	int cnt = 0; // cnt : 삽입정렬이 수행되어 밀어내는 이동이 발생할 때 정렬 통틀어서
	// 총 몇 번 이동했는지에 대한 변수
	int k;
	for (i = 1;i < n;i++) {
		for (j = i;j > 0;j--) {
			if (arr[j] < arr[j - 1]) {
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;

				cnt += j - (j - 1);
			}
		}
	}
	return cnt;
}
int main() {
	int n;
	scanf_s("%d", &n);

	int* arr = (int*)malloc(sizeof(int) * n);
	int i;
	for (i = 0;i < n;i++) {
		scanf_s("%d", arr + i);
	}
	printf("\n");

	printf("%d\n", MoveInsertionCnt(arr, n));
	return 0;
}