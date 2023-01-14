#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void init_f_board(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void print_f_board(char f_board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", f_board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		printf("\n");
	}
}

void pull_bom(int board[ROW + 2][COL + 2], int row, int col, int bom)
{

	while (bom)
	{
		int x = rand() % (row - 2) + 1;
		int y = rand() % (col - 2) + 1;

		if (board[x][y] == 0)
		{
			board[x][y] = 1;
			bom--;
		}

	}

}

int clear_bom(int board[ROW + 2][COL + 2], char f_board[ROW][COL], int row, int col)
{
	int x, y;

	while (1)
	{
		printf("请选择您要侦探的目标");
		scanf("%d %d", &x, &y);

		if (x > 0 && x < (row - 1) && y>0 && y < (col - 1))
		{
			if (board[x][y] == 1)
			{
				return fail(board, f_board, ROW + 2, COL + 2);
			}
			else if (f_board[x - 1][y - 1] != ' ')
			{
				printf("这个点已经看过了，请看重新输入。\n");
			}
			else
			{
				f_board[x - 1][y - 1] = 48 + board[x - 1][y - 1] + board[x - 1][y] + board[x - 1][y + 1] + board[x][y - 1] + board[x][y + 1] + board[x + 1][y - 1] + board[x + 1][y] + board[x + 1][y + 1];
				return 0;
			}
		}
		else
		{
			printf("坐标错误，请重新输入!\n");
		}
	}

}

int fail(int board[ROW + 2][COL + 2], char f_board[ROW][COL], int row, int col)
{
	for (int i = 1; i < row - 1; i++)
	{
		for (int j = 1; j < col - 1; j++)
		{
			if (board[i][j] == 1)
			{
				f_board[i - 1][j - 1] = '*';
			}
		}
	}
	printf("很遗憾你踩到雷了~\n");
	print_f_board(f_board, ROW, COL);
	return 1;
}