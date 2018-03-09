#include <stdio.h>

int main(void)
{
	/* 
	int i;
	
	for (i=0; i<=4; ++i)
	{
		if (i < 4)
		   break;  //break不能直接用于if，只能用于循环，所以这里终止的是for; 
		printf("丢雷楼谋!\n");
	}
	
	*/
	
	
	/*
	int i, j;
	
	for (i=0; i<3; ++i)
	{
		for (j=0, j<4, ++i)
		    break;   //break只能终止距离它最近的for； 
		printf("儿砸们好！\n");  
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
			break; // 终止的是第二个switch， 也是距离它最近的switch； 
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
