#include <stdio.h>
int main() {
    int n; // 정사각형의 한 변의 길이 n
    scanf_s("%d", &n);

    int rownum; // 각 line 에 출력할 값 변수
    // 홀수 line 에는 1 부터 n까지 증가
    // 짝수 line 에는 n 부터 1까지 감소
    int i, j;
    for (i = 1;i <= n;i++) { // n * n 형태로 출력
        if (i % 2 != 0) { // 홀수 line 일 때
            rownum = 1; // 출력은 1 부터 이므로 출력 시작 값을 1로 적용
            for (j = 1;j <= n;j++, rownum++) { // n 까지 출력
                printf("%d ", rownum);
            }
        }
        else { // 짝수 line 일 때
            rownum = n; // 출력은 n 부터 이므로 출력 시작 값을 n 으로 적용
            for (j = n;j >= 1;j--, rownum--) { // 1 까지 출력
                printf("%d ", rownum);
            }
        }
        printf("\n");
    }

    return 0;
}