#include <stdio.h>

void f(int * p, int len) // len 为数组长度;
{
	int i;
	
	for (i=0; i<len; ++i)
	    printf("%d ", p[i]); // p[i] 等价于 *(p+i); 
	printf("\n");
}

int main(void)
{
	int a[6] = {1, 2, 4, 6, 8, 5};
	int b[4] = {5, 2, 8, 3};
	
	f(a, 6); // 6为数组长度 ，a为存储 a[6]数组 的 第一个地址 即a[0]的地址,  数据类型为 int * 类型; 
	f(b, 4); // 同上; 
	
	return 0;
}
