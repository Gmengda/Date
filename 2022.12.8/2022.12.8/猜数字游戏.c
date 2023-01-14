#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mune() {
	printf("***********************\n");
	printf("*****   1.play   ******\n");
	printf("*****   0.exit   ******\n");
	printf("***********************\n");
}

//rand函数是专门用来生成随机数的
//返回的是 0  MAX  之间的一个数字
// 
//rang函数使用之前要使用一个srand来设置随机数字生成
//srand(整形)
//srand  只需要调用一次就够了，不需要多次调用 
//所以放在game()  里是不合适的，应该放在main里

//时间戳
//C语言中会返回时间戳，
//需要一个参数，暂时传空指针

void game() {

	int i = rand() % 100 + 1;
	int num = 0;

	while (1) {
		printf("猜数字：");
		scanf("%d", &num);
		if (num > i) {
			printf("猜大了！\n");
		}
		else if (num < i) {
			printf("猜小了！\n");
		}
		else {
			printf("猜对啦！！\n");
			break;
		}
	}


}

int main() {

	int i = 0;
	srand((unsigned int)time(NULL));   //强制类型转换

	do {
		mune();
		printf("请选择：");
		scanf("%d", &i);
		switch (i) {
		case 1:
			printf("开始游戏！\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
			i = 1;
		}
	} while (i);

	return 0;
}

