#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 10

int rand_num()
{
    return rand()%99;    
}

char rturn(int imp)
{
    switch(imp)
    {
	case 0:return '0';break;
	case 1:return '@';break;
	case 2:return 'p';break;
	defaul:return '#';
    }
}

void p_map(int map[M][M])
{
    int i;
    int j;
    for(i = 0 ; i < M ; i++)
    {
	for(j = 0 ; j < M ; j++)
	{
	    printf("%c ",rturn(map[i][j]));
	}
	printf("\n");
    }
}


int main()
{
    int i;
    int j;
    int m[M][M] = {0};
    for(i = 0 ; i < M ; i++)
    {
	for(j = 0 ; j < M ;j++)
	{
	    m[i][j] = 0;
	}
    }
    for(i = 0 ; i < M ; i++)
    {
	int mousex = rand_num()%M;
	int mousey = rand_num()%M;
	if(m[mousex][mousey] == 1)
	{
	    i--;
	}
	else
	{
	    m[mousex][mousey] = 1;
	}	    
    }
    srand(time(0));
    int n;
    printf("请输入击打次数：");
    scanf("%d",&n);
    int hits = 0;
    int missed = 0;
    printf("一共有10个地鼠，请击打吧！\n");
    for(i = 0 ; i < n ; i++)
    {
	int x;
	int y;
	p_map(m);
	printf("请在0~9中输入您要打的横坐标\n");
	scanf("%d",&x);
	printf("请在0~9中输入您要打的纵坐标\n");
	scanf("%d",&y);
	if(m[x][y] == 1)
	{
	    printf("恭喜你打中了！！\n");
	    hits++;
	    m[x][y] = 2;
	}
	else if(m[x][y] == 0)
	{
	    printf("很遗憾没有打中哦～～\n");
	    missed++;
	    m[x][y] = 2;   
	}
	else
	{
	    printf("这个位置已经打过了，请重新选择！\n");
	    i--;
	}
	printf("游戏结束啦！\n你一共打中了%d次,未打中%d次\n",hits,missed);
    }
    return 0;
}