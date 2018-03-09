# include <stdio.h>

int main(void)
{
	int i = 1;
	int j = 2;
	int t;
	
	t = i;
	i = j;
	j = t;
	
	printf("i = %d, j = %d", i, j);
	
	return 0;
}
