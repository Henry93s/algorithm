#include <stdio.h>
void danPrint(int n, int m) {
	if (n == 10) { // 9단까지 끝나면 종료
		return;
	}
	if (m == 10) { // 하나의 단이 끝나면 개행문자를 넣고 단을 올려서 재귀
		printf("\n");
		danPrint(n + 1, 1); // 다음 단 재귀함수 호출
	}
	printf("%d * %d = %d\n", n, m, n * m);
	danPrint(n, m + 1); // 현재 단에서 다음 곱할 피연산자 적용 후 재귀함수 호출
}

int main() {
	danPrint(2, 1); // 2 * 1 부터 출력하기 위한 구구단 재귀함수 호출

	return 0;
}