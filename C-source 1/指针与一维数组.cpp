#include <stdio.h>

void f(int * p, int len) // len Ϊ���鳤��;
{
	int i;
	
	for (i=0; i<len; ++i)
	    printf("%d ", p[i]); // p[i] �ȼ��� *(p+i); 
	printf("\n");
}

int main(void)
{
	int a[6] = {1, 2, 4, 6, 8, 5};
	int b[4] = {5, 2, 8, 3};
	
	f(a, 6); // 6Ϊ���鳤�� ��aΪ�洢 a[6]���� �� ��һ����ַ ��a[0]�ĵ�ַ,  ��������Ϊ int * ����; 
	f(b, 4); // ͬ��; 
	
	return 0;
}
