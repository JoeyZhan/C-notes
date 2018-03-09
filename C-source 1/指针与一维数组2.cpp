#include <stdio.h>

void f(int * i, int len) // i存储的是 a (14行)的内容, 即 等价于 a; 
{
	i[3] = 66; // i[3] 等价于 *(i+3), 也等价于 a[3] ;   数据类型为 int 类型变量; 
}

int main(void)
{
	int a[6] = {1, 2, 3, 4, 5, 6};
	
	printf("%d\n", a[3]);
	
	f(a, 6);
	
	printf("%d\n", a[3]);
	
	
	return 0;
}
