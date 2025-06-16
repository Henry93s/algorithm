#include <stdio.h>

int N;
int used[9];           // ���� ��� ���� üũ (1~N)
int permutation[8];    // ���� ���� ���� (�ִ� N=8)

void backtrack(int depth) {
    // ���� ������ ���̰� N�� ��������, ������ �ϼ��� ����
    if (depth == N) {
        // �ϼ��� ������ ���
        for (int i = 0; i < N; i++) {
            printf("%d ", permutation[i]);
        }
        printf("\n"); // �� �� ��� �� ����
        return; // ���� ��� ����
    }

    // 1���� N������ ���� ������� Ž�� (���� ���� ����)
    for (int i = 1; i <= N; i++) {
        // ���� ������ ���� ���ڸ� ��� ����
        if (!used[i]) {
            used[i] = 1;               // i�� ���� ��� ǥ��
            permutation[depth] = i;    // ���� ���� ��ġ�� i�� ����
            backtrack(depth + 1);      // ���� �ڸ�(depth + 1)�� ��� ȣ��
            used[i] = 0;               // ��Ʈ��ŷ: i�� ���ڸ� �ٽ� ����� �� �ֵ��� ����
        }
    }
}

int main() {
    scanf_s("%d", &N);
    backtrack(0);
    return 0;
}