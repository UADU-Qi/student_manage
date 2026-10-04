#include "manage_stu.h"
//统计学生数量
//返回值为人数
int CountStu(LinkList L)
{
    LNode *p=L->next;
    int cnt=0;
    while(p!=NULL)
    {
        cnt++;
        p=p->next;
    }
    return cnt;
}