#include <stdio.h>
int main(void) {
    int s, e;

    while (1) {
        scanf_s("%d %d", &s, &e); // ������ ������ ó���� ���� �Է� ����
        if ((s < 2 || s > 9) || (e < 2 || e > 9)) { // ������ ������ ���Ե��� ���� �� ���� ó��
            printf("INPUT ERROR!\n");
            continue;
        }
        else {
            break;
        }
    }

    int j;
    if (s <= e) { // ���� ���� �� �� ���� ���� ���
        for (int i = s;i <= e;i++) { // i �� ������Ű�鼭 ������ ���
            j = 1;
            while (j <= 3) { // �� �ٿ� 3 ���� ���길 ����ϱ� ����
                printf("%d * %d = %2d   ", i, j, i * j);
                j++;
            }
            printf("\n");
            while (j <= 6) {
                printf("%d * %d = %2d   ", i, j, i * j);
                j++;
            }
            printf("\n");
            while (j <= 9) {
                printf("%d * %d = %2d   ", i, j, i * j);
                j++;
            }
            printf("\n\n");
        }
    }
    else { // ���� ���� �� �� ���� Ŭ ���
        for (int i = s;i >= e;i--) {  // i �� ������Ű�鼭 ������ ���
            j = 1;
            while (j <= 3) { // �� �ٿ� 3 ���� ���길 ����ϱ� ����
                printf("%d * %d = %2d   ", i, j, i * j);
                j++;
            }
            printf("\n");
            while (j <= 6) {
                printf("%d * %d = %2d   ", i, j, i * j);
                j++;
            }
            printf("\n");
            while (j <= 9) {
                printf("%d * %d = %2d   ", i, j, i * j);
                j++;
            }
            printf("\n\n");
        }
    }

    return 0;
}