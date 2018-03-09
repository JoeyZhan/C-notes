/*
	2017-11-26 15:11:24
	笔记
	多级指针的使用； 
*/ 

#include <stdio.h>

int main(void)
{
	int i = 5;
	
	int * a = &i;	// a 只能存放 int 变量的地址； 
	int ** b = &a;	// b 是 int ** 类型，所谓 int ** 类型就是指 b 只能存放 int * 类型变量的地址； 
	int *** c = &b;	// c 是 int *** 类型，所谓 int *** 类型就是指 c 只能存放 int ** 类型变量的地址； 
	
	//c = &a;  //error 因为 c是 int *** 类型，r只能存放 int ** 类型变量的地址； 
	printf("%d", ***c);	//输出结果是 5, ***c等价于i； 
	
	return 0;
}
