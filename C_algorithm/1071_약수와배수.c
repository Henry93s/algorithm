#include <stdio.h>
#include <stdlib.h> // �����Ҵ� �� �ʿ��� ��� ����
int main() {
    int n; // �Է¹��� n ���� ����
    scanf_s("%d", &n);
    int* arr = (int*)malloc(sizeof(int) * n); // 1���� �����Ҵ� �迭
    int i;
    for (i = 0;i < n;i++) { // n ���� ������ �Է� ����
        scanf("%d", &arr[i]);
    }
    int m; // n ���� ������ �߿��� m �� ����� ����� ���ϱ� ���� ���� ����
    scanf("%d", &m);

    int divsum = 0, mulsum = 0;
    for (i = 0;i < n;i++) {
        if (m % arr[i] == 0) { // m ������ n������������ ���� �� 0 ���� �������� arr[i] �� m �� ���
            divsum += arr[i];
        }
        if (arr[i] % m == 0) { // arr[i] ������ m �� ���� �� 0 ���� �������� arr[i] �� m �� ���
            mulsum += arr[i];
        }
    }
    printf("%d\n%d", divsum, mulsum);

    free(arr); // �����Ҵ� ����
    return 0;
}