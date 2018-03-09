/*
	2017-11-26 00:15:34
	笔记
	关于如何用malloc()函数动态分配数组的举例； 
*/

#include <stdio.h>
#include <malloc.h> 

int main(void)
{
	int * pArr;
	int len;
	int i;
	
	//动态构造一维数组； 
	printf("请输入你要存放的元素的个数: ");
	scanf("%d", &len);
	pArr = (int *)malloc(4 * len);
	//本行动态的构造了一个一维数组, 该一维数组的长度是len, 该数组的数组名是pArr, 该数组的每个元素是int类型  类似于 int pArr[len]; 
	
	//对一维数组进行操作. 如：对动态一维数组进行赋值;
	for (i=0; i<len; ++i)
		scanf("%d", &pArr[i]);

	////对一维数组进行输出;
	printf("\n一维数组的内容是:\n");
	for (i=0; i<len; ++i)
		printf("%d\n", pArr[i]);
		
	free(pArr); //释放掉动态分配的数组； 
	
	
	return 0;
}
