/*
	2017-11-26 00:15:34
	�ʼ�
	���������malloc()������̬��������ľ����� 
*/

#include <stdio.h>
#include <malloc.h> 

int main(void)
{
	int * pArr;
	int len;
	int i;
	
	//��̬����һά���飻 
	printf("��������Ҫ��ŵ�Ԫ�صĸ���: ");
	scanf("%d", &len);
	pArr = (int *)malloc(4 * len);
	//���ж�̬�Ĺ�����һ��һά����, ��һά����ĳ�����len, ���������������pArr, �������ÿ��Ԫ����int����  ������ int pArr[len]; 
	
	//��һά������в���. �磺�Զ�̬һά������и�ֵ;
	for (i=0; i<len; ++i)
		scanf("%d", &pArr[i]);

	////��һά����������;
	printf("\nһά�����������:\n");
	for (i=0; i<len; ++i)
		printf("%d\n", pArr[i]);
		
	free(pArr); //�ͷŵ���̬��������飻 
	
	
	return 0;
}
