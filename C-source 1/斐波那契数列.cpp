/*
  斐波拉契序列 == 1 2 3 5 8 13 21 34... 
*/

#include <stdio.h>

int main(void)
{
	int n;
	int i;
	int f1, f2;
	int sum = 0;
	
	f1 = 1;
	f2 = 2;
	
	printf("请输入您要输入的项值：");
	scanf("%d", &n);
	
	if (1 == n)
	{
		sum = 1;
	}
	else if (2 == n)
	{
		sum = 2;
	}
	else
	{
		for (i=3; i<=n; ++i)
		{
			sum = f1 + f2;
			f1 = f2;
			f2 = sum;
		}
	}
	
	printf("%d\n", sum);
	 
	
	return 0;
}

/*试数; 
 
若n=3；

n=3, i=3; i<=n 成立；
sum = 1 + 2 = 3;
f1 = 2;
f2 = 3;

3+1=4=i, i<=n, 不成立；

------------------
若n=5;

n=5, i=3, i<=n 成立；
sum = 1+2=3;
f1 = 2;
f2 = 3;

3+1=4=i, n=5, i<=n 成立；
sum = 2+3=5;
f1 = 3;
f2 = 5;

4+1=5=i, n=5, i<=n 成立；
sum = 3+5=8;
f1 = 5;
f2 = 8;

5+1=6=i, n=5. i<=n 不成立；

*/
