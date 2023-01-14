#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "game.h"

void game() {

	int n = 0;
	char m;
	char board[ROW][COL];
	//初始棋盘为全空格
	init_board(board, ROW, COL);
	//打印棋盘
	print_board(board, ROW, COL);
	while (n < (ROW)*(COL))
	{
		if (n % 2 == 0) 
		{
			//玩家下棋
			player_move(board, ROW, COL);
		}
		else
		{
			//电脑下棋
			computer_move(board, ROW, COL);
		}
		//打印棋盘
		print_board(board, ROW, COL);
		//判断局势
		m = situation(board, ROW, COL);
		if (m == '*')
		{
			printf("玩家胜！\n");
			break;
		}
		else if (m == '#')
		{
			printf("电脑胜！\n");
			break;
		}
		n++;
	}
	if (n == (ROW) * (COL))
		printf("平局！\n");

}

void mune() 
{

	printf("******************\n");
	printf("***** 1.paly *****\n");
	printf("***** 0.eixt *****\n");
	printf("******************\n");
}

void test()
{
	srand((unsigned int)time(NULL));
	int i = 0;

	do {
		mune();
		printf("请选择：");
		scanf("%d", &i);
		switch (i) 
		{
		case 1:
			printf("开始游戏~\n");
			game();
			break;
		case 0:
			printf("期待下次见面~\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
		}

	} while (i);

}

int main() 
{

	test();

	return 0;
}







