#define _CRT_SECURE_NO_WARNINGS 1

int Fib(int n) {

	if (n <= 2) {
		return 1;
	}
	else {
		return Fib(n - 1) + Fib(n - 2);
	}

}

int main() {

	int n = 0;

	scanf("%d", &n);
	printf("%d", Fib(n));

	return 0;
}