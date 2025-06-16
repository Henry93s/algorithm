#include <stdio.h>
/*
    backtrack?
    1. 중복 수열 금지
    2. 수열은 사전 순으로 출력되야함
    => 중복도 안되는데 수열이 사전 순으로 출력되야는데 이걸 기존 반복문으로? 절대 불가..함..?
    그래서 사용한 backtracking 재귀
*/


void backtrack(int N, int M, int row[], int checked[], int iterator) {
    // return 조건 : 수열 한 줄 채워지면 출력
    if (iterator == M) {
        for (int i = 0; i < M; i++) {
            printf("%d ", *(row + i));
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (*(checked + i) == 0) {
            *(checked + i) = 1; // 재귀 돌아갈 때 무한 재귀로 꼬이지 않게 하기 위함 like semaphore v(sem_post()) 나 mutex lock 같은 느낌
            // 첫 자리에 1을 채우고 backtracking 들어감으로써
            /*
                1. 같은 수는 절대 row 배열에 들어갈 수 없음 -> 중복 조건 처리 완료ㅗ
                2. 매번 for 문으로 1 ~ N(최대 8) 까지 순회하니까 -> 무조건 사전순으로 row 한 줄 수열 처리 완료
            */
            *(row + iterator) = i;
            backtrack(N, M, row, checked, iterator + 1);
            *(checked + i) = 0; // semaphore p(sem_wait()) OR mutex unlock
        }
    }
}

int main() {
    int N, M;
    int row[8] = { 0 }; // 한 줄에 수열 최대 Depth 는 8 까지 고정이라서 동적 안함 -> [8]
    int checked[9] = { 0 }; // 최대 Depth 가 8로 고정이니까 편의상 체크 함수 는 
    // 0~7 이 아니라 0 무시하고 1부터 8 사용 -> [9] 로 선언
    int iterator = 0;

    scanf_s("%d %d", &N, &M);
    backtrack(N, M, row, checked, iterator);
    return 0;
}