#ifndef _PERSON_H_
#define _PERSON_H_

typedef struct person
{
	// ѧ��
	int num;
	// ����
	char name[30];
	// �Ա�
	char sex;
	// ����
	int age;
	// ��ע
	char remarks[100];
	// �ɼ�
	float score;
	// βָ��
	struct person * next;
}Person;

#define PERSON_SIZE sizeof(struct person)

// �ֹ�¼��
Person * person_add_manual(Person * head);
// �ļ�¼��
Person * person_add_load_file(Person * head);

// ѧ��������Ϣ��ʾ 
void person_print(Person * head);

// ѧ��������Ϣ���� 
void person_add_save_file(Person * head);

// ѧ��������Ϣɾ��(��ѧ��)
Person * person_delete_by_num(Person * head, int num);

// ѧ��������Ϣ�޸ģ�Ҫ�����������룩 
void person_update_by_num(Person * head, int num);

// ѧ��������Ϣ��ѯ 
// ��ѧ�Ų�ѯ 
void person_query_by_num(Person * head, int num);

// ��������ѯ 
void person_query_by_name(Person * head, char name[]);

// ѧ���ֳܷɼ���ѯ
// �������ѯ
void person_sort_by_score_desc(Person * head);
Person * sort_desc(Person * head);

// �������ѯ
void person_sort_by_score_asc(Person * head);
Person * sort_asc(Person * head);

Person * copy_linked(Person * head);
void free_linked(Person * head);

#endif