#ifndef _PERSON_H_
#define _PERSON_H_

typedef struct person
{
	// 学号
	int num;
	// 姓名
	char name[30];
	// 性别
	char sex;
	// 年龄
	int age;
	// 备注
	char remarks[100];
	// 成绩
	float score;
	// 尾指针
	struct person * next;
}Person;

#define PERSON_SIZE sizeof(struct person)

// 手工录入
Person * person_add_manual(Person * head);
// 文件录入
Person * person_add_load_file(Person * head);

// 学生基本信息显示 
void person_print(Person * head);

// 学生基本信息保存 
void person_add_save_file(Person * head);

// 学生基本信息删除(按学号)
Person * person_delete_by_num(Person * head, int num);

// 学生基本信息修改（要求先输入密码） 
void person_update_by_num(Person * head, int num);

// 学生基本信息查询 
// 按学号查询 
void person_query_by_num(Person * head, int num);

// 按姓名查询 
void person_query_by_name(Person * head, char name[]);

// 学生总分成绩查询
// 按降序查询
void person_sort_by_score_desc(Person * head);
Person * sort_desc(Person * head);

// 按升序查询
void person_sort_by_score_asc(Person * head);
Person * sort_asc(Person * head);

Person * copy_linked(Person * head);
void free_linked(Person * head);

#endif