#include <stdio.h>
int main() {
    int n; // ���簢���� �� ���� ���� n
    scanf_s("%d", &n);

    int rownum; // �� line �� ����� �� ����
    // Ȧ�� line ���� 1 ���� n���� ����
    // ¦�� line ���� n ���� 1���� ����
    int i, j;
    for (i = 1;i <= n;i++) { // n * n ���·� ���
        if (i % 2 != 0) { // Ȧ�� line �� ��
            rownum = 1; // ����� 1 ���� �̹Ƿ� ��� ���� ���� 1�� ����
            for (j = 1;j <= n;j++, rownum++) { // n ���� ���
                printf("%d ", rownum);
            }
        }
        else { // ¦�� line �� ��
            rownum = n; // ����� n ���� �̹Ƿ� ��� ���� ���� n ���� ����
            for (j = n;j >= 1;j--, rownum--) { // 1 ���� ���
                printf("%d ", rownum);
            }
        }
        printf("\n");
    }

    return 0;
}