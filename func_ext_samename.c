#include "manage_stu.h"
int SameName(char samenames[30],LinkList L,SNLinkList Lsame)
{
    //清空释放链表
    SNNode *del=Lsame->next;
    Lsame->next=NULL;
    while(del!=NULL)
    {
        SNNode *q=del;
        del=del->next;
        free(q);
    }
    int flag=0;
    LNode *psame=L->next;
    SNNode *r=Lsame;
    
        //重名情况
    int same_name_cnt=0;
    while(psame!=NULL)
    {
        //查询有多少个重复这个名字的人
        if(strcmp(samenames,psame->data.name)==0)
        {
            same_name_cnt++;
            SNNode *newsame=(SNNode *)malloc(sizeof(SNNode));
            newsame->sameid=psame->data.id;
            newsame->next=NULL;
            r->next=newsame;
            r=newsame;    
        }
        psame=psame->next;
    }
    if(same_name_cnt>1)
    {
        printf("查询到重名学生\n");
        printf("现在为您提供学号,请根据学号进行后续操作\n");
        flag=1;
        SNNode *p=Lsame->next;
        while(p!=NULL)
        {
            printf("%d\n",p->sameid);
            p=p->next;
        }
        //printf("\n");
        return 1;
    }
    else
    return 0;
}