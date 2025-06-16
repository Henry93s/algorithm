#include <stdio.h>

int N, M;
int sequence[8];       // �ִ� M�� 8 
int visited[9];        // �湮 üũ (1���� N���� ���)

void backtrack(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            printf("%d ", sequence[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            sequence[depth] = i;
            backtrack(depth + 1);
            visited[i] = 0; // backtrack
        }
    }
}

int main() {
    scanf_s("%d %d", &N, &M);
    backtrack(0);
    return 0;
}