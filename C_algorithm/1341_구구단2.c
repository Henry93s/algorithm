#include <stdio.h>
int main(void) {
    int s, e;

    while (1) {
        scanf_s("%d %d", &s, &e); // 구구단 범위의 처음과 끝을 입력 받음
        if ((s < 2 || s > 9) || (e < 2 || e > 9)) { // 구구단 범위에 포함되지 않을 때 에러 처리
            printf("INPUT ERROR!\n");
            continue;
        }
        else {
            break;
        }
    }

    int j;
    if (s <= e) { // 시작 단이 끝 단 보다 작을 경우
        for (int i = s;i <= e;i++) { // i 를 증가시키면서 구구단 출력
            j = 1;
            while (j <= 3) { // 한 줄에 3 개의 연산만 출력하기 위함
                printf("%d * %d = %2d   ", i, j, i * j);
                j++;
            }
            printf("\n");
            while (j <= 6) {
                printf("%d * %d = %2d   ", i, j, i * j);
                j++;
            }
            printf("\n");
            while (j <= 9) {
                printf("%d * %d = %2d   ", i, j, i * j);
                j++;
            }
            printf("\n\n");
        }
    }
    else { // 시작 단이 끝 단 보다 클 경우
        for (int i = s;i >= e;i--) {  // i 를 증가시키면서 구구단 출력
            j = 1;
            while (j <= 3) { // 한 줄에 3 개의 연산만 출력하기 위함
                printf("%d * %d = %2d   ", i, j, i * j);
                j++;
            }
            printf("\n");
            while (j <= 6) {
                printf("%d * %d = %2d   ", i, j, i * j);
                j++;
            }
            printf("\n");
            while (j <= 9) {
                printf("%d * %d = %2d   ", i, j, i * j);
                j++;
            }
            printf("\n\n");
        }
    }

    return 0;
}