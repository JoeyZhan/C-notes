#include <stdio.h>

int main(void)
{
	int i, j;
	
	for (i=0; i<=5; ++i)
	{
		printf("111\n");
		for (j=1; j<=3; ++j)
		{
			printf("222\n");
			printf("333\n");
		}
		printf("444\n");
	}
	
	return 0;
}
