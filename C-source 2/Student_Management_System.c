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
	int numb;		//学号
	char name[10];	//名字
	float elect;	//必修课分数
	float requi;	//选修课分数
	float t_p;		//总分
};

struct student_Information stu[32];

void menu(void);				//显示功能菜单函数
void show_Inf(void);			//输出函数
void input_Inf(void);			//录入函数
void search_Inf(void);			//查找函数
void modify_Inf(void);			//修改函数
void delete_Inf(void);			//删除函数
void rankings_Inf(void);		//排名函数
void score_analyze_Inf(void);	//成绩分析函数

int main(void)
{
	int n;
	menu();
	scanf("%d", &n);
	while (n)			//循环判断用户选择的功能
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
	int i, m = 0;				//临时变量
	float elect_average = 0;	//用于存储平均分的变量
	float requi_average = 0;
	float t_p_average = 0;
	FILE * fp;					//文件指针
	
	if ((fp = fopen("data","ab+")) == NULL)		//判断是否打开/创建 出文件, 不能则终止该函数
	{ 
		printf("Can't open/find file!\n");
		return;
	}
	
	while (!feof(fp))							//检测流文件指针是否已到达文件结尾
		if (1 == fread(&stu[m], LEN, 1, fp))	//从文件流中读数据
			++m;								//读到一个stu[m]数据, m自增
	fclose(fp);
	
	if (0 == m) 								//判读文件是否有内容
	{
		printf("No find information!\n");
		return;
	}
	
	printf("\nScore analyze:\n");
	for (i=0; i<m; ++i)							//计算各科平均分
	{
		elect_average += stu[i].elect;
		requi_average += stu[i].requi;
		t_p_average += stu[i].t_p;
	}
	//输出各科平均分及最高分最低分
	printf("\t\tElective Average: %f\n\t\tRequired Average: %f\n\t\tTotal Average: %f\n", elect_average/i, requi_average/i, t_p_average/i);
	printf("\t\tTop score: %f\n\t\tLowest mark: %f\n", stu[m-1].t_p, stu[0].t_p);	
}

void rankings_Inf(void)
{ 
	struct student_Information t;	//临时变量
	int i=0, j=0, m=0;				//临时变量
	FILE * fp;						//文件变量
	
	if ((fp = fopen("data","ab+")) == NULL)		//判断是否打开/创建 出文件, 不能则终止该函数
	{ 
		printf("Can't open/find file!\n");
		return;
	}
	
	while (!feof(fp))							//检测流文件指针是否已到达文件结尾
		if (1 == fread(&stu[m], LEN, 1, fp))	//从文件流中读数据
			++m;								//读到一个stu[m]数据, m自增
	fclose(fp);
		
	if (0 == m) 								//判读文件是否有内容
	{
		printf("No find information!\n");
		return;
	}
	
	for (i=0; i<m-1; ++i)
		for (j=i+1; j<m; ++j)		//双重循环实现成绩比较并交换
			if (stu[i].t_p < stu[j].t_p)
			{ 
				t = stu[i];
				stu[i] = stu[j];
				stu[j] = t;
			}
			
	if ((fp = fopen("data","wb")) == NULL)		//判断是否能够写入文件, 不能则终止该函数
	{ 
		printf("Can't open/find file!\n");
		return;
	}
	
	for (i=0; i<m; ++i)
		if (1 != fwrite(&stu[i], LEN, 1, fp))	//将修改后的学生信息写入数据文件
		{ 
			printf("Can't save information!");
			getch();
		}
	fclose(fp);
	printf("Saved successfully!\n");
	show_Inf();		//将排序好的学生信息进行输出
}

