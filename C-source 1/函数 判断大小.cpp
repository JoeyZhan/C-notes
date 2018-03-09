#include <stdio.h>

void max (int i, int j)
{
	if (i > j)
	   printf("%d\n", i);
	else 
	   printf("%d\n", j);
}

int main(void)
{
	int a, b, c, d, e, f;
	a = 1, b = 2, c = 5, d = -7, e = 113, f = 23;
	
	max(a, b);
	max(c, d);
	max(e, f);	
	
	return 0;
 } 
