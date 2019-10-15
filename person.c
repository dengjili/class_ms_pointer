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

	printf("请录入学号 姓名 性别 年龄 备注 成绩(学号小于0终止)\n");
	do
	{
		Person * node = (Person *) malloc(PERSON_SIZE);
		printf("请录入学生信息：");
		scanf("%d %s %c %d %s %f", &node->num, node->name, &node->sex, &node->age, node->remarks, &node->score);
	
		// 终止
		if (node->num <= 0)
		{
			free(node);
			break;
		}

		// 空链表
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

	// 末节点指针手动置为NULL
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
		printf("\n\n未录入学生数据\n\n");
		return;
	}

	printf("%-10s%-10s%-10s%-10s%-20s%-10s\n", "学号", "姓名", "性别", "年龄", "备注", "成绩");
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
		printf("\n\n未录入学生数据\n\n");
		return NULL;
	}

	for (front = head; node != NULL && node->num != num; node = node->next)
	{
		front = head;
	}

	// 未找到删除节点
	if (node == NULL)
	{
		printf("\n\n当前数据中，没有学号：%d，请核对\n\n", num);
		return NULL;
	}

	// 删除节点

	// 1. 头结点
	if (node == head)
	{
		head = node->next;
	}
	// .尾节点与中间结点,删除逻辑一致,合并
	else
	{
		front->next = node->next;
	}
	free(node);
	printf("\n\n成功删除学号：%d\n\n", num);

	return head;
}

void person_update_by_num(Person * head, int num)
{
	Person * node = head;

	if (node == NULL)
	{
		printf("\n\n未录入学生数据\n\n");
		return;
	}

	while (node != NULL && node->num != num)
	{
		node = node->next;
	}

	// 如果未找到
	if (node == NULL)
	{
		printf("\n\n当前数据中，没有学号：%d，请核对\n\n", num);
		return;
	}

	// 如果找到，那么数组移动位置，从找到处开始：i + 1 = i
	printf("请重新录入 姓名 性别 年龄 备注 成绩：");
	scanf("%s %c %d %s %f", node->name, &node->sex, &node->age, node->remarks, &node->score);

	printf("\n\n成功修改学号：%d\n\n", num);
}

void person_query_by_num(Person * head, int num)
{
	Person * node = head;

	while (node != NULL && node->num != num)
	{
		node = node->next;
	}

	// 如果未找到
	if (node == NULL)
	{
		printf("\n\n当前数据中，没有学号：%d，请核对\n\n", num);
		return;
	}

	// 如果找到，输出
	printf("%-10s%-10s%-10s%-10s%-20s%-10s\n", "学号", "姓名", "性别", "年龄", "备注", "成绩");
	printf("%-10d%-10s%-10c%-10d%-20s%-10.1f\n", node->num, node->name, node->sex, node->age, node->remarks, node->score);
}

void person_query_by_name(Person * head, char name[])
{
	Person * node = head;

	while (node != NULL && strcmp(node->name, name) != 0)
	{
		node = node->next;
	}

	// 如果未找到
	if (node == NULL)
	{
		printf("\n\n当前数据中，没有姓名：%s，请核对\n\n", name);
		return;
	}

	// 如果找到，输出
	printf("%-10s%-10s%-10s%-10s%-20s%-10s\n", "学号", "姓名", "性别", "年龄", "备注", "成绩");
	printf("%-10d%-10s%-10c%-10d%-20s%-10.1f\n", node->num, node->name, node->sex, node->age, node->remarks, node->score);
}

void person_sort_by_score_desc(Person * head)
{
	Person * node = head, * copy_head = NULL;

	if (node == NULL)
	{
		printf("\n\n未录入学生数据\n\n");
		return;
	}

	// 1. 拷贝
	copy_head = copy_linked(head);
	// . 排序（选择排序）
	copy_head = sort_desc(copy_head);
	// 3. 输出
	person_print(copy_head);

	free_linked(copy_head);
}

// 排序（采用遍历+链表重建方式）
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

		// 1. 构建新的sort_head
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

		// . 将head链表中的max节点移除掉
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
		printf("\n\n未录入学生数据\n\n");
		return;
	}

	// 1. 拷贝
	copy_head = copy_linked(head);
	// . 排序（选择排序）
	copy_head = sort_asc(copy_head);
	// 3. 输出
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

		// 1. 构建新的sort_head
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

		// . 将head链表中的max节点移除掉
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
		printf("\n\n未录入学生数据\n\n");
		return NULL;
	}

	// 1. 拷贝
	while (node != NULL)
	{
		copy_node = (Person *) malloc(PERSON_SIZE);
		* copy_node = * node;

		// 空链表
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

	// 末节点指针手动置为NULL
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
		// 依次释放结点
		free(front);
	}
}