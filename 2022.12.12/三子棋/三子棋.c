#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "game.h"

void game() {

	int n = 0;
	char m;
	char board[ROW][COL];
	//��ʼ����Ϊȫ�ո�
	init_board(board, ROW, COL);
	//��ӡ����
	print_board(board, ROW, COL);
	while (n < (ROW)*(COL))
	{
		if (n % 2 == 0) 
		{
			//�������
			player_move(board, ROW, COL);
		}
		else
		{
			//��������
			computer_move(board, ROW, COL);
		}
		//��ӡ����
		print_board(board, ROW, COL);
		//�жϾ���
		m = situation(board, ROW, COL);
		if (m == '*')
		{
			printf("���ʤ��\n");
			break;
		}
		else if (m == '#')
		{
			printf("����ʤ��\n");
			break;
		}
		n++;
	}
	if (n == (ROW) * (COL))
		printf("ƽ�֣�\n");

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
		printf("��ѡ��");
		scanf("%d", &i);
		switch (i) 
		{
		case 1:
			printf("��ʼ��Ϸ~\n");
			game();
			break;
		case 0:
			printf("�ڴ��´μ���~\n");
			break;
		default:
			printf("����������������룡\n");
		}

	} while (i);

}

int main() 
{

	test();

	return 0;
}







