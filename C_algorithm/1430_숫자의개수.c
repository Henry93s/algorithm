// class_1-7.c : 
#include <stdio.h>
int main() {
    int a, b, c; // �� ���� �ڿ��� ���� ����
    scanf_s("%d %d %d", &a, &b, &c);

    int multiply = a * b * c; // �� �ڿ����� ���� ���ϰ� 0 ���� 9���� ���� ���ڰ� �� �� �������� Ȯ���� ��
    int cnt0 = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0, cnt5 = 0, cnt6 = 0, cnt7 = 0, cnt8 = 0, cnt9 = 0;

    while (multiply > 0) { // ���� ���� 0 ���� Ŭ ������ 10���� �����鼭
        // ���� ���� 10���� ���� �������� �� �� �ڸ����� 0~9 �� � �������� üũ
        switch (multiply % 10) // �� �ڸ����� ���ڰ� �� �� ������ count ����
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
        multiply /= 10; // ���� �ڸ� ���� Ȯ���ϱ� ���� ���� ���� ��� 10���� ����
    }
    printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", cnt0, cnt1, cnt2, cnt3, cnt4, cnt5, cnt6, cnt7, cnt8, cnt9);

    return 0;
}