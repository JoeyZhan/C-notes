/*
	2017-12-04 14:01:27
	�ʼ�
	����ö�ٵ�ʹ�� ���� Ӧ�ã� 
	
	ö�پ��� ��һ���������п��ܵ�ȡֵһһ�оٳ���
	
	ö�ٵ���ȱ��
	�������ȫ
	��д�鷳

*/ 

#include <stdio.h>

enum weekday
{
	Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday	//Monday��ֵĬ��Ϊ0�����ı���Ϊ1 2 3...������������ Monday��ֵ��Monday =5�����ı�����Ϊ 6 7 8...�� 
};		//������һ��������ö�٣����ҿ��õ�ֵֻ�������߸�����ȫ�Ըߣ� 

void f(enum weekday);

int main(void)
{
	f(Friday);
	
	return 0;
}

void f(enum weekday i)
{
	switch (i)
	{
		case 0:
			printf("Monday!\n");
			break;
		case 1:
			printf("Tuesday!\n");
			break;
		case 2:
			printf("Wednesday!\n");
			break;
		case 3:
			printf("Thursday!\n");
			break;
		case 4:
			printf("Friday!\n");
			break;
		case 5:
			printf("Saturday!\n");
			break;
		case 6:
			printf("Sunday!\n");
			break;
	}
}
