#include <stdio.h>
#include <stdlib.h>
int main() {
	int n;
	scanf("%d", &n); // n ���� ������ �Է¹���
	int* arr = (int*)malloc(sizeof(int) * n); // n ���� ������ 1���� �����迭 �Ҵ� �� �ʱ�ȭ
	int i, j;
	for (i = 0;i < n;i++) {  // �Է¹��� ������ �� �ִ� ������� �ּҰ������ ã������ �������� �Է¹���
		scanf("%d", &arr[i]);
	}

	int max = arr[0]; // max �� �Ǵ��� ���� �� ���ǿ� �� �������(for)
	for (i = 0;i < n;i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	int break_control; // �ִ������� Ȯ���ϰ� ���� break_control �� ���� 
	// �ִ������� Ȯ�ε� ������ �ִ������� ����ؼ� ��ü
	int maxdiv = 1;
	for (i = 2;i <= max;i++) { // �ִ����� find case
		break_control = 0;
		for (j = 0;j < n;j++) {
			if (arr[j] % i == 0) {
				break_control = 1;
			}
			else {
				break_control = 0;
				break;
			}
		}
		if (break_control == 1) {
			maxdiv = i;
		}
	}

	int minmul = max;
	int arr_max = -1; // max �� �Ǵ��� ���� �� ���ǿ� �� �������(for)
	for (i = 0;i < n;i++) {
		if (arr[i] > arr_max) {
			arr_max = arr[i];
		}
	}

	// �ּҰ������ Ȯ���ϰ� ���� break_control �� ���� 
	// �ִ������� Ȯ�εǸ� �ִ������� ��ü�ϰ� �ٷ� break �� �ݺ��� Ż��
	for (i = arr_max; ;i++) {
		break_control = 0;
		for (j = 0;j < n;j++) {
			if (i % arr[j] == 0) {
				break_control = 1;
			}
			else {
				break_control = 0;
				break;
			}
		}
		if (break_control == 1) {
			minmul = i;
			break;
		}
	}

	printf("%d %d", maxdiv, minmul);

	return 0;
}