// ���� : ���Լ����� �ڷ� ����(Last-In-Fast-Out)
#include <stdio.h>
#include <stdlib.h>
int main() {
	int n;
	scanf_s("%d", &n);

	int* arr = (int*)malloc(sizeof(int) * n); // �ڷᱸ�� ���� �Ҵ�.
	// ������ �ִ� ��ɼ��� 100 �̹Ƿ� ��� i(insert) �� �����ϴ��� ������ �������� ����.
	int arrIndex = -1;
	int data;
	char op; // i, o, c ��ɾ�

	for (int k = n;k > 0;k--) {
		scanf_s(" %c", &op); // ���� scanf �� %c ���Ĺ��� �տ� ������ �־� NULL ���� ���� ����
		switch (op)
		{
		case 'i': // push
			scanf_s(" %d", &data);
			arr[++arrIndex] = data;
			break;
		case 'o': // pop
			if (arrIndex == -1) {
				printf("empty\n");
			}
			else {
				printf("%d\n", arr[arrIndex]);
				arrIndex--;
			}
			break;
		case 'c': // print cnt == arrIndex + 1
			printf("%d\n", arrIndex + 1);
			break;
		default:
			break;
		}
	}

	return 0;
}