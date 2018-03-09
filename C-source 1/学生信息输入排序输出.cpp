/*
	2017-12-03 14:36:56
	笔记
	学生信息管理程序
	有问题待解决！！！
	1.空白符问题，50行；
	2.函数模块化问题，81行；	 
*/ 

#include <stdio.h>
#include <malloc.h>

struct student
{
	char name[100];
	char sex;
	float score;
};

//void inputInformation(int, struct student **);
//void alg(int, struct student **);
//void outInformation(int, struct student **);

int main(void)
{
	int len;
	struct student * pArr;
	int i, j;
	struct student t;
	//char ch;
	
	printf("请输入学生人数：");
	scanf("%d", &len);
	
	pArr = (struct student *)malloc(len * sizeof(struct student));
	
/*	inputInformation(len, &pArr);
	alg(len, &pArr);
	outInformation(len, &pArr);
*/
	for (i=0; i<len; ++i)
	{
		printf("请输入学生信息：\n");
		printf("请输入%d个学生的信息：\n", i+1);
		
		printf("name = ");
		scanf("%s", pArr[i].name);
//		while ((ch=getchar()) != '\n')
//		continue;
		printf("sex = ");
		scanf(" %c", &pArr[i].sex);		//空白符的问题，待解决！！！ 
		
		printf("score = ");
		scanf("%f", &pArr[i].score);
	}
	
	for (i=0; i<len-1; ++i)
	{
		for (j=0; j<len-1-i; ++j)
		{
			if (pArr[j].score < pArr[j+1].score)	//冒泡排序 
			{
				t = pArr[j];
				pArr[j] = pArr[j+1];
				pArr[j+1] = t;
			}
		}
	}
	
	for (i=0; i<len; ++i)
	{
		printf("\n\n第%d个学生的信息：\n", i+1);
		
		printf("name = %s\n", pArr[i].name);
		printf("sex = %c\n", pArr[i].sex);
		printf("score = %f\n", pArr[i].score);
	}
	
	return 0;	
}
/*		函数模块化执行尚未解决， 在执行第二次输入学生信息的时候会出错！！！ 
void inputInformation(int clen, struct student ** cpArr)
{
	int i;
	
	for (i=0; i<clen; ++i)
	{
		printf("请输入学生信息：\n");
		printf("请输入%d个学生的信息：\n", i+1);
		
		printf("name = ");
		scanf("%s", cpArr[i]->name);

		printf("sex = ");
		scanf(" %c", &cpArr[i]->sex);
		
		printf("score = ");
		scanf("%f", &cpArr[i]->score);
	}
}

void alg(int len, struct student ** cpArr)
{
	int i, j;
	struct student * t;
	
	for (i=0; i<len-1; ++i)
	{
		for (j=0; j<len-1-i; ++j)
		{
			if (cpArr[j]->score < cpArr[j+1]->score)
			{
				*t = *cpArr[j];
				*cpArr[j] = *cpArr[j+1];
				*cpArr[j+1] = *t;
			}
		}
	}
}

void outInformation(int len, struct student ** cpArr)
{
	int i;
	
	for (i=0; i<len; ++i)
	{
		printf("第%d个学生的信息：\n", i+1);
		
		printf("name = %s\n", cpArr[i]->name);
		printf("sex = %c\n", cpArr[i]->sex);
		printf("score = %f\n", cpArr[i]->score);
	}
}*/
