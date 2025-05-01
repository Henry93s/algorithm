#include <stdio.h>
#include <stdlib.h>

// shuffle : N 카드 수를 매개변수로 받고 
// 홀수 번째(0, 2...) 인덱스 카드는 그대로 둔다.(플레이어에게 주는 효과)
// 짝수 번째(1, 3...) 인덱스 카드는 카드 배열의 맨 뒤 보내고
// 이후 값들을 앞으로 땡겨온다. 단, 플레이어에게 주지는 않았음.
void init(int* card, int N) { // 처음 카드 배열이 만들어짐
	int i;
	// 첫 init 은 모두 -1 로 하여 최종 결과에는 -1 인 요소는 출력 X
	for (i = 0;i < N * 2;i++) {
		card[i] = -1;
	}
	// 실제 카드 요소 init
	for (i = 0;i < N;i++) {
		card[i] = i + 1;
	}
	return;
}
void shuffle(int* card, int N) {
	int i;
	int shuffledIndex = N; // 뒤로 보내질 초기의 인덱스를 N 으로 설정
	// 그리고, 보내질 때마다 보내질 인덱스를 + 1 씩 늘린다.
	int nullNum = -1; // 카드는 1부터 써져있으므로 빈 공간은 -1 로 구분한다.

	for (i = 0;i < N * 2;i++) {
		if ((i + 1) % 2 == 1) {}// 홀수 번째 인덱스 요소 는 그대로 둔다.
		else { // 짝수 번째 인덱스 : 카드 배열의 맨 뒤 인덱스 요소와 swap
			if (i != N * 2 - 1) { // 마지막 인덱스 요소는 넘기지 않는다.
				card[shuffledIndex] = card[i]; // 배열의 맨 뒤로 보냄
				shuffledIndex++;
				card[i] = -1; // 버려진 공간은 -1 로 예외 처리한다.
			}
		}
	}

	return;
}

int main() {
	int N;
	scanf_s("%d", &N); // 1 <= N <= 100 범위
	int* card = (int*)malloc(sizeof(int) * (N * 2));
	// N * 2 = 기본 N 의 개수와 맨 뒤로 보내지는 횟수를 계산해서 여유 인덱스 추가

	// card 배열을 초기화 한다.
	init(card, N);
	// shuffle 을 동작한다. 
	shuffle(card, N);

	// shuffle 후 결과 카드 배열 출력
	int k;
	for (k = 0;k < N * 2;k++) {
		if (card[k] != -1) { // 이동되거나 버려진 인덱스 요소는 -1 처리한다.
			printf("%d ", card[k]);
		}
	}
	
	return 0;
}