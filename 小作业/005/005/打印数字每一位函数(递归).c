#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int Number(int x) {
	//获取x的位数
	if (x < 10) {
		return 1;
	}
	else {
		return 1 + Number(x / 10);
	}
}

void Print(int x,int n) {

	n--;
	if (n) {
		Print(x / 10, n);
	}
	printf("%d ", x % 10);
}

int main() {

	int x;

	scanf("%d", &x);
	Print(x, Number(x));

	return 0;
}

