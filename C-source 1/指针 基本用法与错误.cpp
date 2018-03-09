#include <stdio.h>

int main(void)
{
	int i = 123;
	int * n; // int * 存放整型变量地址 ;
	int * m;
	
	n = &i; //将 i 变量的地址存放在 n； 
	
	*n = i; // *n 是以 n 的内容为地址的变量; 
//	*m = *n;  error, *m是垃圾值，所在的内存控制单元权限没有授权于本程序； 
	
	printf("%d", *n);
//	printf("%d", *m);   error, 同上; 
	
	return 0;
}
