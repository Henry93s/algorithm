#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, k; // 자연수 n 과 k 선언
	scanf_s("%d %d", &n, &k); 
	int* div_arr = (int*)malloc(sizeof(int) * n); // n 개의 길이의 1차원 동적할당 배열 선언 및 초기화
	int div_arrcnt = 0; // 배열의 인덱스 컨트롤 변수
	int i;
	for (i = 0;i < n;i++) {
		if (i != 0 && n % i == 0) { // n 까지 순차적으로 순회하면서 약수임을 판단하고
			// 약수일 경우 약수 1차원 동적할당 배열에 차례로 값을 저장
			div_arr[div_arrcnt] = i;
			div_arrcnt++;
		}
	}
	printf("%d", div_arr[k - 1]); // 약수가 저장된 배열에 따라 k 번째로 작은 약수를 출력하려면 k - 1 인덱스 값으로 출력

	free(div_arr);
	return 0;
}