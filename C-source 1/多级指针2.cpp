/*
	2017-11-26 15:28:51
	�ʼ�
	�༶ָ��纯��ʹ�ã� 
*/
#include <stdio.h>

void f(int ** b)
{
	printf("%d", **b);	// *b �ȼ��� a�� **b �ȼ��� i�� 
}

void g(void)
{
	int i = 5;
	int * a = &i;
	
	f(&a);	// a ��int *���� , &a ��int ** ����
	
}

int main(void)
{
	g();
	
	return 0;	
} 
