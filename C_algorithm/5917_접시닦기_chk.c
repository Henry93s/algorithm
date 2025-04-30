#include <stdio.h>
#include <stdlib.h>
void Wait(int* stack, int dish, int* index1) {
	stack[++(*index1)] = dish;
	return;
}
void Wash(int* stack1, int* stack2, int* index1, int* index2, int n) {
	int data = stack1[(*index1)--];
	stack2[++(*index2)] = data;
	return;
}
void Dry(int* stack2, int* stack3, int* index2, int* index3, int n) {
	int data = stack2[(*index2)--];
	stack3[++(*index3)] = data;
	return;
}
int main() {
	int n, t;
	scanf_s("%d %d", &n, &t);
	
	int* stack1 = (int*)malloc(sizeof(int) * n); // 대기 접시 스택 2는 테스트용
	int index1 = -1;
	int* stack2 = (int*)malloc(sizeof(int) * n); // 씻는 접시 스택
	int index2 = -1;
	int* stack3 = (int*)malloc(sizeof(int) * n); // 건조 접시 스택
	int index3 = -1;

	int i;
	for (i = n - 1;i >= 0;i--) {
		Wait(stack1, i + 1, &index1);
	} // wait 접시 셋팅 완료 -> 역순으로 삽입


	int cnt; // 1 또는 2 명령(wash 또는 dry 수행 횟수)
	int j;
	int op, dish; // 명령과 접시의 수

	for (i = 0;i < t;i++) {
		scanf_s("%d %d", &op, &dish);
		for (j = 1;j <= dish;j++) {
			// 접시 수만큼 명령 동작 실행
			if (op == 1) {
				Wash(stack1, stack2, &index1, &index2, n);
			}
			else if (op == 2) {
				Dry(stack2, stack3, &index2, &index3, n);
			}
		}
	}


	// 최종 결과 stack3 (dry 된 스택) 출력
	for (i = n - 1;i > -1;i--) {
		printf("%d\n", stack3[i]);
	}


	return 0;
}