#include <stdio.h>

int main(void)
{
	int i;
	int sum = 0;
	
	i = 0;
	while (i<=10)
	{
		sum += i;
		++i;
	}
	
	/* �ȼ�������for
	for (i=0; i<=100; ++i)
	{
	    sum += i;
    }
	
	*/
	
	printf("sum = %d", sum);
	
	return 0;
}

//��Ȼwhile��for���һ������for�߼��Ը�ǿ�����ѳ��� 
