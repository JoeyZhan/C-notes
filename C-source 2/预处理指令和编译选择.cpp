/*
	2017-11-22 00:11:52
	��������;Ϊ �ʼ� 
	���� Ԥ����ָ��ͱ���ѡ�� ������÷� 
	�ο��鱾turbo c P142
	δѧ��#line, #pragma 
*/

#include <stdio.h>
#define HOBY "1024\n" // ��ʽ��#define ������� �ַ��� �� ������������ô�д�ַ������ڶ�����ʱһ�ۿ����Ǻ궨�壻 ���ܣ������������������� ������� �滻��������� �ַ����� 
#define X 300   // ���滻�����Դ�����ʽ���� ����������� turbo c P143; 
#define Y 200

int main(void)
{
	#if X<200	// #if #elif #else ������ if, else if, else ��ͬ, ���� #elif �� else if;  ÿ��ʹ�� #if ָ�����Ҫһ�� #endif ������#if ; 
		printf("X\n");
	#elif Y>100
		printf("Y\n");	//  #else ������24�е� #ifdef �� #ifndef��Ƕ��ʹ��, �� #elif �����ԣ����� 
	#else
		printf("error");
	#endif		// #endif ���ڽ��� #if #ifdef #ifndef �����;  
	
	#ifdef HOBY		// #ifdef ָ�� �Ĺ���Ϊ �жϺ��Ƿ��ж��壬 ��˼�� ����� �� ���� ��ִ���������;  ��ʽΪ��#ifdef ������� ; 
		printf(HOBY);
	#endif
	
	#ifndef z     // #ifndef ָ�� �Ĺ���Ϊ �жϺ��Ƿ��ж��壬 ��˼�� ����� δ ���� ��ִ���������;  ������� #ifndef ��if no define����д�� 
//	#error ָ�� �����ֶ�ʹ������������������뵽�����������޷�����ɹ��� 
		printf("error\n");
	#endif
	
	printf(HOBY);
	
	return 0;
}
