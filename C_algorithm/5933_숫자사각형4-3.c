#include <stdio.h>
int main() {
    int n; // ���簢���� �� ���� ���� n
    scanf_s("%d", &n);

    int i, j;
    int rownum = 1; // �� line ���� ����� ������ų �� ���� ���� �� �ʱ�ȭ
    int sum;
    for (i = 1;i <= n;i++, rownum++) {
        sum = rownum; // ù ��� ���� �׻� n ��° ��
        for (j = 1;j <= n;j++) {
            printf("%d ", sum);
            sum += rownum; // ������Ű�� ���� n ��° ���̹Ƿ� �� line �� ����
        }
        printf("\n");
    }

    return 0;
}