/*
	malloc�纯��ʹ�ã� 
	
	��������� 
*/

#include <stdio.h>
#include <malloc.h>

void input(int * i)
{
	scanf("%d", *&i);
}

void output(int * i)
{
	printf("%d", *i);
}

int main(void)
{
	int * i;
	i = (int*)malloc(sizeof(int));
	
	input(i);
	output(i);
	
	return 0;
}
