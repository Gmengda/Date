//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include<stdio.h>
//
//int main() {
//
//	int arr[10] = { 1,2,3,4,5,6,7,8,9 };
//	int left = 0;
//	int right = 9;
//	int flag = 0;
//	int m;
//
//	scanf("%d", &m);
//
//	while (left <= right) {
//		int mid = (left + right) / 2;
//		if (arr[mid] < m) {
//			left = mid + 1;
//		}
//		else if(arr[mid] > m) { 
//			right = mid - 1;
//		}
//		else {
//			printf("找到了，下标是%d", mid);
//			flag = 1;
//			break;
//		}
//	}
//	if (flag == 0) {
//		printf("没找到哦");
//	}
//
//	return 0;
//}
