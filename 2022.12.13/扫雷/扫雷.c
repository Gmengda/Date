#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"


void menu()
{
	printf("*****************************\n");
	printf("********   1. play     ******\n");
	printf("********   0. eixt     ******\n");
	printf("*****************************\n");
}

void game() 
{
	int i = 0;
	int m = 0;
	int board[ROW + 2][COL + 2] = { 0 };
	char f_board[ROW][COL];

	//初始化棋盘
	init_f_board(f_board, ROW, COL);
	//设置雷
	pull_bom(board, ROW + 2, COL + 2, BOM);
	//输出棋盘
	print_f_board(f_board, ROW, COL);
	while (i < (ROW * COL - BOM))
	{
		m = clear_bom(board, f_board, ROW + 2, COL + 2);
		if (m == 1)
			break; 
		print_f_board(f_board, ROW, COL);
		i++;
	}
	if (i == (ROW * COL - BOM))
	{
		printf("恭喜你，你完成了扫雷！\n");
	}

}

void test()
{

	srand((unsigned int)time(NULL));
	int i = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (i);

}

int main() 
{
	
	test();

	return 0;
}