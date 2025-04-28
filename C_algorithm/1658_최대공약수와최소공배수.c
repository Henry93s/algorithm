#include <stdio.h>
int main() {
	int a, b;
	scanf("%d %d", &a, &b); // 두 개의 자연수 변수 선언 및 입력

	int i;
	int small, big; // 두 개의 자연수 중 작은 수와 큰 수 변수 선언
	int maxdiv, minmul; // 최대공약수와 최소공배수 변수 선언
	a > b ? (small = b, big = a) : (small = a, big = b);
	// 작은 수와 큰 수를 구분 후 변수에 저장

	for (i = 1;i <= small;i++) { // 두 자연수 중 작은 수까지 증가하면서 
		if (small % i == 0 && big % i == 0) { // 두 자연수가 i 로 나눠질 경우 계속 최대공약수를 교체
			maxdiv = i;
		}
	}
	for (i = big;i <= a * b;i++) { // 두 자연수의 곱까지 증가하면서 
		if (i % a == 0 && i % b == 0) { // i 가 a 또는 b 로 모두 나눠질 경우 최소공배수로 저장하고 break;
			minmul = i;
			break; // 최소공배수이므로 한 번만 저장하고 바로 break;
		}
	}

	printf("%d\n%d\n", maxdiv, minmul);
	return 0;
}