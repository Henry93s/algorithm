// ť(queue) : ���� ���� �����Ͱ� ���� ��µȴ�. -> ���Լ���
// ����(stack) (review) : ���߿� ���� �����Ͱ� ���� ��µȴ�. -> ���Լ���
#include <stdio.h>
#include <stdlib.h>
void enqueue(int* queue, int* enqueueIndex, int* queueCnt, int data) {
	queue[++(*enqueueIndex)] = data;
	(*queueCnt)++;
	return;
}
// dequeue : ť�� ù��° �ε������� Ȯ���Ѵ�. ( ���Լ��� )
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
	int N; // ť ��� ����
	scanf_s("%d", &N);
	while (getchar() != '\n'); // ���� ��� Ŀ�ǵ� �ޱ� ���� ���ۿ� �����ִ� ���๮�� ����

	int* queue = (int*)malloc(sizeof(int) * N); 
	// ť ���̴� ���� �� ���� ��쿡�� �ִ� 7 ��(��ɾ� ��)�� ���Ҹ� ����ϴ�.
	int enqueueIndex = -1;
	int dequeueIndex = -1;

	int i;
	char op; int data; // op : ť ��� Ŀ�ǵ�, data : enqueue �� ���� ������
	int dequeueData;
	int queueCnt = 0; // ���� queue �� ����ִ� ����� ����
	for (i = 0;i < N;i++) {
		scanf_s(" %c", &op, 1); 
		// !! scanf �Է� ���� ���� ���ڸ�(����, ��, ����) ����

		if (op == 'i') {
			scanf_s("%d", &data); // �� 38 line ���� �̹� ���� ���ڵ��� ����
			// �ϹǷ� �߰��� while(getchar() != '\0'); �ڵ带 ���� �ʾƵ� ��! 
			enqueue(queue, &enqueueIndex, &queueCnt, data);
		}
		else if (op == 'c') {
			// ��� ������ �ϳ��� ���� ���� �־����� �ʴ´�.(���� ����)
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