#include <stdio.h>

int main(void)
{
	int i;
	char ch;
	
	printf("������ i ��ֵ: ");
	scanf("%d", &i);
	printf("i = %d\n", i);
	
	while ( (ch=getchar()) != '\n')
	      continue;
	      
	printf("������ j ��ֵ: "); 
    int j;
    scanf("%d", &j);
    printf("j = %d\n", j);
	
	return 0;
}
