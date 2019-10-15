#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "menu_ui.h"
#include "person.h"

// 输入值
int input();
void input_string(char str[]);
// 错误输入提示
void input_error_show();

int main()
{
	Person * head = NULL;

	// 主界面输入项
	int choice, len = 0, working;
	char choice_name[30];

	// 程序是否运行(1是运行，0是终止)
	int is_runing = RUNNING;

	while (is_runing)
	{
		main_ui();
		
		choice = input();
		switch (choice)
		{
		case 1:
			working = TRUE;
			while (working)
			{
				person_add_ui();
				choice = input();
				switch (choice) 
				{
				case 1:
					head = person_add_manual(head);
					break;
				case 2:
					head = person_add_load_file(head);
					break;
				case 3:
					working = FALSE;
					break;
				default:
					input_error_show();
				}
			}
			break;
		case 2:
			person_print(head);
			break;
		case 3:
			person_add_save_file(head);
			break;
		case 4:
			printf("学生基本信息删除（按学号删除）");
			choice = input();
			head = person_delete_by_num(head, choice);
			break;
		case 5:
			printf("学生基本信息修改（选择需要修改的学号）");
			choice = input();
			person_update_by_num(head, choice);
			break;
		case 6:
			working = TRUE;
			while (working)
			{
				person_info_ui();
				choice = input();
				switch (choice) 
				{
				case 1:
					printf("学生基本信息查询（按学号查询）");
					choice = input();
					person_query_by_num(head, choice);
					break;
				case 2:
					printf("学生基本信息查询（按学号查询）");
					input_string(choice_name);
					person_query_by_name(head, choice_name);
					break;
				case 3:
					working = FALSE;
					break;
				default:
					input_error_show();
				}
			}
			break;
		case 7:
			working = TRUE;
			while (working)
			{
				score_ui();
				choice = input();
				switch (choice) 
				{
				case 1:
					person_sort_by_score_desc(head);
					break;
				case 2:
					person_sort_by_score_asc(head);
					break;
				case 3:
					working = FALSE;
					break;
				default:
					input_error_show();
				}
			}
			break;
		case 8:
			is_runing = STOP;
			break;
		default:
			input_error_show();
		}
	}

	printf("\n\n已退出...\n\n");

	return 0;
}

int input()
{
	// 输入项
	int num;

	printf("\n\n请选择：");
	scanf("%d", &num);

	return num;
}

void input_string(char str[])
{
	printf("\n\n请输入：");
	scanf("%s", str);
}

void input_error_show()
{
	printf("\n\n你输入的指令非法，请重新选择（按任意键继续）\n\n");
	system("pause");
}