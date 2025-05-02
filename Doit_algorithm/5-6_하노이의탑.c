#include <stdio.h>
void move(int no, int x, int y) {
	if (no > 1) {
		move(no - 1, x, 6 - x - y); // 시작 기둥에서 중간 기둥
	}
	printf("원반 %d 를 %d 에서 %d 기둥으로 옮김\n", no, x, y);

	if (no > 1) {
		move(no - 1, 6 - x - y, y); // 중간 기둥에서 목표 기둥
	}
}
int main() {
	int n; // 원반 개수
	printf("하노이의 탑\n원반 개수 : ");
	scanf_s("%d", &n);
	move(n, 1, 3); // 1번 시작 기둥에서 최종 3번 목표 기둥으로 이동

	return 0;
}