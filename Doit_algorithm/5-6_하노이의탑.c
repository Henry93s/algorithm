#include <stdio.h>
void move(int no, int x, int y) {
	if (no > 1) {
		move(no - 1, x, 6 - x - y); // ���� ��տ��� �߰� ���
	}
	printf("���� %d �� %d ���� %d ������� �ű�\n", no, x, y);

	if (no > 1) {
		move(no - 1, 6 - x - y, y); // �߰� ��տ��� ��ǥ ���
	}
}
int main() {
	int n; // ���� ����
	printf("�ϳ����� ž\n���� ���� : ");
	scanf_s("%d", &n);
	move(n, 1, 3); // 1�� ���� ��տ��� ���� 3�� ��ǥ ������� �̵�

	return 0;
}