#include <stdio.h>
int main(void) {
    int n, m; // 사각형의 높이 n 과 너비 m 

    scanf_s("%d %d", &n, &m); // 높이와 너비를 입력받음

    int num = 1;
    for (int i = 1;i <= n;i++) { // n * m 형태로 출력하기 위한 중첩 반복문 구현
        for (int j = 1;j <= m;j++, num++) {
            printf("%d ", num);
        }
        printf("\n");
    }

    return 0;
}