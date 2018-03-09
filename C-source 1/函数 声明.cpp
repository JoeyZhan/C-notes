#include <stdio.h>

void cao(void); //声明，表示：让程序内部知道cao是个函数, 使cao函数（普通函数）可放在主函数后面 （默认情况下，普通函数只能放在主函数前）； 注意：分号不可丢！！！ 

int main(void)
{
	cao();
	
	return 0;
 } 
 
 void cao(void)
 {
 	printf("丢雷老母!\n");
 }
