#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "global.h"
#include "person_file.h"
#include "person.h"

Person * person_add_manual(Person * head)
{
	Person * tail = head;
	if (tail != NULL)
	{
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
	}

	printf("��¼��ѧ�� ���� �Ա� ���� ��ע �ɼ�(ѧ��С��0��ֹ)\n");
	do
	{
		Person * node = (Person *) malloc(PERSON_SIZE);
		printf("��¼��ѧ����Ϣ��");
		scanf("%d %s %c %d %s %f", &node->num, node->name, &node->sex, &node->age, node->remarks, &node->score);
	
		// ��ֹ
		if (node->num <= 0)
		{
			free(node);
			break;
		}

		// ������
		if (head == NULL)
		{
			head = node;
			tail = node;
		} 
		else
		{
			tail->next = node;
			tail = node;
		}
	} while(TRUE);

	// ĩ�ڵ�ָ���ֶ���ΪNULL
	tail->next = NULL;
	return head;
}

Person * person_add_load_file(Person * head)
{
	return load(head);
}

void person_print(Person * head)
{
	Person * node = head;

	if (node == NULL)
	{
		printf("\n\nδ¼��ѧ������\n\n");
		return;
	}

	printf("%-10s%-10s%-10s%-10s%-20s%-10s\n", "ѧ��", "����", "�Ա�", "����", "��ע", "�ɼ�");
	while (node != NULL)
	{
		printf("%-10d%-10s%-10c%-10d%-20s%-10.1f\n", node->num, node->name, node->sex, node->age, node->remarks, node->score);
		node = node->next;
	}
}

void person_add_save_file(Person * head)
{
	save(head);
}

Person * person_delete_by_num(Person * head, int num)
{
	Person * node = head, * front;

	if (node == NULL)
	{
		printf("\n\nδ¼��ѧ������\n\n");
		return NULL;
	}

	for (front = head; node != NULL && node->num != num; node = node->next)
	{
		front = head;
	}

	// δ�ҵ�ɾ���ڵ�
	if (node == NULL)
	{
		printf("\n\n��ǰ�����У�û��ѧ�ţ�%d����˶�\n\n", num);
		return NULL;
	}

	// ɾ���ڵ�

	// 1. ͷ���
	if (node == head)
	{
		head = node->next;
	}
	// .β�ڵ����м���,ɾ���߼�һ��,�ϲ�
	else
	{
		front->next = node->next;
	}
	free(node);
	printf("\n\n�ɹ�ɾ��ѧ�ţ�%d\n\n", num);

	return head;
}

void person_update_by_num(Person * head, int num)
{
	Person * node = head;

	if (node == NULL)
	{
		printf("\n\nδ¼��ѧ������\n\n");
		return;
	}

	while (node != NULL && node->num != num)
	{
		node = node->next;
	}

	// ���δ�ҵ�
	if (node == NULL)
	{
		printf("\n\n��ǰ�����У�û��ѧ�ţ�%d����˶�\n\n", num);
		return;
	}

	// ����ҵ�����ô�����ƶ�λ�ã����ҵ�����ʼ��i + 1 = i
	printf("������¼�� ���� �Ա� ���� ��ע �ɼ���");
	scanf("%s %c %d %s %f", node->name, &node->sex, &node->age, node->remarks, &node->score);

	printf("\n\n�ɹ��޸�ѧ�ţ�%d\n\n", num);
}

void person_query_by_num(Person * head, int num)
{
	Person * node = head;

	while (node != NULL && node->num != num)
	{
		node = node->next;
	}

	// ���δ�ҵ�
	if (node == NULL)
	{
		printf("\n\n��ǰ�����У�û��ѧ�ţ�%d����˶�\n\n", num);
		return;
	}

	// ����ҵ������
	printf("%-10s%-10s%-10s%-10s%-20s%-10s\n", "ѧ��", "����", "�Ա�", "����", "��ע", "�ɼ�");
	printf("%-10d%-10s%-10c%-10d%-20s%-10.1f\n", node->num, node->name, node->sex, node->age, node->remarks, node->score);
}

