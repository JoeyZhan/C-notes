#include <stdio.h>

int main(void)
{
	/* 
	int i;
	
	for (i=0; i<=4; ++i)
	{
		if (i < 4)
		   break;  //break����ֱ������if��ֻ������ѭ��������������ֹ����for; 
		printf("����¥ı!\n");
	}
	
	*/
	
	
	/*
	int i, j;
	
	for (i=0; i<3; ++i)
	{
		for (j=0, j<4, ++i)
		    break;   //breakֻ����ֹ�����������for�� 
		printf("�����Ǻã�\n");  
	}
	*/
	
	int x = 1, y = 0, a = 3, b = 4;
	
	switch (x)
	{
	case 1:
		switch (y)
		{
		case 0:
			a++;
			break; // ��ֹ���ǵڶ���switch�� Ҳ�Ǿ����������switch�� 
		case 1: 
		    b++;
		    break;
		}
		break;
	case 2:
		a++;
		b++;
		break;
	}
	
	printf("a = %d, b = %d\n", a, b);
	
	return 0;
}
