#include <stdio.h>
int main() {
    int s; int e;
    while (1) {
        scanf_s("%d %d", &s, &e); // 구구단의 시작 단과 끝 단을 입력받음
        if ((s < 2 || s > 9) || (e < 2 || e > 9)) { // 시작 단과 끝 단이 구구단에 포함되지 않을 경우 에러 처리
            printf("INPUT ERROR!\n");
            continue; // 구구단의 단을 잘못입력한 경우이므로 다시 입력하도록 한다.
        }
        else {
            break; // 구구단의 단을 알맞게 입력했으므로 반복문을 탈출하고 다음 step 으로 진행
        }
    }

    if (s <= e) { // 선 입력한 단이 후 입력한 단 보다 작을 경우 ... case 1
        for (int j = 1;j <= 9;j++) {
            for (int i = s;i <= e;i++) { // case 1 : 선 입력단 ~ 후 입력단 순서 출력
                printf("%d * %d = %2d   ", i, j, i * j); // %2d : 2 자리 우측 정렬
            }
            printf("\n");
        }
    }
    else {
        for (int j = 1;j <= 9;j++) { // 선 입력한 단이 후 입력한 단 보다 클 경우 ... case 2
            for (int i = s;i >= e;i--) {
                printf("%d * %d = %2d   ", i, j, i * j); // case 2 : 후 입력단 ~ 선 입력단 순서 출력
            }
            printf("\n");
        }
    }

    return 0;
}