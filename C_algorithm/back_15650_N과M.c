#include <stdio.h>

int N, M;
int sequence[8]; // 최대 M = 8

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
        backtrack(depth + 1, i + 1); // i+1부터 탐색 → 오름차순
    }
}

int main() {
    scanf_s("%d %d", &N, &M); // 또는 scanf_s 가능
    backtrack(0, 1); // 1부터 시작
    return 0;
}
