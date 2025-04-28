#include <stdio.h>
void LeftSide(int n) { // 왼쪽 정렬 뒤집힌 삼각형 출력 함수
	int i, j;
	for (i = 0;i < n;i++) {

	}

}
void RightSide(int n) { // 오른쪽 정렬 삼각형 출력함수 (LeftSide 에서 중앙 * print함)
	int i, j;

}
int main() {
	int n;
	scanf_s("%d", &n);

	if (n < 1 || n > 100 || n % 2 != 0) {
		printf("INPUT ERROR!\n"); // 주어진 정수가 100이하의 양의 정수가 아닐 때 에러 출력 및 프로그램 종료
	}
	else {
		LeftSide(n);
		RightSide(n);
	}

	return 0;
}