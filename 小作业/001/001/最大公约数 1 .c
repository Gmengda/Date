#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main() {

	int a, b;
	int n = 1;
	scanf("%d %d", &a, &b);
	for (int i = 1; i <= a; i++) {
		if (a % i == 0 && b % i == 0) {
			n = i;
		}
	}
	printf("%d", n);

	return 0;
}