#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <string.h>

#define LEN sizeof(struct student_Information)
#define FORMAT "%-8d%-10s%-15.1lf%-15.1f%-13.1f\n"
#define DATA stu[i].numb,stu[i].name,stu[i].elect,stu[i].requi,stu[i].t_p

struct student_Information
{
	int numb;		//ѧ��
	char name[10];	//����
	float elect;	//���޿η���
	float requi;	//ѡ�޿η���
	float t_p;		//�ܷ�
};

struct student_Information stu[32];

void menu(void);				//��ʾ���ܲ˵�����
void show_Inf(void);			//�������
void input_Inf(void);			//¼�뺯��
void search_Inf(void);			//���Һ���
void modify_Inf(void);			//�޸ĺ���
void delete_Inf(void);			//ɾ������
void rankings_Inf(void);		//��������
void score_analyze_Inf(void);	//�ɼ���������

int main(void)
{
	int n;
	menu();
	scanf("%d", &n);
	while (n)			//ѭ���ж��û�ѡ��Ĺ���
	{
		switch(n)
		{
			case 1:
				input_Inf();
				break;
			case 2:
				search_Inf();
				break;
			case 3:
				modify_Inf();
				break;
			case 4:
				delete_Inf();
				break;
			case 5:
				rankings_Inf();
				break;
			case 6:
				show_Inf();
			case 7:
				score_analyze_Inf();
			default:
				break;
		}
		getch();
		menu();
		scanf("%d",&n);
	}
	
	return 0;
}

void score_analyze_Inf(void)
{
	int i, m = 0;				//��ʱ����
	float elect_average = 0;	//���ڴ洢ƽ���ֵı���
	float requi_average = 0;
	float t_p_average = 0;
	FILE * fp;					//�ļ�ָ��
	
	if ((fp = fopen("data","ab+")) == NULL)		//�ж��Ƿ��/���� ���ļ�, ��������ֹ�ú���
	{ 
		printf("Can't open/find file!\n");
		return;
	}
	
	while (!feof(fp))							//������ļ�ָ���Ƿ��ѵ����ļ���β
		if (1 == fread(&stu[m], LEN, 1, fp))	//���ļ����ж�����
			++m;								//����һ��stu[m]����, m����
	fclose(fp);
	
	if (0 == m) 								//�ж��ļ��Ƿ�������
	{
		printf("No find information!\n");
		return;
	}
	
	printf("\nScore analyze:\n");
	for (i=0; i<m; ++i)							//�������ƽ����
	{
		elect_average += stu[i].elect;
		requi_average += stu[i].requi;
		t_p_average += stu[i].t_p;
	}
	//�������ƽ���ּ���߷���ͷ�
	printf("\t\tElective Average: %f\n\t\tRequired Average: %f\n\t\tTotal Average: %f\n", elect_average/i, requi_average/i, t_p_average/i);
	printf("\t\tTop score: %f\n\t\tLowest mark: %f\n", stu[m-1].t_p, stu[0].t_p);	
}

void rankings_Inf(void)
{ 
	struct student_Information t;	//��ʱ����
	int i=0, j=0, m=0;				//��ʱ����
	FILE * fp;						//�ļ�����
	
	if ((fp = fopen("data","ab+")) == NULL)		//�ж��Ƿ��/���� ���ļ�, ��������ֹ�ú���
	{ 
		printf("Can't open/find file!\n");
		return;
	}
	
	while (!feof(fp))							//������ļ�ָ���Ƿ��ѵ����ļ���β
		if (1 == fread(&stu[m], LEN, 1, fp))	//���ļ����ж�����
			++m;								//����һ��stu[m]����, m����
	fclose(fp);
		
	if (0 == m) 								//�ж��ļ��Ƿ�������
	{
		printf("No find information!\n");
		return;
	}
	
	for (i=0; i<m-1; ++i)
		for (j=i+1; j<m; ++j)		//˫��ѭ��ʵ�ֳɼ��Ƚϲ�����
			if (stu[i].t_p < stu[j].t_p)
			{ 
				t = stu[i];
				stu[i] = stu[j];
				stu[j] = t;
			}
			
	if ((fp = fopen("data","wb")) == NULL)		//�ж��Ƿ��ܹ�д���ļ�, ��������ֹ�ú���
	{ 
		printf("Can't open/find file!\n");
		return;
	}
	
	for (i=0; i<m; ++i)
		if (1 != fwrite(&stu[i], LEN, 1, fp))	//���޸ĺ��ѧ����Ϣд�������ļ�
		{ 
			printf("Can't save information!");
			getch();
		}
	fclose(fp);
	printf("Saved successfully!\n");
	show_Inf();		//������õ�ѧ����Ϣ�������
}

