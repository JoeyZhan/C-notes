#include <stdio.h>

struct FuckOff
{
	int pusy;
	float vigina;
	char fuck[100];
}; //�ֺŲ���ʡ�� 

int main(void)
{
	struct FuckOff fone = {666, 69.96, "žžž"};
	struct FuckOff *pfone = &fone;
	
	printf("%d %f %s\n", fone.pusy, fone.vigina, fone.fuck);
	printf("%d %f %s\n", pfone->pusy, pfone->vigina, pfone->fuck); //pfone->pusy ת���� (*pfone).pusy �ȼ��� fone.pusy;
	
	return 0;
}
