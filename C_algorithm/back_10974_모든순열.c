#include <stdio.h>

int N;
int used[9];           // 숫자 사용 여부 체크 (1~N)
int permutation[8];    // 현재 순열 저장 (최대 N=8)

void backtrack(int depth) {
    // 현재 순열의 길이가 N과 같아지면, 순열이 완성된 상태
    if (depth == N) {
        // 완성된 순열을 출력
        for (int i = 0; i < N; i++) {
            printf("%d ", permutation[i]);
        }
        printf("\n"); // 한 줄 출력 후 개행
        return; // 현재 재귀 종료
    }

    // 1부터 N까지의 수를 순서대로 탐색 (사전 순을 위함)
    for (int i = 1; i <= N; i++) {
        // 아직 사용되지 않은 숫자만 사용 가능
        if (!used[i]) {
            used[i] = 1;               // i번 숫자 사용 표시
            permutation[depth] = i;    // 현재 순열 위치에 i를 넣음
            backtrack(depth + 1);      // 다음 자리(depth + 1)로 재귀 호출
            used[i] = 0;               // 백트래킹: i번 숫자를 다시 사용할 수 있도록 복구
        }
    }
}

int main() {
    scanf_s("%d", &N);
    backtrack(0);
    return 0;
}