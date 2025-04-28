#include <stdio.h>
int main() {
    int n; // 정사각형의 한 변의 길이 n
    scanf_s("%d", &n);

    int sum; // 계속해서 출력하면서 증가할 값 
    int i, j;
    for (i = 1;i <= n;i++) { // n * n 형태로 출력하기 위한 반복문 중첩
        sum = i; // 각 line 의 첫 번째 출력 값은 n 번째 줄과 같다.
        for (j = 1;j <= n;j++) {
            printf("%d ", sum);
            sum += n; // 이전과 다르게 sum 을 출력할 때 1 이 아닌 변의 길이 n 만큼 더하면서 출력해야함.
        }
        printf("\n");
    }
}