#include <stdio.h>
int main() {
    int N;
    // �迭 ��� ���Ҹ� �ι��ڷ� �ʱ�ȭ
    char arr[101][101] = { 0 };
    scanf_s("%d", &N);
    char ch = 'A';

    for (int i = 1; i <= N; i++) {
        int i_tmp = i;
        for (int j = N; j >= 1; j--) {
            arr[i_tmp][j] = ch;
            i_tmp++;
            ch++;

            if (ch == 'Z' + 1) ch = 'A';
            if (i_tmp > N) break;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            // ���Ұ� �ι��ڸ� ������� ���
            if (arr[i][j] == NULL) {
                printf("  ");
            }
            else {
                printf("%c ", arr[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}