// class_1-7.c : 
#include <stdio.h>
int main() {
    int a, b, c; // 세 개의 자연수 변수 선언
    scanf_s("%d %d %d", &a, &b, &c);

    int multiply = a * b * c; // 세 자연수의 값을 곱하고 0 부터 9까지 각각 숫자가 몇 번 쓰였는지 확인할 것
    int cnt0 = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, cnt5 = 0, cnt6 = 0, cnt7 = 0, cnt8 = 0, cnt9 = 0;

    while (multiply > 0) { // 곱한 값을 0 보다 클 때까지 10으로 나누면서
        // 곱한 값을 10으로 나눈 나머지인 맨 끝 자리수가 0~9 중 어떤 숫자인지 체크
        switch (multiply % 10) // 각 자리수의 숫자가 몇 번 들어갔는지 count 시작
        {
        case 0:
            cnt0++;
            break;
        case 1:
            cnt1++;
            break;
        case 2:
            cnt2++;
            break;
        case 3:
            cnt3++;
            break;
        case 4:
            cnt4++;
            break;
        case 5:
            cnt5++;
            break;
        case 6:
            cnt6++;
            break;
        case 7:
            cnt7++;
            break;
        case 8:
            cnt8++;
            break;
        case 9:
            cnt9++;
            break;
        default:
            break;
        }
        multiply /= 10; // 다음 자리 수를 확인하기 위해 곱한 값을 계속 10으로 나눔
    }
    printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", cnt0, cnt1, cnt2, cnt3, cnt4, cnt5, cnt6, cnt7, cnt8, cnt9);

    return 0;
}