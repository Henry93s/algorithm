#include <stdio.h>
int main() {
    int n; // ���簢���� �� ���� ���� n
    scanf_s("%d", &n);

    int sum; // ����ؼ� ����ϸ鼭 ������ �� 
    int i, j;
    for (i = 1;i <= n;i++) { // n * n ���·� ����ϱ� ���� �ݺ��� ��ø
        sum = i; // �� line �� ù ��° ��� ���� n ��° �ٰ� ����.
        for (j = 1;j <= n;j++) {
            printf("%d ", sum);
            sum += n; // ������ �ٸ��� sum �� ����� �� 1 �� �ƴ� ���� ���� n ��ŭ ���ϸ鼭 ����ؾ���.
        }
        printf("\n");
    }
}