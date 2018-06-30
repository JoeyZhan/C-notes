#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

int * Pseudo_random(void);						//α��������ɺ���
int * Lottery_draw(void);						//ѡ�ź���
void Compare(int * random, int * lucky_numb);	//�ԱȲ��齱�Ϳ�������

int main(void)
{
	char ch;		//�ж��Ƿ�����ı���
	
	do
	{
	    int * random = Pseudo_random();    
	    int * lucky_numb = Lottery_draw();
	    Compare(random, lucky_numb);
	    
		printf("\t\t| �Ƿ���Ҫ�����齱(Y/N): ");
		scanf(" %c", &ch);
	}while ('y' == ch || 'Y' == ch);										//ѭ���ж��Ƿ�����齱
    printf("\t\t|------------------------------------------------\n");
    
    return 0;
}

int * Pseudo_random(void)
{
	int i, j;	//��ʱ����
	int * random = (int *)malloc(8 * sizeof(int));	//��̬��������
	
    srand((int)time(0));					//ʱ������
    for (i=0; i<8; ++i)
    {
    	random[i] = rand()%(29-1+1) + 1;	//ָ����Χ��α����������㷨:	rand()%(max-min+1) + min;
    }
    
    return random;		//����random��̬������ڴ浥Ԫ��ַ
}

int * Lottery_draw(void)
{
	int i;
	int * lucky_numb = (int *)malloc(8 * sizeof(int));	//��̬��������
	system("cls");
	printf("\n\n\n");
	printf("\t\t|-------------------29-Choose-7------------------\n");
	printf("\t\t| ��ѡ��7�� 1-29 ��������ֵ:                     \n");
	for (i=0; i<7; ++i)
	{
		printf("\t\t| ������� %d ����ֵ: ", i+1);		//����齱��ֵ
		scanf("%d", &lucky_numb[i]);
	}
	printf("\t\t|--------------------Good-Luck-------------------\n");
	
	return lucky_numb;		//���������û��齱�Ķ�̬����
}

void Compare(int * random, int * lucky_numb)
{
	int i;
	int cnt = 0;							//ͳ���н��������
	int special = 0;						//ͳ���Ƿ��н������
	for (i=0; i<8; ++i)
	{
		if (random[i] == lucky_numb[i])		//�Աȳ齱����Ϳ�������
			++cnt;
		else (random[7] == lucky_numb[i]);
			++special;
	}
	
	printf("\t\t| ��������: ");
	for (i=0; i<7; ++i)
	{
		printf("%d ", random[i]);			//�����������
	}
	printf(" �ر��: %d", random[7]);		//����ر��
	printf("\n");
	
	printf("\t\t| ���ĺ���: ");				
	for (i=0; i<7; ++i)
	{
		printf("%d ", lucky_numb[i]);		//����齱����
	}
	printf("\n");
	
	printf("\t\t| �齱���:");
	
	if (cnt == 7)								//�жϲ��������
		printf(" ��ϲ�������: һ�Ƚ�!\n");
	else if (cnt == 6 && special == 1)
		printf(" ��ϲ�������: ���Ƚ�!\n");
	else if (cnt == 6)
		printf(" ��ϲ�������: ���Ƚ�!\n");
	else if (cnt == 5 && special == 1)
		printf(" ��ϲ�������: �ĵȽ�!\n");
	else if (cnt == 5)
		printf(" ��ϲ�������: ��Ƚ�!\n");
	else if (cnt == 4 && special == 1)
		printf(" ��ϲ�������: ���Ƚ�!\n");
	else if (cnt == 4)
		printf(" ��ϲ�������: �ߵȽ�!\n");
	else
		printf(" лл�ݹ�!\n");
	
	printf("\t\t|------------------------------------------------\n");
}

//2018-06-30 17:17:03 by Joeyzhan
