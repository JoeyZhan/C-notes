#include <stdio.h>

int main(void)
{
	int i;
	char ch;
	
	printf("请输入 i 的值: ");
	scanf("%d", &i);
	printf("i = %d\n", i);
	
	while ( (ch=getchar()) != '\n')
	      continue;
	      
	printf("请输入 j 的值: "); 
    int j;
    scanf("%d", &j);
    printf("j = %d\n", j);
	
	return 0;
}
