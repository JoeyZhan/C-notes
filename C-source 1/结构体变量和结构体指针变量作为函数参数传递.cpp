/*
	2017-11-30 22:48:14
	�ʼ� 
	ͨ��������ɶԽṹ����������������� 
*/

#include <stdio.h>
#include <string.h>		//strcpy�����ڴ�ͷ�ļ�� 

struct student
{
	char name[100];
	char sex;
	int age;
};	//ע��ֺŲ���ʡ�ԣ� 

void inputstudent(struct student *);
void outstudent(struct student *);

int main(void)
{
	struct student st;	
	
	inputstudent(&st);	  
	
	outstudent(&st);	//�����������ָ��Ҳ����ֱ�ӽ����ݷ��͸�outstudent�������ֱ�ӷ������ݣ����ָ�����һ�����ݣ�������ʹ���ڴ棬����ͨ��ʹ��ָ��Ϳ��ԣ�ָ��ֻռ4���ֽڣ�64λϵͳ��ռ8λ���� 
}

void inputstudent(struct student * pstu)
{
	strcpy(pstu->name, "����");		//�ַ������������ܹ�д��pstu.name = "����"�������ַ�����������⣬���в��ģ� 
	pstu->sex = 'M';
	pstu->age = 18; 
}

void outstudent(struct student * sstu)
{
	printf("NAME = %s\nSEX = %c\nAGE = %d", sstu->name, sstu->sex, sstu->age);
}







