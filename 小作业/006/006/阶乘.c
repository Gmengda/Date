#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int factorial(int n) {
	int sum = 1;
	for (int i = 2; i <= n; i++) {
		sum *= i;
	}

	return sum;
}

int Factorial(int n) {

	if (n == 1) {
		return 1;
	}
	else {
		return n * Factorial(n - 1);
	}
}

int main() {

	int n;

	scanf("%d", &n);
	printf("%d\n", factorial(n));
	printf("%d\n", Factorial(n));

	return 0;
}