void person_query_by_name(Person * head, char name[])
{
	Person * node = head;

	while (node != NULL && strcmp(node->name, name) != 0)
	{
		node = node->next;
	}

	// ���δ�ҵ�
	if (node == NULL)
	{
		printf("\n\n��ǰ�����У�û��������%s����˶�\n\n", name);
		return;
	}

	// ����ҵ������
	printf("%-10s%-10s%-10s%-10s%-20s%-10s\n", "ѧ��", "����", "�Ա�", "����", "��ע", "�ɼ�");
	printf("%-10d%-10s%-10c%-10d%-20s%-10.1f\n", node->num, node->name, node->sex, node->age, node->remarks, node->score);
}

void person_sort_by_score_desc(Person * head)
{
	Person * node = head, * copy_head = NULL;

	if (node == NULL)
	{
		printf("\n\nδ¼��ѧ������\n\n");
		return;
	}

	// 1. ����
	copy_head = copy_linked(head);
	// . ����ѡ������
	copy_head = sort_desc(copy_head);
	// 3. ���
	person_print(copy_head);

	free_linked(copy_head);
}

// ���򣨲��ñ���+�����ؽ���ʽ��
Person * sort_desc(Person * head)
{
	Person * max, * front_max, * node, * front_node, * sort_head = NULL, * sort_tail;
	
	while (head != NULL)
	{
		for (max = head, front_node = head, node = front_node->next; node != NULL; front_node = node, node = node->next)
		{
			if (max->score < node->score)
			{
				front_max = front_node;
				max  = node;
			}
		}

		// 1. �����µ�sort_head
		if (sort_head == NULL)
		{
			sort_head =  max;
			sort_tail = max;
		}
		else 
		{
			sort_tail->next = max;
			sort_tail = max;
		}

		// . ��head�����е�max�ڵ��Ƴ���
		if (max == head)
		{
			head = NULL;
		}
		else 
		{
			front_max->next = max->next;
		}
	}

	return sort_head;
}

void person_sort_by_score_asc(Person * head)
{
	Person * node = head, * copy_head = NULL;

	if (node == NULL)
	{
		printf("\n\nδ¼��ѧ������\n\n");
		return;
	}

	// 1. ����
	copy_head = copy_linked(head);
	// . ����ѡ������
	copy_head = sort_asc(copy_head);
	// 3. ���
	person_print(copy_head);

	free_linked(copy_head);
}

Person * sort_asc(Person * head)
{
	Person * max, * front_max, * node, * front_node, * sort_head = NULL, * sort_tail;
	
	while (head != NULL)
	{
		for (max = head, front_node = head, node = front_node->next; node != NULL; front_node = node, node = node->next)
		{
			if (max->score > node->score)
			{
				front_max = front_node;
				max  = node;
			}
		}

		// 1. �����µ�sort_head
		if (sort_head == NULL)
		{
			sort_head =  max;
			sort_tail = max;
		}
		else 
		{
			sort_tail->next = max;
			sort_tail = max;
		}

		// . ��head�����е�max�ڵ��Ƴ���
		if (max == head)
		{
			head = head->next;
		}
		else 
		{
			front_max->next = max->next;
		}
	}

	return sort_head;
}

Person * copy_linked(Person * head)
{
	Person * node = head, * copy_head = NULL, * copy_tail, * copy_node;

	if (node == NULL)
	{
		printf("\n\nδ¼��ѧ������\n\n");
		return NULL;
	}

	// 1. ����
	while (node != NULL)
	{
		copy_node = (Person *) malloc(PERSON_SIZE);
		* copy_node = * node;

		// ������
		if (copy_head == NULL)
		{
			copy_head = copy_node;
			copy_tail = copy_node;
		} 
		else
		{
			copy_tail->next = copy_node;
			copy_tail = copy_node;
		}
		node = node->next;
	}

	// ĩ�ڵ�ָ���ֶ���ΪNULL
	copy_tail->next = NULL;
	return copy_head;
}

void free_linked(Person * head)
{
	Person * node = head, * front;

	if (node == NULL)
	{
		return;
	}

	while (node != NULL)
	{
		front = node;
		node = node->next;
		// �����ͷŽ��
		free(front);
	}
}