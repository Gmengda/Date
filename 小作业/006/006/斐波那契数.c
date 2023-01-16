#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int Fibonacci(int n) {
//
//	int j = 0;
//	int z = 1;
//	int sum = 1;
//	if (n == 1 || n == 2)
//		return 1;
//	for (int i = 2; i < n; i++) {
//		j = z;
//		z = sum;
//		sum = z + j;
//	}
//	return sum;
//}
//
//int FibonaccI(int n) {
//
//	if (n == 0) {
//		return 0;
//	}
//	else if (n == 1) {
//		return 1;
//	}
//	else {
//		return FibonaccI(n - 1) + FibonaccI(n - 2);
//	}
//
//}
//
//int main() {
//
//	int n = 0;
//
//	scanf("%d", &n);
//	printf("%d\n", Fibonacci(n));
//	scanf("%d", &n);
//	printf("%d\n", FibonaccI(n));
//
//	return 0;
//}