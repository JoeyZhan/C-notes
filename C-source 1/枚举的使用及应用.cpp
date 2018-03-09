/*
	2017-12-04 14:01:27
	笔记
	关于枚举的使用 及其 应用； 
	
	枚举就是 把一个事物所有可能的取值一一列举出来
	
	枚举的优缺点
	代码更安全
	书写麻烦

*/ 

#include <stdio.h>

enum weekday
{
	Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday	//Monday的值默认为0，其后的变量为1 2 3...这样排序，若给 Monday赋值，Monday =5，其后的变量则为 6 7 8...； 
};		//定义了一个变量（枚举），且可用的值只有以上七个；安全性高！ 

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
