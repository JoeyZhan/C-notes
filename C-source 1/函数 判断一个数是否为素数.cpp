//����Ҳ�����������壺��1������֮�⣬�޷���������������������Ϊ���� �� 

#include <stdio.h>

bool IsPrime(int val)
{
	int i;
	
	for (i=2; i<val; ++i)
	{
		if (val%i == 0)
		   break;
	}
	if (i == val)
	   return true;
	else
	   return false;
}

int main(void)
{
	int m;
	char ch;
	
	do
	{
	printf("��������Ҫ�жϵ���: ");
	scanf("%d", &m);
	
	if ( IsPrime(m) )
	   printf("Yes!\n\n");
	else 
	   printf("No!\n\n");
	   
	printf("���������(Y/N):");
	scanf(" %c", &ch);
	printf("\n");
	} while ('y' == ch || 'Y' == ch);
	

	return 0;
}
