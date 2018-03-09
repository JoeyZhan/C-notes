# include <stdio.h>

int main(void)
{
	int a, b, c;
	int t;
	
	printf("请输入三个值（中间用空格隔开）: ");
	scanf("%d %d %d", &a, &b, &c);
	
	if (a < b)
	{
		t = a;
		a = b;
		b = t;
	 } 
	if (a < c)
	{
		t = a;
		a = c;
		c = t;
	}
	if (b < c)
	{
		t = b;
		b = c;
		c = t;
	}
	
	printf("%d %d %d", a, b, c);
	
	return 0;
}
