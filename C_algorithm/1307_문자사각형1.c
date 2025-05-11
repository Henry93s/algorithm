#include <stdio.h>

void drawingRectangle(int N) {
    char arr[100][100] = { 0 };
    int i, row, col;
    int end = N - 1;
    char print = 'A';

    for (col = 0; col <= end; col++) {
        // 아래 방향으로
        if (col == 0 || col % 2 == 0) {
            for (row = 0; row <= end; row++) {
                arr[row][col] = print++;
                if (print > 'Z') {
                    print = 'A';
                }
            }
        }
        else { // 위 방향으로
            for (row = end; row >= 0; row--) {
                arr[row][col] = print++;
                if (print > 'Z') {
                    print = 'A';
                }
            }
        }

    }

    for (i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int N;
    scanf_s("%d", &N);

    if (N <= 0 || N > 100) {
        printf("INPUT ERROR!\n");
        return 0;
    }

    drawingRectangle(N);
    return 0;
}
