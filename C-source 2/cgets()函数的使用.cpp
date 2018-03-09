/*
	2017-11-27 13:12:24 
	笔记 
	cgets()函数的使用； 	(turbo c P241)
	
	定义一个 cgets()函数，str的长度至少为 str[0]+2 个字符，即为str[2];
	详细内容（turbo c P241）； 
	发现问题：调用方式: char * cgets(char * srt) 是错误的！！！ 在dev c++编译软件中会出错：(.text+0x19): undefined reference to `cgets' 
			   应该是:	char * _cgets(char * buffer) !!! 
*/ 
#include <stdio.h>
#include <conio.h>	//屏幕操作函数； 

int main(void)
{
	char str[82];	// str[0]存储的是数组的 长度，str[1]存储的是 字符数，而实际输入的内容存储在 str[2]开始到最后; 
	char * i;
	str[0] = 80; 
  //i = cgets; 	error: cgets() 函数的调用方式应为 char * _cgets(char * buffer); 
	i = _cgets(str);		//cgets()函数调用成功时，返回指向 str[2] 的指针，否则返回 Null； 
	
	printf("cget got %d characters: \"%s\"\n", str[1], i);	//	\" 为转义序列符号, 用来输出一个 "（双引号） 或 ' （单引号）；  %s为字符串，%c为单个字符； 
	
	return 0;
}

/*
	格式：char 数组名[长度]；
		  char * 指针变量名；
		  数组名[0] = 长度-2；
		  指针变量名 = _cgets(数组名); 
*/
