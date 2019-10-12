#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "menu_ui.h"
#include "person.h"

// ����ֵ
int input();
void input_string(char str[]);
// ����������ʾ
void input_error_show();

int main()
{
	Person * head = NULL;

	// ������������
	int choice, len = 0, working;
	char choice_name[30];

	// �����Ƿ�����(1�����У�0����ֹ)
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
			printf("ѧ��������Ϣɾ������ѧ��ɾ����");
			choice = input();
			head = person_delete_by_num(head, choice);
			break;
		case 5:
			printf("ѧ��������Ϣ�޸ģ�ѡ����Ҫ�޸ĵ�ѧ�ţ�");
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
					printf("ѧ��������Ϣ��ѯ����ѧ�Ų�ѯ��");
					choice = input();
					person_query_by_num(head, choice);
					break;
				case 2:
					printf("ѧ��������Ϣ��ѯ����ѧ�Ų�ѯ��");
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

	printf("\n\n���˳�...\n\n");

	return 0;
}

int input()
{
	// ������
	int num;

	printf("\n\n��ѡ��");
	scanf("%d", &num);

	return num;
}

void input_string(char str[])
{
	printf("\n\n�����룺");
	scanf("%s", str);
}

void input_error_show()
{
	printf("\n\n�������ָ��Ƿ���������ѡ�񣨰������������\n\n");
	system("pause");
}