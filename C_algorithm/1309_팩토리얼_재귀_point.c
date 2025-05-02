#include <stdio.h>
// 문제에서 결과 값이 int 범위가 넘을 경우 long long 사용
long long factorial(int n) {
	if (n == 0) {
		return 1; // 1 을 반환해야 이전에 반환된 결과들을
		// 계속 곱할 수 있다.
		// 재귀함수는 최종 return 이후 '스택' 과 같이 후입선출의 개념으로
		// 후입선출 데이터들을 가져와서 동작을 수행한다.
	}
	else {
		if (n != 1) {
			printf("%d! = %d * %d!\n", n, n, n - 1);
		}
		else {
			printf("%d! = %d\n", n, n);
		}
		// 재귀 함수 호출
		return n * factorial(n - 1);
	}
}
int main() {
	int n; 
	scanf_s("%d", &n);

	// 문제에서 결과 값이 int 범위가 넘을 경우 long long 사용
	printf("%lld", factorial(n)); // long long 변수 출력시 서식문자 %lld 사용
	return 0;
}