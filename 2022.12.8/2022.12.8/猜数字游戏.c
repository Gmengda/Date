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

//rand������ר�����������������
//���ص��� 0  MAX  ֮���һ������
// 
//rang����ʹ��֮ǰҪʹ��һ��srand�����������������
//srand(����)
//srand  ֻ��Ҫ����һ�ξ͹��ˣ�����Ҫ��ε��� 
//���Է���game()  ���ǲ����ʵģ�Ӧ�÷���main��

//ʱ���
//C�����л᷵��ʱ�����
//��Ҫһ����������ʱ����ָ��

void game() {

	int i = rand() % 100 + 1;
	int num = 0;

	while (1) {
		printf("�����֣�");
		scanf("%d", &num);
		if (num > i) {
			printf("�´��ˣ�\n");
		}
		else if (num < i) {
			printf("��С�ˣ�\n");
		}
		else {
			printf("�¶�������\n");
			break;
		}
	}


}

int main() {

	int i = 0;
	srand((unsigned int)time(NULL));   //ǿ������ת��

	do {
		mune();
		printf("��ѡ��");
		scanf("%d", &i);
		switch (i) {
		case 1:
			printf("��ʼ��Ϸ��\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("����������������룡\n");
			i = 1;
		}
	} while (i);

	return 0;
}

