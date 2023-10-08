#include"stdio.h"
#include"stdlib.h"
#define num 2


struct Student
{
	char no[10];
	float math;
	float phy;
	float english;
	float chinese;
	float pe;
	float average;
}stu[num];


#include"stdio.h"
#include"stdlib.h"
#define num 2
#define _CRT_SECURE_NO_WARNINGS 1

struct Student
{
	char no[10];
	float math;
	float phy;
	float english;
	float chinese;
	float pe;
	float average;
}stu[num];


void Avermath(struct Student *p,int n)
{
	int i;
	float ave=0,sum=0;
	for(i=0;i<n;i++)
		sum+=p[i].math;
	ave=sum/n;
	printf("\t%d名学生数学的平均成绩为:%.2f\n",n,ave);
	printf("\n");
}

void Faild(struct Student *p,int n)
{
	int i,count,total=0;
	float ave=0,sum=0;
	for(i=0;i<n;i++)
	{
		count=0;
		if(p[i].math<60)
			count++;
		if(p[i].phy<60)
			count++;
		if(p[i].english<60)
			count++;
		if(p[i].chinese<60)
			count++;
		if(p[i].pe<60)
			count++;
		if(count>2)
		{
			total++;
			sum=0;
			sum+=p[i].math;
			sum+=p[i].phy;
			sum+=p[i].english;
			sum+=p[i].chinese;
			sum+=p[i].pe;
			ave=sum/5;
			printf("\n\t该学生有两门以上的课程不及格信息为：");
			printf("\n\t学号：%s",p[i].no);
			printf("\n\t数学成绩：%f",p[i].math);
			printf("\n\t物理成绩：%f",p[i].phy);
			printf("\n\t英语成绩：%f",p[i].english);
			printf("\n\t语文成绩：%f",p[i].chinese);
			printf("\n\t体育成绩：%f",p[i].pe);
			printf("\n\t平均成绩为：%f",ave);
			printf("\n");
		}
	}
	if(total==0)
		printf("\t无两门以上课程不及格的学生！\n");
	printf("\n");
}

void Good(struct Student *p,int n)
{
	int i,count,total=0;
	float ave=0,sum;
	for(i=0;i<n;i++)
	{
		sum=0;
		sum+=p[i].math;
		sum+=p[i].phy;
		sum+=p[i].english;
		sum+=p[i].chinese;
		sum+=p[i].pe;
		ave=sum/5;
		count=0;
		if(p[i].math>80)
			count++;
		if(p[i].phy>80)
			count++;
		if(p[i].english>80)
			count++;
		if(p[i].chinese>80)
			count++;
		if(p[i].pe>80)
			count++;
		if(count==5||ave>85)
		{
			printf("\n\t该学生成绩优良且信息为：");
			printf("\n\t学号：%s",p[i].no);
			printf("\n\t数学成绩：%f",p[i].math);
			printf("\n\t物理成绩：%f",p[i].phy);
			printf("\n\t英语成绩：%f",p[i].english);
			printf("\n\t语文成绩：%f",p[i].chinese);
			printf("\n\t体育成绩：%f",p[i].pe);
			printf("\n\t平均成绩为：%f",ave);
			printf("\n");
			total++;
		}
	}
	if(total==0)
		printf("\t无成绩优良的学生！\n");
	printf("\n");
}
int main()
{
	int i,j;
	for(i=0;i<num;i++)
	{
		printf("\t请输入第%d名学生的数据",i+1);
		printf("\t学号:");
		scanf("%s",stu[i].no);
		printf("\t请输入第%d名学生数学的成绩",i+1);
		scanf("%lf",&stu[i].math);
		printf("\t请输入第%d名学生物理的成绩",i+1);
		scanf("%lf",&stu[i].phy);
		printf("\t请输入第%d名学生英语的成绩",i+1);
		scanf("%lf",&stu[i].english);
		printf("\t请输入第%d名学生语文的成绩",i+1);
		scanf("%lf",&stu[i].chinese);
		printf("\t请输入第%d名学生体育的成绩",i+1);
		scanf("%lf",&stu[i].pe);
		printf("\n");
	}
	Avermath(stu,num);
	Faild(stu,num);
	Good(stu,num);
	return 0;
}

















