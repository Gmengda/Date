#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

void Prime(int x) {
	int i = 0;
	int n = 1;
	for (i = 2; i <= x; i++) {  //ÓÅ»¯ x -> sqrt(x);
		if (x % i == 0) {
			n = 0;
			break;
		}
	}
	if (n) {
		printf("%d ", x);
	}

}

int main() {

	for (int i = 101; i <= 200; i += 2) {
		Prime(i);
	}

	return 0;
}