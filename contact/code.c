#include "text.h"

void mune()
{
	printf("******************\n");
	printf("****1.add     ****\n");
	printf("****2.del     ****\n");
	printf("****3.search  ****\n");
	printf("****4.modify  ****\n");
	printf("****5.show    ****\n");
	printf("****6.sort    ****\n");
	printf("****0.exit    ****\n");
	printf("******************\n");
}

enum op
{
	zz,
	add,
	del,
	search,
	modify,
	show,
	sort
};

int main()
{
	int m;
	tact p;
	//初始化通讯录
	initcontact(&p);
	do
	{
		mune();
		printf("请选择想要执行的操作：");
		scanf("%d", &m);
		switch (m)
		{
		case add:
			Addcontact(&p);
			break;
		case del:
			Delcontact(&p);
			break;
		case search:
			searchcontact(&p);
			break;
		case modify:
			Moidfycontact(&p);
			break;
		case show:
			Showcontact(&p);
			break;
		case sort:
			Sortcontact(&p);
			break;
		case zz:
			printf("退出通讯录\n");
			break;
		default:
			printf("输入错误，请重新输入：");
		}

	} while (m);
	return 0;
}