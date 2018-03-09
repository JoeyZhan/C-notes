#include <stdio.h>

bool IsPrime(int m)
{
	int j;
	for (j=2; j<m; ++j)
		{
			if (0 == m%j)
			   break;
		}
		if (m == j)
		   return true;
		else
		   return false;
}

int main(void)
{
	int val;
	int i;
	
	printf("请输入需要判断的数: ");
	scanf("%d", &val);
	
	for (i=2; i<=val; ++i)
	{
		if (IsPrime(i))
		   printf("%d\n", i);
	}
	
	
	
	return 0;
}
