#include <stdio.h>

int main(void)
{
	int i;
	int sum = 0;
	int count = 0;
	float average;
	
	for (i=1; i<=1257891; ++i)
	{
		if (i%2 == 1)
		{
			sum += i;
			++count;
		}
	}
	
	average = 1.0*sum / count;
	
	printf("sum = %d\n", sum);
	printf("count = %d\n", count);
	printf("average = %f\n", average);
	
	return 0;
}
