#include <stdio.h>
int main() {
    int n; // ���簢���� �� ���� ���� n
    scanf_s("%d", &n);

    int i, j;
    int rownum; // �� row line �� �� ���� ����
    for (i = 1;i <= n;i++) { // n * n ���� ���
        rownum = i; // �� row �� ���� n ��° �ٿ��� n �� ����.
        for (j = 1;j <= n;j++) {
            printf("%d ", rownum);
        }
        printf("\n");
    }

    return 0;
}