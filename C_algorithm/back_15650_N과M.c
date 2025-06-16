#include <stdio.h>

int N, M;
int sequence[8]; // �ִ� M = 8

void backtrack(int depth, int start) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            printf("%d ", sequence[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i <= N; i++) {
        sequence[depth] = i;
        backtrack(depth + 1, i + 1); // i+1���� Ž�� �� ��������
    }
}

int main() {
    scanf_s("%d %d", &N, &M); // �Ǵ� scanf_s ����
    backtrack(0, 1); // 1���� ����
    return 0;
}
