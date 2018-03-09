//素数也称质数，定义：除1与自身之外，无法用其他的数整除的数称为素数 ； 

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
	printf("请输入想要判断的数: ");
	scanf("%d", &m);
	
	if ( IsPrime(m) )
	   printf("Yes!\n\n");
	else 
	   printf("No!\n\n");
	   
	printf("继续或结束(Y/N):");
	scanf(" %c", &ch);
	printf("\n");
	} while ('y' == ch || 'Y' == ch);
	

	return 0;
}
