#include <stdio.h>
// for 반복문으로 입력 받을 수 10억정도까지 실행 시 문제 제한 시간 1초를 초과하게 된다.
// -> 수정 필요 : 약수를 구할 때 제곱근을 이용
// a * b = n (a > 1, b > 1) 일 때 a 와 b는 n 의 약수이다.
// --> a 와 b 중 작은 수 쪽만 확인해도 n 이 합성수임을 알 수 있음
/*
void isPrime(int n) {
	int i;
	int cnt = 0;
	for (i = 1;i <= n;i++) {
		if (n % i == 0) {
			cnt++;
		}
	}
	if (cnt == 2) {
		printf("prime number\n");
	}
	else if (cnt == 1) {
		printf("number one\n");
	}
	else {
		printf("composite number \n");
	}
}
*/
void isPrime(int n) {
	if (n < 2) { 
		printf("number one\n");
		return;
	}
	for (int i = 2;i <= n / i;i++) {
		if (n % i == 0) {
			printf("composite number \n");
			return;
		}
	}
	printf("prime number\n");
	return;
}
int main() {
	int n;
	int arr[5];
	for (int i = 0;i < 5;i++) {
		scanf_s("%d", &arr[i]);
		isPrime(arr[i]);
	}
	return 0;

}