#include <stdio.h>
int main(void) {
    int n, m; // �簢���� ���� n �� �ʺ� m 

    scanf_s("%d %d", &n, &m); // ���̿� �ʺ� �Է¹���

    int num = 1;
    for (int i = 1;i <= n;i++) { // n * m ���·� ����ϱ� ���� ��ø �ݺ��� ����
        for (int j = 1;j <= m;j++, num++) {
            printf("%d ", num);
        }
        printf("\n");
    }

    return 0;
}