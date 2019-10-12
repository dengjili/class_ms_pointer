# 班级档案管理系统 (数组版本)
原题目要求是对一个有N个学生的班级，通过该系统实现对该班级学生的基本信息进行录入、
显示、修改、删除、保存等操作的管理。

`由于个人需要，我单独将项目改造为指针使用版本，掌握上难度较高，有需要的请前往指针版本：` [对应github项目地址]()

**主要掌握点包括**

* 结构体的使用
* 数组的使用
* 增删改查的基本概念
* 基本算法的使用如：排序、查找算法等
* 文件的读取、写入
  
## 功能点列表

1. 本系统采用一个包含N个数据的结构体数组，每个数据的结构应当包括：学
号、姓名、性别、年龄、备注。
2. 本系统显示这样的菜单：
	* 学生基本信息录入
		1. 手工录入
		2. 文件录入
		3. 手工录入(追加)
	* 学生基本信息显示
	* 学生基本信息保存
	* 学生基本信息删除
	* 学生基本信息修改 ~~（要求先输入密码）~~
	* 学生基本信息查询
		1. 按学号查询
		2. 按姓名查询
	* 学生总分成绩查询
		1. 按降序查询
		2. 按升序查询
	* 退出系统
3. 执行一个具体的功能之后，程序将重新显示菜单。
4. 将学生基本信息保存到文件中。
5. ~~进入系统之前要先输入密码。~~

`其中删除线功能未实现，如果有兴趣实现可以向我Pull requests，功能实现不复杂，有一点需要注意，输入密码需要使用****等覆盖，不能显示明文`


## 使用

* 压缩包下载： [Download Zip](https://github.com/dengjili/class_ms/archive/master.zip)
* 或者git命令下载： 
  ```git clone git@github.com:dengjili/class_ms.git```

* 项目结构截图

<img src="https://raw.githubusercontent.com/dengjili/class_ms/master/picture/import_1.png" width = "400" height = "300" div align=center />

********************
**项目结构说明**

    ---头文件
        ---global.h (全局变量声明)
        ---menu_ui.h (菜单声明)
        ---person.h (班级信息功能实现声明)
        ---person_file.h (文件操作声明)
    ---源文件文件
        ---main.c (全局变量实现)
        ---menu_ui.c (菜单实现)
        ---person.c (班级信息功能实现实现)
        ---person_file.c (文件操作实现)
    ---资源文件
        ---person.dat (文件存储操作的数据，默认有初始化数据)


* 直接运行界面，对系统进行操作

<img src="https://raw.githubusercontent.com/dengjili/class_ms/master/picture/run_1.png" width = "400" height = "300" div align=center />

## 功能演示
所有演示采用GIT动态图演示，有的操作属于合并

### 学生基本信息录入
1. 手工录入已经追加

    其中手动录入为初始化录入一条学生信息，然后选择操作3追加一条学生信息数据，然后再打印录入信息

<img src="https://raw.githubusercontent.com/dengjili/class_ms/master/picture/manual_add.gif" width = "600" height = "450" div align=center />

2. 文件录入

    导入数据来自于文件：`person.dat`，文件为二进制文件，不可使用编辑器直接查看数据。操作为导入文件，然后再打印录入信息

<img src="https://raw.githubusercontent.com/dengjili/class_ms/master/picture/file_add.gif" width = "600" height = "450" div align=center />

### 学生基本信息显示
    信息展示为所有演示功能的基础功能，参考其他即可

### 学生基本信息保存
    添加一条学生信息数据，然后保存最新数据到文件中，然后再操作导入文件，再打印最新文件信息，测试是否保存成功

<img src="https://raw.githubusercontent.com/dengjili/class_ms/master/picture/file_save.gif" width = "600" height = "450" div align=center />

### 学生基本信息删除
    删除一条学生信息
<img src="https://raw.githubusercontent.com/dengjili/class_ms/master/picture/person_delete.gif" width = "600" height = "450" div align=center />

### 学生基本信息修改
    修改一条学生信息
<img src="https://raw.githubusercontent.com/dengjili/class_ms/master/picture/person_update.gif" width = "600" height = "450" div align=center />

### 学生基本信息查询
1. 按学号查询
<img src="https://raw.githubusercontent.com/dengjili/class_ms/master/picture/person_query_by_num.gif" width = "600" height = "450" div align=center />  

2. 按姓名查询
 <img src="https://raw.githubusercontent.com/dengjili/class_ms/master/picture/person_query_by_name.gif" width = "600" height = "450" div align=center />  

### 学生总分成绩查询
1. 按降序查询
<img src="https://raw.githubusercontent.com/dengjili/class_ms/master/picture/person_desc.gif" width = "600" height = "450" div align=center />

2. 按升序查询
<img src="https://raw.githubusercontent.com/dengjili/class_ms/master/picture/person_asc.gif" width = "600" height = "450" div align=center />

### 退出系统
退出系统