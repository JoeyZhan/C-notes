#include <stdio.h>

int main(void)
{
	int i;
	int count = 0;
	
	for (i=1; i<=512589; ++i)
	{
		if(i%2 == 1)
		  ++count;
	}
	printf("count = %d\n", count);
	
	return 0;
}
