#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//
////获取字符串长度
//int Strlen(char* arr) {
//	int i = 0;
//	while (arr[i] != '\0') {
//		i++;
//	}
//	return i;
//}
//
//void arrSwap(char* arr){
//
//	int n = Strlen(arr);
//	char* a = *arr;
//
//	*arr = arr[n - 1];
//	arr[n - 1] = '\0';
//	if (Strlen(arr + 1) > 1) {
//		arrSwap(arr + 1);
//	}
//	arr[n - 1] = a;
//}
//
//int main() {
//
//	char arr[] = "abcdef";
//
//	char* p = arr;
//	arrSwap(arr);
//	printf("%s",arr);
//
//	return 0;
//}