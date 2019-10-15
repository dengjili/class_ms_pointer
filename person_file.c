#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "person_file.h"

// 从文件中读取数据
Person * load(Person * head)
{
	FILE * fp;
	Person * tail = head;
	if (tail != NULL)
	{
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
	}

	fp = fopen("person.dat", "rb");
	if (fp == NULL)
	{
		printf("读取文件person.dat失败，退出当前程序\n");
		exit(-1);
	}

	do
	{
		Person * node = (Person *) malloc(PERSON_SIZE);

		// 终止
		if (fread(node, sizeof(Person), 1, fp) != TRUE)
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
	fclose(fp);

	printf("\n\n成功从文件中读取数据.\n\n");
	return head;
}

// 保存数据到文件
void save(Person * head)
{
	Person * node = head;
	FILE * fp;

	if (node == NULL)
	{
		return;
	}

	fp = fopen("person.dat", "wb");
	if (fp == NULL)
	{
		printf("文件person.dat创建失败，退出当前程序\n");
		exit(-1);
	}

	while (node != NULL)
	{
		fwrite(node, sizeof(Person), 1, fp);
		node = node->next;
	}
	
	fclose(fp);

	printf("成功保存数据到文件\n");
}