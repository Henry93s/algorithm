#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, k; // �ڿ��� n �� k ����
	scanf_s("%d %d", &n, &k); 
	int* div_arr = (int*)malloc(sizeof(int) * n); // n ���� ������ 1���� �����Ҵ� �迭 ���� �� �ʱ�ȭ
	int div_arrcnt = 0; // �迭�� �ε��� ��Ʈ�� ����
	int i;
	for (i = 0;i < n;i++) {
		if (i != 0 && n % i == 0) { // n ���� ���������� ��ȸ�ϸ鼭 ������� �Ǵ��ϰ�
			// ����� ��� ��� 1���� �����Ҵ� �迭�� ���ʷ� ���� ����
			div_arr[div_arrcnt] = i;
			div_arrcnt++;
		}
	}
	printf("%d", div_arr[k - 1]); // ����� ����� �迭�� ���� k ��°�� ���� ����� ����Ϸ��� k - 1 �ε��� ������ ���

	free(div_arr);
	return 0;
}