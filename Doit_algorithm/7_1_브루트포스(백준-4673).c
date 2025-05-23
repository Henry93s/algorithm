#include <stdio.h>
#include <stdlib.h>

// 생성자가 없는 셀프 넘버 찾기
// 33 + 3 + 3 = 39 일 때, 33은 39 의 생성자
// 91 + 9 + 1 = 101, 100 + 1 + 0 = 101 으로, 101의 생성자는 91, 100 총 2개
// 셀프 넘버 : 생성자가 없는 숫자(ex. 1, 3, ... )
int numberCheck(int num) {
	int data = num;
	int sum = 0;
	sum += data;
	do {
		sum += (num % 10);
		num /= 10;
	} while (num > 0);
	//printf("%d\n", sum);
	return sum;
}
void makeNumberArr(int numArr[10001][2]) {
	int notSelfNum;
	for (int i = 1;i < 10000;i++) {
		notSelfNum = numberCheck(i);
		if (notSelfNum < 10000) {
			numArr[notSelfNum][1] = 1;
		}
	}
	return;
}
int main() {
	int numArr[10001][2] = { 0 };
	makeNumberArr(numArr);
	for (int i = 1;i < 10000;i++) {
		if (numArr[i][1] == 0) {
			printf("%d\n", i);
		}
	}
	
	return 0;
}
