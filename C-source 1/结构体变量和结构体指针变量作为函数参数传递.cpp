/*
	2017-11-30 22:48:14
	笔记 
	通过函数完成对结构体变量的输入和输出； 
*/

#include <stdio.h>
#include <string.h>		//strcpy函数在此头文件里； 

struct student
{
	char name[100];
	char sex;
	int age;
};	//注意分号不能省略； 

void inputstudent(struct student *);
void outstudent(struct student *);

int main(void)
{
	struct student st;	
	
	inputstudent(&st);	  
	
	outstudent(&st);	//输出，可以用指针也可以直接将内容发送给outstudent，但如果直接发送内容，就又复制了一次内容，增加了使用内存，所以通常使用指针就可以，指针只占4个字节（64位系统下占8位）； 
}

void inputstudent(struct student * pstu)
{
	strcpy(pstu->name, "张三");		//字符串拷贝；不能够写成pstu.name = "张三"；关于字符串处理的问题，自行查阅； 
	pstu->sex = 'M';
	pstu->age = 18; 
}

void outstudent(struct student * sstu)
{
	printf("NAME = %s\nSEX = %c\nAGE = %d", sstu->name, sstu->sex, sstu->age);
}







