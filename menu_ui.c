#include <stdio.h>
#include "menu_ui.h"

void main_ui()
{
	printf("\n\n");
	printf("\t\t\t *=====================================*\n");
    printf("\t\t\t| | * - * - * -管-理-界-面- * - * - * | |\n");
    printf("\t\t\t| *                                   * |\n");
    printf("\t\t\t| |  [1]   学生基本信息录入           | |\n");
    printf("\t\t\t| *  [2]   学生基本信息显示           * |\n");
    printf("\t\t\t| |  [3]   学生基本信息保存           | |\n");
    printf("\t\t\t| *  [4]   学生基本信息删除           * |\n");
    printf("\t\t\t| |  [5]   学生基本信息修改(密码)     | |\n");
    printf("\t\t\t| *  [6]   学生基本信息查询           * |\n");
	printf("\t\t\t| |  [7]   学生总分成绩查询           | |\n");
    printf("\t\t\t| *  [8]   退出系统                   * |\n");
    printf("\t\t\t| |                                   | |\n");
    printf("\t\t\t| * - * - * - * - * - * - * - * - * - * |\n");
	printf("\t\t\t *=====================================*\n");
}

void person_add_ui()
{
	printf("\n\n");
	printf("\t\t\t *=====================================*\n");
    printf("\t\t\t| | * - * - * -信-息-录-入- * - * - * | |\n");
    printf("\t\t\t| *                                   * |\n");
    printf("\t\t\t| |  [1]   学生基本信息录入           | |\n");
    printf("\t\t\t| *	  [1]	     手工录入(可追加)   * |\n");
	printf("\t\t\t| |	  [2]	     文件录入           | |\n");
	printf("\t\t\t| |	  [3]	     退出               * |\n");
    printf("\t\t\t| |                                   | |\n");
    printf("\t\t\t| * - * - * - * - * - * - * - * - * - * |\n");
	printf("\t\t\t *=====================================*\n");
}


void person_info_ui()
{
	printf("\n\n");
	printf("\t\t\t *=====================================*\n");
    printf("\t\t\t| | * - * - * -信-息-查-询- * - * - * | |\n");
    printf("\t\t\t| *                                   * |\n");
    printf("\t\t\t| *  [6]   学生基本信息查询           * |\n");
    printf("\t\t\t| |	  [1]	   按学号查询           | |\n");
	printf("\t\t\t| *	  [2]	   按姓名查询           * |\n");
	printf("\t\t\t| |	  [3]	   退出                 | |\n");
    printf("\t\t\t| |                                   | |\n");
    printf("\t\t\t| * - * - * - * - * - * - * - * - * - * |\n");
	printf("\t\t\t *=====================================*\n");
}

void score_ui()
{
	printf("\n\n");
	printf("\t\t\t *=====================================*\n");
    printf("\t\t\t| | * - * - * -成-绩-查-询- * - * - * | |\n");
    printf("\t\t\t| *                                   * |\n");
    printf("\t\t\t| *  [7]   学生总分成绩查询           * |\n");
    printf("\t\t\t| |	  [1]	   按降序查询           | |\n");
	printf("\t\t\t| |	  [2]	   按升序查询           | |\n");
	printf("\t\t\t| *	  [3]	     退出               * |\n");
    printf("\t\t\t| |                                   | |\n");
    printf("\t\t\t| * - * - * - * - * - * - * - * - * - * |\n");
	printf("\t\t\t *=====================================*\n");
}