#include <stdio.h>
#include <string.h>
int heightCalculate(char* arr) { // 길이 계산 함수
	int sum = 10; // 문제에서 문자열의 길이는 최소 3이상이므로 첫 번째는 무조건 10cm 로 시작
	int i;
	for (i = 1;i < strlen(arr);i++) { // strlen(arr) 은 공백문자이므로 제외하고 검사 진행
		if (arr[i - 1] == arr[i]) {
			sum += 5; // 이전 문자와 같은 괄호 문자일 때 포개지므로 += 5 연산
		}
		else {
			sum += 10; // 이전 문자와 다른 괄호 문자일 때는 포개지지 않으므로 += 10 연산
		}
	}
	return sum;
}
// ( 과 ) 로 이루어진 문자열을 받고, ( 또는 ) 은 10 으로 계산, (( 또는 )) 는 15로 계산한다.
// 문자열은 3이상 50이하. 최종 길이를 계산.
int main() {
	char arr[51]; // 문자열 변수 선언
	scanf_s("%s", arr, 51);

	printf("%d", heightCalculate(arr));

	return 0;
}