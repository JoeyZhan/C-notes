/*
	2017-11-26 23:26:26
	笔记
	关于动态内存跨函数使用； 
	
	静态内存 是存储在 栈 里面的，当一个函数执行完毕后就会 出栈；
	动态内存 是存储在 堆 里面的，当一个函数执行完毕后不会自动释放此内存，需要由程序员手动释放；
*/

#include <stdio.h>
#include <malloc.h>

void f(int ** l)
{
	*l = (int *)malloc(sizeof(int));	//sizeof(数据类型) 返回该数据类型所占的字节数； 
										//等价于 i = (int *)malloc(sizeof(int));
  //l = 5; 		error l是 int ** 类型，存储的是i的地址；
  //*l = 5;		error *l等价于i，则 *l = 5 等价于 i = 5，而 i 是int *类型，只能存放指针变量； 
	**l = 5;	// **l 等价于 *i； 
}

int main(void)
{
	int * i;
	
	f(&i);
	
	printf("%d", *i);
	free(i);
	
	return 0;
}
