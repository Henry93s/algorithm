#include <stdio.h>
#include <stdlib.h> // 동적할당 시 필요한 헤더 파일
int main() {
    int n; // 입력받을 n 개의 정수
    scanf_s("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n); // 1차원 동적할당 배열
    int i;
    for (i = 0;i < n;i++) { // n 개의 정수를 입력 받음
        scanf("%d", &arr[i]);
    }
    int m; // n 개의 정수들 중에서 m 의 약수와 배수를 구하기 위한 변수 선언
    scanf("%d", &m);

    int divsum = 0, mulsum = 0;
    for (i = 0;i < n;i++) {
        if (m % arr[i] == 0) { // m 나누기 n개의정수들을 했을 때 0 으로 떨어지면 arr[i] 는 m 의 약수
            divsum += arr[i];
        }
        if (arr[i] % m == 0) { // arr[i] 나누기 m 을 했을 때 0 으로 떨어지면 arr[i] 는 m 의 배수
            mulsum += arr[i];
        }
    }
    printf("%d\n%d", divsum, mulsum);

    free(arr); // 동적할당 해제
    return 0;
}