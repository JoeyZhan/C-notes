/*
	2017-11-27 13:12:24 
	�ʼ� 
	cgets()������ʹ�ã� 	(turbo c P241)
	
	����һ�� cgets()������str�ĳ�������Ϊ str[0]+2 ���ַ�����Ϊstr[2];
	��ϸ���ݣ�turbo c P241���� 
	�������⣺���÷�ʽ: char * cgets(char * srt) �Ǵ���ģ����� ��dev c++��������л����(.text+0x19): undefined reference to `cgets' 
			   Ӧ����:	char * _cgets(char * buffer) !!! 
*/ 
#include <stdio.h>
#include <conio.h>	//��Ļ���������� 

int main(void)
{
	char str[82];	// str[0]�洢��������� ���ȣ�str[1]�洢���� �ַ�������ʵ����������ݴ洢�� str[2]��ʼ�����; 
	char * i;
	str[0] = 80; 
  //i = cgets; 	error: cgets() �����ĵ��÷�ʽӦΪ char * _cgets(char * buffer); 
	i = _cgets(str);		//cgets()�������óɹ�ʱ������ָ�� str[2] ��ָ�룬���򷵻� Null�� 
	
	printf("cget got %d characters: \"%s\"\n", str[1], i);	//	\" Ϊת�����з���, �������һ�� "��˫���ţ� �� ' �������ţ���  %sΪ�ַ�����%cΪ�����ַ��� 
	
	return 0;
}

/*
	��ʽ��char ������[����]��
		  char * ָ���������
		  ������[0] = ����-2��
		  ָ������� = _cgets(������); 
*/
