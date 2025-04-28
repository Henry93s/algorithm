#include <stdio.h>
#include <stdlib.h>
int main() {
	int n;
	scanf("%d", &n); // n 개의 정수를 입력받음
	int* arr = (int*)malloc(sizeof(int) * n); // n 개의 길이인 1차원 동적배열 할당 및 초기화
	int i, j;
	for (i = 0;i < n;i++) {  // 입력받은 정수들 중 최대 공약수와 최소공배수를 찾기위해 정수들을 입력받음
		scanf("%d", &arr[i]);
	}

	int max = arr[0]; // max 값 판단을 위한 값 정의와 값 적용까지(for)
	for (i = 0;i < n;i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	int break_control; // 최대공약수를 확인하고 나서 break_control 에 따라 
	// 최대공약수가 확인될 때마다 최대공약수를 계속해서 교체
	int maxdiv = 1;
	for (i = 2;i <= max;i++) { // 최대공약수 find case
		break_control = 0;
		for (j = 0;j < n;j++) {
			if (arr[j] % i == 0) {
				break_control = 1;
			}
			else {
				break_control = 0;
				break;
			}
		}
		if (break_control == 1) {
			maxdiv = i;
		}
	}

	int minmul = max;
	int arr_max = -1; // max 값 판단을 위한 값 정의와 값 적용까지(for)
	for (i = 0;i < n;i++) {
		if (arr[i] > arr_max) {
			arr_max = arr[i];
		}
	}

	// 최소공배수를 확인하고 나서 break_control 에 따라 
	// 최대공배수가 확인되면 최대공약수를 교체하고 바로 break 로 반복문 탈출
	for (i = arr_max; ;i++) {
		break_control = 0;
		for (j = 0;j < n;j++) {
			if (i % arr[j] == 0) {
				break_control = 1;
			}
			else {
				break_control = 0;
				break;
			}
		}
		if (break_control == 1) {
			minmul = i;
			break;
		}
	}

	printf("%d %d", maxdiv, minmul);

	return 0;
}