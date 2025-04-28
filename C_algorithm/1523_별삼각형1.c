#include <stdio.h>
void PrintTriangle(int n, int m) {
	int i, j;

	switch (m)
	{
	case 1: // 좌측 정렬 삼각형 출력
		for (i = 0;i < n;i++) {
			for (j = 0;j < i + 1;j++) {
				printf("*");
			}
			for (j = 0;j < n - i + 1;j++) {
				printf(" ");
			}
			printf("\n");
		}
		break;
	case 2: // 좌측 정렬 역삼각형 출력
		for (i = 0;i < n;i++) {
			for (j = 0;j < n - i;j++) {
				printf("*");
			}
			for (j = 0;j < i;j++) {
				printf(" ");
			}
			printf("\n");
		}
		break;
	case 3: // 중앙 정렬 삼각형 출력
		for (i = 0;i < n;i++) { 
			for (j = 0;j < n - i - 1;j++) { // 좌측 공백 부분
				printf(" ");
			}
			for (j = 0;j < 2 * i + 1;j++) { // 중앙 * 부분
				printf("*");
			}
			for (j = 0;j < n - i - 1;j++) { // 우측 공백 부분
				printf(" ");
			}
			printf("\n");
		}
		break;
	default:
		break;
	}
}
int main() {
	int n; // 삼각형의 높이 n
	int m; // 출력할 별삼각형의 종류 CASE 변수 m

	scanf_s("%d %d", &n, &m);
	if (n < 0 || n > 100 || m < 1 || m > 3) { // 삼각형 크기와 종류 값 범위에 일치하지 않을 경우 에러 로그 출력
		printf("INPUT ERROR!");
	}
	else {
		PrintTriangle(n, m); // 종류 m 에 따라 출력하는 함수 호출
	}

	return 0;
}