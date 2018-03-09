/*
	2017-11-24 20:20:32
	笔记
	关于malloc函数的用法；
	
	malloc 是 memory（内存） allocate（分配） 的缩写； 
*/

#include <stdio.h>
#include <malloc.h>

int main(void)
{	
	int a = 5;		//静态分配 
	int * i = (int *)malloc(4);		//动态分配
	/*
		1. 要使用malloc函数，必须添加 malloc.h 这个头文件；
		2. malloc 函数只有一个形参，并且形参为整数；
		3. 括号里的 4 表示请求系统为本程序分配 4 个字节；
		4. malloc函数只能返回第一个字节的地址； 
		5. 在64位系统下 第15行分配了 12个字节， i变量占8个字节，i所指向的内存占4个字节；
		   在32位系统下 第15行分配了 8个字节， i变量占4个字节，i所指向的内存也占4个字节；
		6. i本身所占的内存是 静态分配 的， i所指向的内存是 动态分配 的； 
	*/ 
	*i = 5;
		
	printf("%d\n", *i);
	
	free(i);	// free(i) 表示把 i 所指向 的内存给释放掉；		i 本身的内存是静态的，不能由程序员手动释放，i 本身的内存只能在 i 变量所在的函数运行终止时由系统自动释放； 
	
	printf("%d\n", *i);
	
	return 0;
}
