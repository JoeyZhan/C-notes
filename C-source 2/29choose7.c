#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

int * Pseudo_random(void);						//伪随机数生成函数
int * Lottery_draw(void);						//选号函数
void Compare(int * random, int * lucky_numb);	//对比并抽奖和开奖函数

int main(void)
{
	char ch;		//判断是否继续的变量
	
	do
	{
	    int * random = Pseudo_random();    
	    int * lucky_numb = Lottery_draw();
	    Compare(random, lucky_numb);
	    
		printf("\t\t| 是否需要继续抽奖(Y/N): ");
		scanf(" %c", &ch);
	}while ('y' == ch || 'Y' == ch);										//循环判断是否继续抽奖
    printf("\t\t|------------------------------------------------\n");
    
    return 0;
}

int * Pseudo_random(void)
{
	int i, j;	//临时变量
	int * random = (int *)malloc(8 * sizeof(int));	//动态构造数组
	
    srand((int)time(0));					//时间种子
    for (i=0; i<8; ++i)
    {
    	random[i] = rand()%(29-1+1) + 1;	//指定范围内伪随机数生成算法:	rand()%(max-min+1) + min;
    }
    
    return random;		//返回random动态数组的内存单元地址
}

int * Lottery_draw(void)
{
	int i;
	int * lucky_numb = (int *)malloc(8 * sizeof(int));	//动态构造数组
	system("cls");
	printf("\n\n\n");
	printf("\t\t|-------------------29-Choose-7------------------\n");
	printf("\t\t| 请选择7个 1-29 中任意数值:                     \n");
	for (i=0; i<7; ++i)
	{
		printf("\t\t| 请输入第 %d 个数值: ", i+1);		//输入抽奖数值
		scanf("%d", &lucky_numb[i]);
	}
	printf("\t\t|--------------------Good-Luck-------------------\n");
	
	return lucky_numb;		//返回幸运用户抽奖的动态数组
}

void Compare(int * random, int * lucky_numb)
{
	int i;
	int cnt = 0;							//统计中奖号码个数
	int special = 0;						//统计是否中奖特殊号
	for (i=0; i<8; ++i)
	{
		if (random[i] == lucky_numb[i])		//对比抽奖号码和开奖号码
			++cnt;
		else (random[7] == lucky_numb[i]);
			++special;
	}
	
	printf("\t\t| 开奖号码: ");
	for (i=0; i<7; ++i)
	{
		printf("%d ", random[i]);			//输出开奖号码
	}
	printf(" 特别号: %d", random[7]);		//输出特别号
	printf("\n");
	
	printf("\t\t| 您的号码: ");				
	for (i=0; i<7; ++i)
	{
		printf("%d ", lucky_numb[i]);		//输出抽奖号码
	}
	printf("\n");
	
	printf("\t\t| 抽奖结果:");
	
	if (cnt == 7)								//判断并输出奖项
		printf(" 恭喜您获得了: 一等奖!\n");
	else if (cnt == 6 && special == 1)
		printf(" 恭喜您获得了: 二等奖!\n");
	else if (cnt == 6)
		printf(" 恭喜您获得了: 三等奖!\n");
	else if (cnt == 5 && special == 1)
		printf(" 恭喜您获得了: 四等奖!\n");
	else if (cnt == 5)
		printf(" 恭喜您获得了: 五等奖!\n");
	else if (cnt == 4 && special == 1)
		printf(" 恭喜您获得了: 六等奖!\n");
	else if (cnt == 4)
		printf(" 恭喜您获得了: 七等奖!\n");
	else
		printf(" 谢谢惠顾!\n");
	
	printf("\t\t|------------------------------------------------\n");
}

//2018-06-30 17:17:03 by Joeyzhan
