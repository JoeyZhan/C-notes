#include <stdio.h>

void f(int * i, int len) // i�洢���� a (14��)������, �� �ȼ��� a; 
{
	i[3] = 66; // i[3] �ȼ��� *(i+3), Ҳ�ȼ��� a[3] ;   ��������Ϊ int ���ͱ���; 
}

int main(void)
{
	int a[6] = {1, 2, 3, 4, 5, 6};
	
	printf("%d\n", a[3]);
	
	f(a, 6);
	
	printf("%d\n", a[3]);
	
	
	return 0;
}
