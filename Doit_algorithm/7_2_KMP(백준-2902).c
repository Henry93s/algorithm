#include <stdio.h>
#include <stdlib.h>
void findStr(char* find, char* shortStr, int shortIndex) {
	char findChar = '-';
	for (int i = shortIndex; *(find + i) != '\0'; i++) {
		if (*(find + i) == findChar) {
			shortStr[shortIndex++] = *(find + i + 1);
		}
	}
}

int main() {
	char find[101];
	scanf_s("%s", find, 101);
	char shortStr[101] = "~";
	int shortIndex = 0;
	shortStr[shortIndex++] = find[0]; // 첫 글자는 항상 대문자

	findStr(find, shortStr, shortIndex);

	printf("%s", shortStr);

	return 0;
}