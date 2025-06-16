#include <stdio.h>
/*
    backtrack?
    1. 중복 수열 금지
    2. 수열은 사전 순으로 출력되야함
    => 중복도 안되는데 수열이 사전 순으로 출력되야는데 이걸 기존 반복문으로? 절대 불가..함..?
    그래서 사용한 backtracking 재귀
*/

void backtrack(int N, int M, int row[], int iterator, int start) {
    // return 조건 : 수열 한 줄 채워지면 출력
    if (iterator == M) {
        for (int i = 0; i < M; i++) {
            printf("%d ", *(row + i));
        }
        printf("\n");
        return;
    }

    // 예시 출력 보니까 1 2 3 4 하고 나머지 다 중복 처리로 출력하면 안됨 !
    // 즉, for index 를 초기화할 필요가 없다 ! , 즉, lock 을 걸지 않아도 된다!
    // 1. 기존 backtracking 코드를 울궈먹는 부분에서 생각해보면 재귀로 들어가고나서 i 는 진행하던 for 문의 i 를 다음값으로 넘기면 된다
    // 2. 그래서 lock 이 필요가 없어졌다 ! 
    for (int i = start; i <= N; i++) {
        *(row + iterator) = i;
        backtrack(N, M, row, iterator + 1, i + 1);
    }
}

int main() {
    int N, M;
    int row[8] = { 0 }; // 한 줄에 수열 최대 Depth 는 8 까지 고정이라서 동적 안함 -> [8]
    int iterator = 0;
    int start = 1;

    scanf_s("%d %d", &N, &M);
    backtrack(N, M, row, iterator, start);
    return 0;
}