void delete_Inf(void)
{
	int s_numb, i, j, m = 0;	//��ʱ����
	char ch[3];					//�����ж��Ƿ����ѭ���ı���
	FILE * fp;					//�ļ�ָ��
	
	if ((fp = fopen("data", "ab+")) == NULL)	//�ж��Ƿ��/���� ���ļ�, ��������ֹ�ú���
	{
		printf("Can't open/find file!\n");
		return;
	}
	
	while (!feof(fp))							//������ļ�ָ���Ƿ��ѵ����ļ���β
		if (fread(&stu[m], LEN, 1, fp) == 1)	//���ļ����ж�����
			++m;								//����һ��stu[m]����, m����
	
	fclose(fp);
	if (0 == m)									//�ж��ļ��Ƿ�������
	{
		printf("No find information!\n");
		return;
	}
	
	printf("Please input the student number: ");
	scanf("%d", &s_numb);		//������Ҫɾ����ѧ����ѧ��
	
	for (i=0; i<m; ++i)			//�ж��û������ѧ�����ļ��洢���Ƿ����
		if (s_numb == stu[i].numb)	
			break;
	if (i == m)		//�ж��Ƿ��и�ѧ����Ϣ, û��������ú���
	{
		printf("No find information!\n");
		getchar();
		return;
	}
	
	printf("Finded the student information, Delete?(Y/N): ");
	scanf("%s", ch);
	
	if (0 == strcmp(ch, "Y") || 0 == strcmp(ch, "y"))	//�ж��Ƿ���������Ϣ
	{
		for (j=i; j<m; ++j)
			stu[j] = stu[j+1];		//����һ����Ϣ�Ƶ�ǰһ����Ϣ��λ��
		--m;
		printf("Deleted successfully!\n");
		
		if ((fp = fopen("data", "wb")) == NULL)		//�ж��Ƿ��ܹ�д���ļ�, ��������ֹ�ú���
		{
			printf("Can't open/find file!\n");
			return;
		}
		
		for (j=0; j<m; ++j)
			if (1 != fwrite(&stu[j], LEN, 1, fp))	//���޸ĺ��ѧ����Ϣд�������ļ�
			{
				printf("Can't save information!");
				getch();
			}
		
		fclose(fp);
	}
}

void modify_Inf(void)
{
	int i, j, s_numb, m = 0;	//��ʱ����
	FILE * fp;		//�ļ�����
	
	if ((fp = fopen("data", "ab+")) == NULL)	//�ж��Ƿ��/���� ���ļ�, ��������ֹ�ú���
	{
		printf("Can't open/find file!\n");		//������ļ�ָ���Ƿ��ѵ����ļ���β
		return;
	}
	
	while (!feof(fp))							//������ļ�ָ���Ƿ��ѵ����ļ���β
		if (fread(&stu[m], LEN, 1, fp) == 1)	//���ļ����ж�����
			++m;								//����һ��stu[m]����, m����
	if (m == 0)									//�ж��ļ��Ƿ�������
	{
		printf("No find information!\n");
		fclose(fp);
		return;
	}
	
	printf("Please input the student number that needs to be modify: ");
	scanf("%d", &s_numb);		//������Ҫ�޸ĵ�ѧ����ѧ��
	
	for (i=0; i<m; ++i)
		if (s_numb == stu[i].numb)		//�ж��û������ѧ�����ļ��洢���Ƿ����
			break;
		
	if (i<m)	//�ж��Ƿ��и�ѧ����Ϣ, û��������ú���
	{
		printf("Find the student! Please modify!\n");
		printf("Please input student information: \n");
		printf("Name: ");
		scanf("%s", stu[i].name);		//��������
		printf("Elective: ");
		scanf("%f", &stu[i].elect);		//������޿η���
		printf("Required: ");	
		scanf("%f", &stu[i].requi);		//����ѡ�޿η���
		stu[i].t_p = stu[i].elect + stu[i].requi;		//���Ķ����������������ܷ���
	}
	else
	{
		printf("Can't find student information!\n");
		getchar();
		return;
	}
	
	if ((fp = fopen("data", "wb")) == NULL)		//�ж��Ƿ��ܹ�д���ļ�, ��������ֹ�ú���
	{
		printf("Can't open/find file!\n");
		return;
	}
	
	for (j=0; j<m; ++j)
		if (1 != fwrite(&stu[j], LEN, 1, fp))	//���޸ĺ��ѧ����Ϣд�������ļ�
		{
			printf("Can't save information!");
			getch();
		}
		fclose(fp);
}

void search_Inf(void)
{
	int s_numb, i, m = 0;		//��ʱ����
	char ch[3];		//�����ж��Ƿ����ѭ���ı���
	FILE * fp;		//�ļ�ָ��
	
	if ((fp = fopen("data", "ab+")) == NULL)	//�ж��Ƿ��/���� ���ļ�, ��������ֹ�ú���
	{
		printf("Can't open/find file!\n");
		return;
	}
	
	while (!feof(fp))							//������ļ�ָ���Ƿ��ѵ����ļ���β
		if (fread(&stu[m], LEN, 1, fp) == 1)	//���ļ����ж�����
			++m;								//����һ��stu[m]����, m����
	fclose(fp);
	
	if (0 == m)									//�ж��ļ��Ƿ�������
	{
		printf("No find information!\n");
		return;
	}
	printf("Please input the student number: ");	
	scanf("%d", &s_numb);						//������Ҫ��ѯ��ѧ����ѧ��
	
	for (i=0; i<m; ++i)
		if (s_numb == stu[i].numb)				//�ж��û������ѧ�����ļ��洢���Ƿ����, ���������û������Ƿ��������
		{
			printf("Fined the student information, Show up?(Y/N): ");
			scanf("%s", ch);
			if (0 == strcmp(ch, "Y") || 0 == strcmp(ch, "y"))		//�ж��Ƿ���������Ϣ
			{
				printf("Number	Name	Elective	Required	Total Points\t\n");
				printf(FORMAT, DATA);	  //ʹ���Զ����ʽ���;
				break;
			}
			else
				return;
		}
		
		if (i == m)		//�����������ж���, ����ʾ�û�û�и�ѧ����Ϣ
			printf("Can't find the student information!\n");
}

