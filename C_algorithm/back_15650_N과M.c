#include <stdio.h>
/*
    backtrack?
    1. �ߺ� ���� ����
    2. ������ ���� ������ ��µǾ���
    => �ߺ��� �ȵǴµ� ������ ���� ������ ��µǾߴµ� �̰� ���� �ݺ�������? ���� �Ұ�..��..?
    �׷��� ����� backtracking ���
*/

void backtrack(int N, int M, int row[], int iterator, int start) {
    // return ���� : ���� �� �� ä������ ���
    if (iterator == M) {
        for (int i = 0; i < M; i++) {
            printf("%d ", *(row + i));
        }
        printf("\n");
        return;
    }

    // ���� ��� ���ϱ� 1 2 3 4 �ϰ� ������ �� �ߺ� ó���� ����ϸ� �ȵ� !
    // ��, for index �� �ʱ�ȭ�� �ʿ䰡 ���� ! , ��, lock �� ���� �ʾƵ� �ȴ�!
    // 1. ���� backtracking �ڵ带 ��ŸԴ� �κп��� �����غ��� ��ͷ� ������ i �� �����ϴ� for ���� i �� ���������� �ѱ�� �ȴ�
    // 2. �׷��� lock �� �ʿ䰡 �������� ! 
    for (int i = start; i <= N; i++) {
        *(row + iterator) = i;
        backtrack(N, M, row, iterator + 1, i + 1);
    }
}

int main() {
    int N, M;
    int row[8] = { 0 }; // �� �ٿ� ���� �ִ� Depth �� 8 ���� �����̶� ���� ���� -> [8]
    int iterator = 0;
    int start = 1;

    scanf_s("%d %d", &N, &M);
    backtrack(N, M, row, iterator, start);
    return 0;
}