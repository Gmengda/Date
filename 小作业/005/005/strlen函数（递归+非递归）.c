#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//
//int Strlen(char* arr) {
//	int n = 0;
//	int i = 0;
//
//	while (arr[i] != '\0'){
//		i++;
//		n++;
//	}
//	return n;
//}
//
//int StrLen(char* arr) {
//	static int i = 0;
//	if (arr[i] != '\0') {
//		return 1 + StrLen(&arr[i + 1]);      //注意为什么不能用++!!
//	}
//	else {
//		return 0;
//	}
//
//}
//
//int main() {
//
//	char arr[] = "hello bit";
//
//	printf("%d \n", Strlen(&arr));
//	printf("%d \n", StrLen(&arr));
//
//	return 0;
//}