void delete_Inf(void)
{
	int s_numb, i, j, m = 0;	//临时变量
	char ch[3];					//用于判断是否继续循环的变量
	FILE * fp;					//文件指针
	
	if ((fp = fopen("data", "ab+")) == NULL)	//判断是否打开/创建 出文件, 不能则终止该函数
	{
		printf("Can't open/find file!\n");
		return;
	}
	
	while (!feof(fp))							//检测流文件指针是否已到达文件结尾
		if (fread(&stu[m], LEN, 1, fp) == 1)	//从文件流中读数据
			++m;								//读到一个stu[m]数据, m自增
	
	fclose(fp);
	if (0 == m)									//判读文件是否有内容
	{
		printf("No find information!\n");
		return;
	}
	
	printf("Please input the student number: ");
	scanf("%d", &s_numb);		//输入需要删除的学生的学号
	
	for (i=0; i<m; ++i)			//判断用户输入的学号在文件存储中是否存在
		if (s_numb == stu[i].numb)	
			break;
	if (i == m)		//判断是否有该学生信息, 没有则结束该函数
	{
		printf("No find information!\n");
		getchar();
		return;
	}
	
	printf("Finded the student information, Delete?(Y/N): ");
	scanf("%s", ch);
	
	if (0 == strcmp(ch, "Y") || 0 == strcmp(ch, "y"))	//判断是否继续输出信息
	{
		for (j=i; j<m; ++j)
			stu[j] = stu[j+1];		//将后一个信息移到前一个信息的位置
		--m;
		printf("Deleted successfully!\n");
		
		if ((fp = fopen("data", "wb")) == NULL)		//判断是否能够写入文件, 不能则终止该函数
		{
			printf("Can't open/find file!\n");
			return;
		}
		
		for (j=0; j<m; ++j)
			if (1 != fwrite(&stu[j], LEN, 1, fp))	//将修改后的学生信息写入数据文件
			{
				printf("Can't save information!");
				getch();
			}
		
		fclose(fp);
	}
}

void modify_Inf(void)
{
	int i, j, s_numb, m = 0;	//临时变量
	FILE * fp;		//文件变量
	
	if ((fp = fopen("data", "ab+")) == NULL)	//判断是否打开/创建 出文件, 不能则终止该函数
	{
		printf("Can't open/find file!\n");		//检测流文件指针是否已到达文件结尾
		return;
	}
	
	while (!feof(fp))							//检测流文件指针是否已到达文件结尾
		if (fread(&stu[m], LEN, 1, fp) == 1)	//从文件流中读数据
			++m;								//读到一个stu[m]数据, m自增
	if (m == 0)									//判读文件是否有内容
	{
		printf("No find information!\n");
		fclose(fp);
		return;
	}
	
	printf("Please input the student number that needs to be modify: ");
	scanf("%d", &s_numb);		//输入需要修改的学生的学号
	
	for (i=0; i<m; ++i)
		if (s_numb == stu[i].numb)		//判断用户输入的学号在文件存储中是否存在
			break;
		
	if (i<m)	//判断是否有该学生信息, 没有则结束该函数
	{
		printf("Find the student! Please modify!\n");
		printf("Please input student information: \n");
		printf("Name: ");
		scanf("%s", stu[i].name);		//输入名字
		printf("Elective: ");
		scanf("%f", &stu[i].elect);		//输入必修课分数
		printf("Required: ");	
		scanf("%f", &stu[i].requi);		//输入选修课分数
		stu[i].t_p = stu[i].elect + stu[i].requi;		//将改动的其他分数赋给总分数
	}
	else
	{
		printf("Can't find student information!\n");
		getchar();
		return;
	}
	
	if ((fp = fopen("data", "wb")) == NULL)		//判断是否能够写入文件, 不能则终止该函数
	{
		printf("Can't open/find file!\n");
		return;
	}
	
	for (j=0; j<m; ++j)
		if (1 != fwrite(&stu[j], LEN, 1, fp))	//将修改后的学生信息写入数据文件
		{
			printf("Can't save information!");
			getch();
		}
		fclose(fp);
}

