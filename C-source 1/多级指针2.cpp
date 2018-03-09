/*
	2017-11-26 15:28:51
	笔记
	多级指针跨函数使用； 
*/
#include <stdio.h>

void f(int ** b)
{
	printf("%d", **b);	// *b 等价于 a； **b 等价于 i； 
}

void g(void)
{
	int i = 5;
	int * a = &i;
	
	f(&a);	// a 是int *类型 , &a 是int ** 类型
	
}

int main(void)
{
	g();
	
	return 0;	
} 
