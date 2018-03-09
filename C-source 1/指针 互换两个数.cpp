#include <stdio.h>

void i(int *, int *);

int main(void)
{
	int n = 9;
	int m = 6;
	
	i(&n, &m);
	
	printf("n = %d m = %d", n, m);
	
	return 0;
}

void i(int * a, int * b)
{
	int t;
	
	t = *a;
	*a = *b;
	*b = t;
	
}
