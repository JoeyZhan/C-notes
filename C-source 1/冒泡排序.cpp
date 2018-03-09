#include <Stdio.h>

void sort(int * a, int len)
{
	int i, j;
	int t;
	
	for (i=0; i<len-1; ++i)
	{
		for (j=0; j<=len-1-i; ++j)
		{
			if (a[j] > a[j+1])
			{
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
}

int main(void)
{
	int a[6] = {42, 623, -321, 52, -98, 53};
	int i;
	
	sort(a, 6);
	
	for (i=0; i<6; ++i)
	{
		printf("%d ", a[i]);
	}
	
	return 0;
}
