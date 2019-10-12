#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "person_file.h"

// ���ļ��ж�ȡ����
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
		printf("��ȡ�ļ�person.datʧ�ܣ��˳���ǰ����\n");
		exit(-1);
	}

	do
	{
		Person * node = (Person *) malloc(PERSON_SIZE);

		// ��ֹ
		if (fread(node, sizeof(Person), 1, fp) != TRUE)
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
	fclose(fp);

	printf("\n\n�ɹ����ļ��ж�ȡ����.\n\n");
	return head;
}

// �������ݵ��ļ�
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
		printf("�ļ�person.dat����ʧ�ܣ��˳���ǰ����\n");
		exit(-1);
	}

	while (node != NULL)
	{
		fwrite(node, sizeof(Person), 1, fp);
		node = node->next;
	}
	
	fclose(fp);

	printf("�ɹ��������ݵ��ļ�\n");
}