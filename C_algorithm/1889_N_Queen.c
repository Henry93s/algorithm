#include <stdio.h>
#include <stdlib.h>
/*
- 재귀 : 자기 자신을 다시 부르는 함수.
    -> 복잡한 문제를 작은 단위로 쪼개서 쉽게 해결할 수 있도록 설계하기 위함.

    - 필수 조건 : 1. 종료 시점 : 더 이상 재귀 호출을 하지 않고 끝내는 조건이 반드시 필요함.
                  2. 재귀 호출 : 자기 자신을 다시 부르는 부분

    - 예시 정올 문제 1309 번 팩토리얼
        #include <stdio.h>
        long long factorial(int n) {
            if (n == 0) { (재귀 조건 1. 종료 시점)
                return 1; // 1 을 반환해야 이전에 반환된 결과들을 계속 곱할 수 있다.
                // 재귀함수의 최종 계산 return 값은 '스택' 과 같이 후입선출로 쌓이면서 동작.
            }
            else {
                // if ~ else : 문제 내용에 따른 출력 부분.
                if (n != 1) {
                    printf("%d! = %d * %d!\n", n, n, n - 1);
                }
                else {
                    printf("%d! = %d\n", n, n);
                }
                // (재귀 조건 2. 재귀 함수 호출)
                return n * factorial(n - 1);
            }
        }
        int main() {
            int n;
            scanf_s("%d", &n);
            printf("%lld", factorial(n));
            return 0;
        }

        ex. 실행 과정
        factorial(5)
        → 5 × factorial(4)
        → 5 × 4 × factorial(3)
        → 5 × 4 × 3 × factorial(2)
        → 5 × 4 × 3 × 2 × factorial(1)
        → 5 × 4 × 3 × 2 × 1 = 120

 */


 /*
     - 8퀸 문제
       8 * 8 체스판에 퀸 8 개를 서로 공격하지 않게 놓는 모든 경우의 수를 찾는 문제
       - 퀸 : 가로, 세로, 대각선의 모든 위치로 움직여서 공격할 수 있음

     - 알고리즘
       한 행(row) 에 퀸을 하나씩 놓을 때, 이전에 놓은 퀸과 서로 공격이 되는지 체크
       공격이 되지 않을 때 다음 행으로 계속 놓고(재귀 알고리즘), 안 되면 백트래킹(되돌아옴)
       모든 행에 퀸을 다 놓았을 때 정답 case 개수 증가

 */



 // 퀸을 놓을 수 있는지 검사
int queenChk(int* col, int row, int c) {
    for (int i = 0; i < row; i++) {
        // 같은 열에 있거나, 같은 대각선에 있으면 안 됨
        if (col[i] == c || abs(col[i] - c) == row - i)
            return 0;
    }
    return 1;
}

// 퀸을 N 행 번째 줄에 놓는 함수 (재귀 함수)
// -> 행을 먼저 기준으로 잡고 다른 행에 있도록 위치 -> 이후 놓은 위치가 같은 열인지, 같은 대각선인지 검사
// -> (같은 열이거나 같은 대각선일 경우, queenChk return 0) 다른 colPass 열 에서 퀸을 놓을 수 있는지 검사
// -> (다른 열이고 다른 대각선일 경우, queenChk return 1) row 행 colPass 열에 퀸을 놓고 다음 행으로 이동하는 재귀 함수 호출
void placeQueen(int* col, int* cnt, int row, int N) {
    if (row == N) { // 퀸 N 개 다 놓았으면 cnt(경우의 수) 한 개 추가함!
        (*cnt)++;
        return;
    }

    for (int colPass = 0; colPass < N; colPass++) { // 열을 N열까지 하나씩 시도
        if (queenChk(col, row, colPass)) {
            col[row] = colPass;       // row행 colPass열에 퀸을 놓고
            placeQueen(col, cnt, row + 1, N);     // 다음 행으로 이동 (재귀 호출)
            // 돌아올 땐 col[row] 값을 다시 덮어쓰기 때문에 초기화 안 해도 됨
        }
    }
}

int main() {
    // 정올 1889 N Queen 문제 적용 
    int N; 
    scanf_s("%d", &N);

    int* col = (int*)malloc(sizeof(int) * N); // 각 행마다 퀸이 놓일 N 열의 공간 확보
    int cnt = 0; // 퀸이 위치할 수 있는 모든 경우의 개수

    placeQueen(col, &cnt, 0, N); // 0번째 행부터 시작
    printf("%d", cnt);
    return 0;
}



/*
    - 정올 1889 N Queen 문제 적용

    1. main 함수에서 N 을 입력 받음
    2. 퀸이 놓일 열이 저장될 col 의 길이를 동적할당으로 N 크기로 변경
    3. placeQueen 함수 중 열을 하나씩 시도하는 반복문에서 colPass 로 시도하는 열을 N 열까지 시도하도록 수정

*/