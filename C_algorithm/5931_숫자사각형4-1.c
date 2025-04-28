#include <stdio.h>
int main() {
    int n; // 정사각형의 한 변의 길이 n
    scanf_s("%d", &n);

    int i, j;
    int rownum; // 각 row line 의 값 변수 선언
    for (i = 1;i <= n;i++) { // n * n 형태 출력
        rownum = i; // 각 row 의 값은 n 번째 줄에서 n 과 같다.
        for (j = 1;j <= n;j++) {
            printf("%d ", rownum);
        }
        printf("\n");
    }

    return 0;
}