void input_Inf(void)
{
	int i, m = 0;	//��ʱ����
	char ch[3];		//�����ж��Ƿ����ѭ���ı���
	FILE * fp;		//�ļ�ָ��
	
	if ((fp = fopen("data", "ab+")) == NULL)	//�ж��Ƿ��/���� ���ļ�, ��������ֹ�ú���
	{
		printf("Can't open/creat file!\n");
		return;
	}
	while (!feof(fp))							//������ļ�ָ���Ƿ��ѵ����ļ���β
	{
		if (1 == fread(&stu[m], LEN, 1, fp))	//���ļ����ж�����
			++m;								//����һ��stu[m]����, m����
	}
	fclose(fp);
	
	if (m == 0)									//�ж��ļ��Ƿ�������
		printf("No find information!");
	else
	{
		system("cls");							//�������dos����, ���������ѧ����Ϣ
		show_Inf();
	}
	if ((fp=fopen("data", "wb")) == NULL)		//�ж��Ƿ��/���� ���ļ�, ��������ֹ�ú���
	{
		printf("Can't open/find file!\n");
		return;
	}
	
	for (i=0; i<m; ++i)
		fwrite(&stu[i], LEN, 1, fp);			//���ļ�ԭ�������ٴ�������ļ�
	printf("Please input student information(Y/N): ");
	scanf("%s", ch);	//���û�ѡ���Ƿ�ִ��������Ϣ����
	
	while (0 == strcmp(ch, "Y") || 0 == strcmp(ch, "y"))	//�ж��Ƿ����������Ϣ
	{
		printf("Student number: ");
		scanf("%d", &stu[m].numb);		//����ѧ��
		for (i=0; i<m; ++i)
			if (stu[i].numb == stu[m].numb)		//�ж��û������ѧ���Ƿ������ļ��洢�е�ѧ���ظ�, �ظ����������, �ر������ļ�;
			{
				printf("The number already exists, Failed to enter information\n!");
				getch();
				fclose(fp);
				return;
			}
			
		printf("Name: ");
		scanf("%s", stu[m].name);		//����ѧ��
		printf("Elective score: ");		
		scanf("%f", &stu[m].elect);		//������޿η���
		printf("Required score: ");
		scanf("%f", &stu[m].requi);		//����ѡ�޿η���
		stu[m].t_p = stu[m].elect + stu[m].requi;		//���������������ܷ���
		
		if (fwrite(&stu[m], LEN, 1, fp) != 1)		//��ѧ����Ϣд�������ļ�
		{
			printf("Can't save information!");
			getch();
		}
		else
		{
			printf("%s information stored!\n", stu[m].name);
			++m;
		}
		
		printf("Do you want to continue?(Y/N): ");		//�Ƿ����¼��ѧ����Ϣ
		scanf("%s", ch);
	}
	fclose(fp);
	printf("END!\n");
}

void show_Inf(void)
{
	int i, m = 0;	//��ʱ����
	FILE * fp;		//�ļ�ָ��
	fp = fopen("data", "ab+");
	
	while (!feof(fp))	//������ļ�ָ���Ƿ��ѵ����ļ���β
	{
		if (fread(&stu[m], LEN, 1, fp) == 1)	//���ļ����ж�����
			++m;								//����һ��stu[m]����, m����;
	}
	fclose(fp);
	printf("Number	Name	Elective	Required	Total Points\t\n");

	for (i=0; i<m; ++i)
		printf(FORMAT, DATA);	//ʹ���Զ����ʽ���;
}

void menu(void)
{
	system("cls");
	printf("\n\n");
	printf(" |-----------Student-Management-System-----------|\n");
	printf(" | 0. Exit                                       |\n");
	printf(" | 1. Input Information                          |\n");
	printf(" | 2. Search Information                         |\n");
	printf(" | 3. Modify Information                         |\n");
	printf(" | 4. Delete Information                         |\n");
	printf(" | 5. Rankings                                   |\n");
	printf(" | 6. Show Information                           |\n");
	printf(" | 7. Score Analyze                              |\n");
	printf(" |-----------------------------------------------|\n");
	printf("  Please Choose(0-7): ");
}

//2018-06-30 23:53:49 by Joeyzhan 