void search_Inf(void)
{
	int s_numb, i, m = 0;		//临时变量
	char ch[3];		//用于判断是否继续循环的变量
	FILE * fp;		//文件指针
	
	if ((fp = fopen("data", "ab+")) == NULL)	//判断是否打开/创建 出文件, 不能则终止该函数
	{
		printf("Can't open/find file!\n");
		return;
	}
	
	while (!feof(fp))							//检测流文件指针是否已到达文件结尾
		if (fread(&stu[m], LEN, 1, fp) == 1)	//从文件流中读数据
			++m;								//读到一个stu[m]数据, m自增
	fclose(fp);
	
	if (0 == m)									//判读文件是否有内容
	{
		printf("No find information!\n");
		return;
	}
	printf("Please input the student number: ");	
	scanf("%d", &s_numb);						//输入需要查询的学生的学号
	
	for (i=0; i<m; ++i)
		if (s_numb == stu[i].numb)				//判断用户输入的学号在文件存储中是否存在, 存在则让用户决定是否输出出来
		{
			printf("Fined the student information, Show up?(Y/N): ");
			scanf("%s", ch);
			if (0 == strcmp(ch, "Y") || 0 == strcmp(ch, "y"))		//判断是否继续输出信息
			{
				printf("Number	Name	Elective	Required	Total Points\t\n");
				printf(FORMAT, DATA);	  //使用自定义格式输出;
				break;
			}
			else
				return;
		}
		
		if (i == m)		//当所有数据判断完, 则提示用户没有该学生信息
			printf("Can't find the student information!\n");
}

void input_Inf(void)
{
	int i, m = 0;	//临时变量
	char ch[3];		//用于判断是否继续循环的变量
	FILE * fp;		//文件指针
	
	if ((fp = fopen("data", "ab+")) == NULL)	//判断是否打开/创建 出文件, 不能则终止该函数
	{
		printf("Can't open/creat file!\n");
		return;
	}
	while (!feof(fp))							//检测流文件指针是否已到达文件结尾
	{
		if (1 == fread(&stu[m], LEN, 1, fp))	//从文件流中读数据
			++m;								//读到一个stu[m]数据, m自增
	}
	fclose(fp);
	
	if (m == 0)									//判读文件是否有内容
		printf("No find information!");
	else
	{
		system("cls");							//有则清空dos界面, 并输出所有学生信息
		show_Inf();
	}
	if ((fp=fopen("data", "wb")) == NULL)		//判断是否打开/创建 出文件, 不能则终止该函数
	{
		printf("Can't open/find file!\n");
		return;
	}
	
	for (i=0; i<m; ++i)
		fwrite(&stu[i], LEN, 1, fp);			//将文件原有数据再次输入回文件
	printf("Please input student information(Y/N): ");
	scanf("%s", ch);	//让用户选择是否执行输入信息操作
	
	while (0 == strcmp(ch, "Y") || 0 == strcmp(ch, "y"))	//判断是否继续输入信息
	{
		printf("Student number: ");
		scanf("%d", &stu[m].numb);		//输入学号
		for (i=0; i<m; ++i)
			if (stu[i].numb == stu[m].numb)		//判断用户输入的学号是否与在文件存储中的学号重复, 重复则结束函数, 关闭数据文件;
			{
				printf("The number already exists, Failed to enter information\n!");
				getch();
				fclose(fp);
				return;
			}
			
		printf("Name: ");
		scanf("%s", stu[m].name);		//输入学号
		printf("Elective score: ");		
		scanf("%f", &stu[m].elect);		//输入必修课分数
		printf("Required score: ");
		scanf("%f", &stu[m].requi);		//输入选修课分数
		stu[m].t_p = stu[m].elect + stu[m].requi;		//将其他分数赋给总分数
		
		if (fwrite(&stu[m], LEN, 1, fp) != 1)		//将学生信息写入数据文件
		{
			printf("Can't save information!");
			getch();
		}
		else
		{
			printf("%s information stored!\n", stu[m].name);
			++m;
		}
		
		printf("Do you want to continue?(Y/N): ");		//是否继续录入学生信息
		scanf("%s", ch);
	}
	fclose(fp);
	printf("END!\n");
}

void show_Inf(void)
{
	int i, m = 0;	//临时变量
	FILE * fp;		//文件指针
	fp = fopen("data", "ab+");
	
	while (!feof(fp))	//检测流文件指针是否已到达文件结尾
	{
		if (fread(&stu[m], LEN, 1, fp) == 1)	//从文件流中读数据
			++m;								//读到一个stu[m]数据, m自增;
	}
	fclose(fp);
	printf("Number	Name	Elective	Required	Total Points\t\n");

	for (i=0; i<m; ++i)
		printf(FORMAT, DATA);	//使用自定义格式输出;
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
