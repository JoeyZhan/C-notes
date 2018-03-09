/*
	2017-11-28 14:42:00
	笔记
	如何定义结构体 
	
	什么叫结构体
	把一些基本类型数据组合在一起形成的一个新的复合数据类型，这个叫做结构体。 
	
	问题！！！
	st->age = 18 与 st.age = 18 到底等不等价！！！ 
	
	注意！！！ 
	给 结构体变量 赋值与输出时，要注意变量的类型！！！
	例如：struct student * pst1 = &st1;
		  pst1->age = 18; 这里不能改成 pst1.age = 18; 因为 pst1->age = 18 会转化成 (*pst1).age = 18; 数据类型不一致！ 
	 
*/ 
#include <stdio.h>

struct student	//定义了一个结构体 ，也可以说是定义了一个新的数据类型； 
{
	int age;
	float score;
	char sex;
};		//注意！！！这里要加分号； 

int main(void)
{
	struct student st1 = {18, 66.6f, 'M'};	// 定义了一个 叫 st1的struct student数据类型（结构体）变量，且给它赋值；
	struct student * pst1 = &st1;			
	//结构体变量，定义的同时可以整体赋初值，如果定义完之后，则只能单个的赋初值； 
	
	pst1->age = 18;		//指针变量名->成员名, 在计算机内部会被转化成  (*指针变量名).成员名  的方式来执行;
	
	pst1->score = 66.6f;		//66.6在C语言中默认是double类型，如果希望一个实数是float类型，则必须在末尾加f或F, 因此66.6是double, 66.6f或66.6F是float； 
	
	pst1->sex = 'M'; 	// pst1所指向的那个结构体变量中的 sex 这个成员;
	
	printf("st1: age = %d\nscore = %f\nsex =  %c\n", st1.age, st1.score, st1.sex); 
	printf("pst1: age = %d\nscore = %f\nsex =  %c\n", pst1->age, pst1->score, pst1->sex); //这里的pst1变量与st1是同一个，因为pst1指向st1，所以就算将33 35 37行删掉，也一样输出；要是33 35 37行的值修改，改成其他不一样的值，st1的也随之改变，因为pst1指向st1； 
	//这里的st1.成员名 不能改成 st1->成员名，因为st1->age会转化成 (*st1).age, 而 st1 是struct student类型，而不是struct student * 类型；
	 
	return 0;
}
