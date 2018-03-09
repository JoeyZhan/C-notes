#include <stdio.h>

int main(void)
{
	int val;
	
	printf("请输入楼层：");
	scanf("%d", &val);
	
	switch (val)
	{
		case 1:
			printf("一层!\n");
			break;
		case 2:
			printf("二层!\n");
			break;
		case 3:
			printf("三层!\n");
			break;
		default:
			printf("还未盖好!\n");
			break;	
	}
	
	
	return 0;
}
