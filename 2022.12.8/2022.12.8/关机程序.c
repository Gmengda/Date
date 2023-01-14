#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

////shutdown -s -t 60
////  -s  关机
////	-t  设置时间关机
////	-a  取消关机
//
//int main() {
//	int i = 0;
//
//	system("shutdown -s -t 60");
//again:
//	printf("你的电脑将在1分钟内关机,输入1方可停止.\n");
//	scanf("%d,\n", &i);
//	if (i == 1) {
//		printf("太棒了！");
//		system("shutdown -a");
//	}
//	else {
//		printf("勇敢！");
//		goto again;
//	}
//
//	return 0;
//}
//
//
