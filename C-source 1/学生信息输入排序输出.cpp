/*
	2017-12-03 14:36:56
	�ʼ�
	ѧ����Ϣ�������
	����������������
	1.�հ׷����⣬50�У�
	2.����ģ�黯���⣬81�У�	 
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
	
	printf("������ѧ��������");
	scanf("%d", &len);
	
	pArr = (struct student *)malloc(len * sizeof(struct student));
	
/*	inputInformation(len, &pArr);
	alg(len, &pArr);
	outInformation(len, &pArr);
*/
	for (i=0; i<len; ++i)
	{
		printf("������ѧ����Ϣ��\n");
		printf("������%d��ѧ������Ϣ��\n", i+1);
		
		printf("name = ");
		scanf("%s", pArr[i].name);
//		while ((ch=getchar()) != '\n')
//		continue;
		printf("sex = ");
		scanf(" %c", &pArr[i].sex);		//�հ׷������⣬����������� 
		
		printf("score = ");
		scanf("%f", &pArr[i].score);
	}
	
	for (i=0; i<len-1; ++i)
	{
		for (j=0; j<len-1-i; ++j)
		{
			if (pArr[j].score < pArr[j+1].score)	//ð������ 
			{
				t = pArr[j];
				pArr[j] = pArr[j+1];
				pArr[j+1] = t;
			}
		}
	}
	
	for (i=0; i<len; ++i)
	{
		printf("\n\n��%d��ѧ������Ϣ��\n", i+1);
		
		printf("name = %s\n", pArr[i].name);
		printf("sex = %c\n", pArr[i].sex);
		printf("score = %f\n", pArr[i].score);
	}
	
	return 0;	
}
/*		����ģ�黯ִ����δ����� ��ִ�еڶ�������ѧ����Ϣ��ʱ���������� 
void inputInformation(int clen, struct student ** cpArr)
{
	int i;
	
	for (i=0; i<clen; ++i)
	{
		printf("������ѧ����Ϣ��\n");
		printf("������%d��ѧ������Ϣ��\n", i+1);
		
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
		printf("��%d��ѧ������Ϣ��\n", i+1);
		
		printf("name = %s\n", cpArr[i]->name);
		printf("sex = %c\n", cpArr[i]->sex);
		printf("score = %f\n", cpArr[i]->score);
	}
}*/
