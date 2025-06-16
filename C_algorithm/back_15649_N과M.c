#include <stdio.h>
/*
    backtrack?
    1. �ߺ� ���� ����
    2. ������ ���� ������ ��µǾ���
    => �ߺ��� �ȵǴµ� ������ ���� ������ ��µǾߴµ� �̰� ���� �ݺ�������? ���� �Ұ�..��..?
    �׷��� ����� backtracking ���
*/


void backtrack(int N, int M, int row[], int checked[], int iterator) {
    // return ���� : ���� �� �� ä������ ���
    if (iterator == M) {
        for (int i = 0; i < M; i++) {
            printf("%d ", *(row + i));
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (*(checked + i) == 0) {
            *(checked + i) = 1; // ��� ���ư� �� ���� ��ͷ� ������ �ʰ� �ϱ� ���� like semaphore v(sem_post()) �� mutex lock ���� ����
            // ù �ڸ��� 1�� ä��� backtracking �����ν�
            /*
                1. ���� ���� ���� row �迭�� �� �� ���� -> �ߺ� ���� ó�� �Ϸ��
                2. �Ź� for ������ 1 ~ N(�ִ� 8) ���� ��ȸ�ϴϱ� -> ������ ���������� row �� �� ���� ó�� �Ϸ�
            */
            *(row + iterator) = i;
            backtrack(N, M, row, checked, iterator + 1);
            *(checked + i) = 0; // semaphore p(sem_wait()) OR mutex unlock
        }
    }
}

int main() {
    int N, M;
    int row[8] = { 0 }; // �� �ٿ� ���� �ִ� Depth �� 8 ���� �����̶� ���� ���� -> [8]
    int checked[9] = { 0 }; // �ִ� Depth �� 8�� �����̴ϱ� ���ǻ� üũ �Լ� �� 
    // 0~7 �� �ƴ϶� 0 �����ϰ� 1���� 8 ��� -> [9] �� ����
    int iterator = 0;

    scanf_s("%d %d", &N, &M);
    backtrack(N, M, row, checked, iterator);
    return 0;
}