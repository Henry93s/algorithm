#include <stdio.h>
int main() {
    int n; // 정사각형의 한 변의 길이 n
    scanf_s("%d", &n);

    int i, j;
    int rownum = 1; // 각 line 마다 출력할 증가시킬 값 변수 선언 및 초기화
    int sum;
    for (i = 1;i <= n;i++, rownum++) {
        sum = rownum; // 첫 출력 값은 항상 n 번째 줄
        for (j = 1;j <= n;j++) {
            printf("%d ", sum);
            sum += rownum; // 증가시키는 값은 n 번째 줄이므로 각 line 씩 증가
        }
        printf("\n");
    }

    return 0;
}