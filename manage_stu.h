#ifndef MANAGE_STU_H
#define MANAGE_STU_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//学生结构体，封装学生信息
typedef struct{
    char name[30];//姓名
    int score;//成绩
    int id;//学号
}Stu;
//链表存储学生信息，便于增删改
typedef struct LNode{
    Stu data;//内部放置封装好的学生信息结构体
    struct LNode *next;
}LNode,*LinkList;

//重名学生学号链表
typedef struct SameNameNode{
    int sameid;
    struct SameNameNode *next;
}SNNode,*SNLinkList;
//可能重名情况
int SameName(char samenames[30],LinkList L,SNLinkList Lsame);

//部分学生成绩排序
// typedef struct SortScore{
//     int unsortscore;
//     struct SortScore *next;
// }SCNode,*SCLinkList;

//从文件中导入保存过的学生信息
int get_from_file(LinkList L,LNode **r);
//主页面
void welcome_ops();
int save_file(LinkList L);
//1. 添加学生
int AddStu(LinkList L,LNode **r);
//2. 显示所有学生信息
int PrintAllStu(LinkList L);
void PrintScore_HightoLow(LinkList L,int size);
void PrintScore_LowtoHigh(LinkList L,int size);
void PrintID_HightoLow(LinkList L,int size);
void PrintID_LowtoHigh(LinkList L,int size);
//3. 查找学生
void FindStu_Name(LinkList L,SNLinkList Lsame);
void FindStu_ID(LinkList L);
//4. 修改学生成绩
int ChangeScore(LinkList L, SNLinkList Lsame);
//5. 删除学生
int DelStu_name(LinkList L,SNLinkList Lsame);
//6. 按成绩查询
int FindScoreStu(LinkList L,LinkList Lsort);
//7. 统计功能
int CountStu(LinkList L);
//8.清空系统全部学生信息
int Clear(LinkList L);
//0. 关闭程序
#endif