#include "person.h"

#ifndef _PERSON_FILE_H_
#define _PERSON_FILE_H_

// 从文件中读取数据
Person * load(Person * head);
// 保存数据到文件
void save(Person * head);

#endif