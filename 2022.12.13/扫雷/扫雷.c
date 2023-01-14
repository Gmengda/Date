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

	//��ʼ������
	init_f_board(f_board, ROW, COL);
	//������
	pull_bom(board, ROW + 2, COL + 2, BOM);
	//�������
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
		printf("��ϲ�㣬�������ɨ�ף�\n");
	}

}

void test()
{

	srand((unsigned int)time(NULL));
	int i = 0;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &i);
		switch (i)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (i);

}

int main() 
{
	
	test();

	return 0;
}