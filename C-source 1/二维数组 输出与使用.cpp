#include <stdio.h>

int main(void)
{
	int a[4][5] = {
	    {1, 2, 3, 4, 5},
	    {6, 7, 8, 9, 10},
	    {11, 12, 13, 14, 15},
	    {16, 17, 18, 19, 20}
	};
	int i, j;
	
	for (i=0; i<4; ++i)
	{
		for (j=0; j<5; ++j)
		    printf("%-10d", a[i][j]); //-10是指每个输出值向左对齐10个字节； 
		printf("\n");
	}
	
	
	return 0;
}
