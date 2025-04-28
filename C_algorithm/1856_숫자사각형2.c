#include <stdio.h>
int main(void) {
    int n, m; // 사각형의 높이 n 과 너비 m 

    scanf_s("%d %d", &n, &m); // 높이와 너비를 입력받음

    int num = 1; // 출력하면서 계속 증가시킬 값인 num 변수 선언 및 초기화
    int j; 
    int temp; 
    for (int i = 1; i <= n;i++) { // i 는 높이 n 까지 1씩 증가하면서 반복문을 동작시킴
        if (i % 2 != 0) { // 홀수 line 줄일 때 j 는 너비 m 까지 증가하면서 num 을 출력
            for (j = 1; j <= m; j++, num++) {
                printf("%d ", num);
            }
        }
        else { // 짝수 line 줄일 때 j 는 너비 m 부터 1까지 감소하면서 num 을 출력
            temp = num + m; // 홀수 line 일 때 -> 방향 후 짝수 line 일 때 <- 순으로 출력하므로
            num += (m - 1); // 실제 프로그래밍 상 출력할 값에 따라 num 에 너비 m - 1 만큼 더하여 값을 적용한다.
            for (j = m; j >= 1; j--, num--) {
                printf("%d ", num);
            }
            num = temp; // 다시 짝수 라인일 때는 temp 에 저장해 놓은 num 값을 적용.
            // 바로 위 for 문에서 num 이 출력되면서 감소되었기 때문
        }
        printf("\n");
    }
}