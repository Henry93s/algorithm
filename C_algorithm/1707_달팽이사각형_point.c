#include <stdio.h>

void drawingSnail(int N) {
    int arr[100][100] = { 0 };
    int num = 1;
    int i, row, col;
    int start = 0;
    int end = N - 1;

    while (start <= end) {
        // 오른쪽
        for (col = start; col <= end; col++) {
            arr[start][col] = num++;
        }

        // 아래쪽
        for (row = start + 1; row <= end; row++) {
            arr[row][end] = num++;
        }

        // 왼쪽
        for (col = end - 1; col >= start; col--) {
            arr[end][col] = num++;
        }

        // 위쪽
        for (row = end - 1; row > start; row--) {
            arr[row][start] = num++;
        }

        // 안쪽 사각형으로 이동
        start++;
        end--;
    }

    for (i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", arr[i][j]);
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

    drawingSnail(N);
    return 0;
}
