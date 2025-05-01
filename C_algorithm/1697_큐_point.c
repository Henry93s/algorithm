// 큐(queue) : 먼저 들어온 데이터가 먼저 출력된다. -> 선입선출
// 스택(stack) (review) : 나중에 들어온 데이터가 먼저 출력된다. -> 후입선출
#include <stdio.h>
#include <stdlib.h>
void enqueue(int* queue, int* enqueueIndex, int* queueCnt, int data) {
	queue[++(*enqueueIndex)] = data;
	(*queueCnt)++;
	return;
}
// dequeue : 큐의 첫번째 인덱스부터 확인한다. ( 선입선출 )
int dequeue(int* queue, int* dequeueIndex, int* queueCnt) {
	int deqData;
	if (*queueCnt == 0) {
		return -1;
	}
	else { 
		deqData = queue[++(*dequeueIndex)];
		(*queueCnt)--;
		return deqData;
	}
}

int main() {
	int N; // 큐 명령 개수
	scanf_s("%d", &N);
	while (getchar() != '\n'); // 다음 명령 커맨드 받기 전에 버퍼에 남아있는 개행문자 제거

	int* queue = (int*)malloc(sizeof(int) * N); 
	// 큐 길이는 가장 길 때의 경우에도 최대 7 개(명령어 수)의 원소면 충분하다.
	int enqueueIndex = -1;
	int dequeueIndex = -1;

	int i;
	char op; int data; // op : 큐 명령 커맨드, data : enqueue 일 때의 데이터
	int dequeueData;
	int queueCnt = 0; // 현재 queue 에 들어있는 요소의 개수
	for (i = 0;i < N;i++) {
		scanf_s(" %c", &op, 1); 
		// !! scanf 입력 전에 공백 문자를(공백, 탭, 개행) 무시

		if (op == 'i') {
			scanf_s("%d", &data); // 위 38 line 에서 이미 공백 문자들을 무시
			// 하므로 추가로 while(getchar() != '\0'); 코드를 넣지 않아도 됨! 
			enqueue(queue, &enqueueIndex, &queueCnt, data);
		}
		else if (op == 'c') {
			// 출력 내용이 하나도 없는 경우는 주어지지 않는다.(문제 조건)
			printf("%d\n", enqueueIndex - dequeueIndex);
		}
		else { // op == 'o'
			dequeueData = dequeue(queue, &dequeueIndex, &queueCnt);
			if (dequeueData == -1) {
				printf("empty\n");
			}
			else {
				printf("%d\n", dequeueData);
			}
		}
	}

	return 0;
}