#include <stdio.h>

int main(void)
{
	int val;
	
	printf("������¥�㣺");
	scanf("%d", &val);
	
	switch (val)
	{
		case 1:
			printf("һ��!\n");
			break;
		case 2:
			printf("����!\n");
			break;
		case 3:
			printf("����!\n");
			break;
		default:
			printf("��δ�Ǻ�!\n");
			break;	
	}
	
	
	return 0;
}
