#include <stdio.h>

int main(void)
{
	int i = 123;
	int * n; // int * ������ͱ�����ַ ;
	int * m;
	
	n = &i; //�� i �����ĵ�ַ����� n�� 
	
	*n = i; // *n ���� n ������Ϊ��ַ�ı���; 
//	*m = *n;  error, *m������ֵ�����ڵ��ڴ���Ƶ�ԪȨ��û����Ȩ�ڱ����� 
	
	printf("%d", *n);
//	printf("%d", *m);   error, ͬ��; 
	
	return 0;
}
