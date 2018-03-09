/*
	2017-11-23 00:10:21
	
	笔记
	关于 一个指针变量占多少字节的问题； 
	
	总结：
	一个指针变量，无论它指向的变量占几个字节； 
	
	该指针变量本身只占四个字节； （在64位操作系统下 占8个字节）;
	
	一个变量的地址是用该变量首字节的地址来表示； 
	

*/


#include <stdio.h>

int main(void)
{
	int a = 3;
	char b = 'A';
	double c = 23.12;
	
	int * as = &a;
	char * bs = &b;
	double * cs = &c;		//此处的 as bs cs 变量所占的字节是一样的； 
	
	printf("%d %d %d", sizeof(as), sizeof(bs), sizeof(cs));  //一个指针变量无论它指向的变量占几个字节, 该指针变量本身只占 4个字节,（在64位操作系统下占 8个字节）;
	/*
		sizeof语句
		
		sizeof(数据类型)
		
		功能：返回值就是该数据类型所占的字节数
		例子：sizeof(int) = 4  sizeof(char) = 1
		sizet(double) = 8
		
		sizeof(变量名)
		功能：返回值是该变量所占的字节数 
	*/
	
	return 0;
}
