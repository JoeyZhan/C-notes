#include <stdio.h>

int main(void)
{
	float score;
	
	printf("请输入您的考试成绩: ");
	scanf("%f", &score);
	
	if (score > 100)
	   printf("做梦呢~\n");
	else if (score >= 90 && score <= 100)
	   printf("真牛逼\n");
    else if (score >= 80 && score < 90)
	   printf("可以的，666\n");
	else if (score >= 60 && score < 80)
       printf("加油请努力\n");
    else if (score >= 0 && score < 60)
	   printf("没用的家伙！\n");
	else
	   printf("不要如此自卑! \n");
	
	return 0;
}
