/*
	2017-11-22 00:11:52
	本程序用途为 笔记 
	关于 预处理指令和编译选择 的相关用法 
	参考书本turbo c P142
	未学：#line, #pragma 
*/

#include <stdio.h>
#define HOBY "1024\n" // 格式：#define 宏替代名 字符串 ； 宏替代名尽量用大写字符，便于读程序时一眼看出是宏定义； 功能：将程序中所有遇到的 宏替代名 替换成所定义的 字符串； 
#define X 300   // 宏替换名可以带有形式参数 具体内容详见 turbo c P143; 
#define Y 200

int main(void)
{
	#if X<200	// #if #elif #else 功能与 if, else if, else 相同, 其中 #elif 是 else if;  每次使用 #if 指令，都需要一个 #endif 来结束#if ; 
		printf("X\n");
	#elif Y>100
		printf("Y\n");	//  #else 可以在24行的 #ifdef 和 #ifndef中嵌套使用, 但 #elif 不可以！！！ 
	#else
		printf("error");
	#endif		// #endif 用于结束 #if #ifdef #ifndef 等语句;  
	
	#ifdef HOBY		// #ifdef 指令 的功能为 判断宏是否有定义， 意思即 如果宏 已 定义 则执行以下语句;  格式为：#ifdef 宏替代名 ; 
		printf(HOBY);
	#endif
	
	#ifndef z     // #ifndef 指令 的功能为 判断宏是否有定义， 意思即 如果宏 未 定义 则执行以下语句;  个人理解 #ifndef 是if no define的缩写； 
//	#error 指令 用于手动使程序出错，当编译器编译到这里，将会出错，无法编译成功； 
		printf("error\n");
	#endif
	
	printf(HOBY);
	
	return 0;
}
