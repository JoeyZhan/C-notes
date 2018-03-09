#include <stdio.h>

int max(int i, int j)
{
	if (i > j)
	   return i;
	else
	   return j;
}

int main(void)
{
	int a, b, c, d, e, f;
	a = 1, b = 3, c = 6, d = -21, e = 9123, f = -232;
		
	printf("%d\n", max(a, b));
	printf("%d\n", max(c, d));
	printf("%d\n", max(e, f));
	
	return 0;
}
