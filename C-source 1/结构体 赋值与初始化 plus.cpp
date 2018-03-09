#include <stdio.h>

struct FuckOff
{
	int pusy;
	float vigina;
	char fuck[100];
}; //分号不能省； 

int main(void)
{
	struct FuckOff fone = {666, 69.96, "啪啪啪"};
	struct FuckOff *pfone = &fone;
	
	printf("%d %f %s\n", fone.pusy, fone.vigina, fone.fuck);
	printf("%d %f %s\n", pfone->pusy, pfone->vigina, pfone->fuck); //pfone->pusy 转换成 (*pfone).pusy 等价于 fone.pusy;
	
	return 0;
}
