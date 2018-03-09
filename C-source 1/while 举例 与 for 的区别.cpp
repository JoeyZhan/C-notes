#include <stdio.h>

int main(void)
{
	int i;
	int sum = 0;
	
	i = 0;
	while (i<=10)
	{
		sum += i;
		++i;
	}
	
	/* 等价于以下for
	for (i=0; i<=100; ++i)
	{
	    sum += i;
    }
	
	*/
	
	printf("sum = %d", sum);
	
	return 0;
}

//虽然while与for表达一样，但for逻辑性更强，更难出错。 
