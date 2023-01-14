#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//»ñÈ¡×Ö·û´®³¤¶È
int Strlen(char* arr) {
	int i = 0;
	while (arr[i] != '\0') {
		i++;
	}
	return i;
}

//µ¹ÖÃ×Ö·û´®
void partSwap(char* arr, int n) {
	for (int i = 0; i < (n / 2); i++) {
		char p = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = p;
	}
}

int main() {

	char arr[100];
	int i = 0;

	scanf("%[^\n]", &arr);
	int n = Strlen(arr);

	for (int j = 0; j <= n; j++) {

		if (arr[j] == ' ') {
			partSwap(&arr[i], j - i);
			i = j + 1;
		}
		else if (arr[j] == '\0') {
			partSwap(&arr[i], j - i);
			i = j + 1;
		}
	}

	partSwap(arr, n);

	printf("%s", arr);

	return 0;
}