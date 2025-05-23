#include <stdio.h>
#include <stdlib.h>
int conquerArmy(int n, int* armyArr) {
	int armyNum[100001][2] = {0};
	for (int i = 0;i < n;i++) {
		armyNum[armyArr[i]][1] += 1;
	}

	int max = armyNum[0][0];
	int maxIndex = -1;
	int duplication = -1;

	for (int i = 1;i <= 100000;i++) {
		if (armyNum[i][1] >= max) {
			if (armyNum[i][1] == max) {
				duplication = 1;
			}
			else {
				max = armyNum[i][1];
				maxIndex = i;
				duplication = -1;
			}
		}
	}

	if (duplication == 1 || max <= (n / 2)) {
		return 0;
	}
	else {
		return maxIndex;
	}
}
int main() {
	int N;
	scanf_s("%d", &N);
	int armyCount;
	int* armyArr;
	int isConquer = -1;

	int* printAnswer = (int*)malloc(sizeof(int) * N);
	int printAnswerIndex = 0;

	for (int i = 0;i < N;i++) {
		scanf_s("%d", &armyCount);
		armyArr = (int*)malloc(sizeof(int) * (armyCount));

		for (int j = 0;j < armyCount;j++) {
			scanf_s("%d", (armyArr + j));
		}

		isConquer = conquerArmy(armyCount, armyArr);
		if (isConquer == 0) {
			*(printAnswer + printAnswerIndex++) = -1;
		}
		else {
			*(printAnswer + printAnswerIndex++) = isConquer;
		}
	}

	for (int i = 0;i < N;i++) {
		if (*(printAnswer + i) == -1) {
			printf("SYZKGW\n");
		}
		else {
			printf("%d\n", *(printAnswer + i));
		}
	}

	return 0;
}