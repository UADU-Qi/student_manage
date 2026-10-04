#include "manage_stu.h"
int FindScoreStu(LinkList L,LinkList Lsort)
{
    //清空释放链表
    LNode *del=Lsort->next;
    Lsort->next=NULL;
    while(del!=NULL)
    {
        LNode *q=del;
        del=del->next;
        free(q);
    }
    //判空
    if(L->next==NULL)
    {
        printf("系统中无可查询信息\n");
        return -1;
    }
    printf("请输入您想查询的分数范围,系统将为您提供学生名单\n");
    int findscoremin,findscoremax;
    //录入分数范围
    printf("请输入最低分数\n");
    scanf("%d",&findscoremin);
    if(findscoremin>100||findscoremin<0)
    {
        printf("成绩异常\n");
        return -1;
    }
    printf("请输入最高分数\n");
    scanf("%d",&findscoremax);
    if(findscoremax>100||findscoremax<0)
    {
        printf("成绩异常\n");
        return -1;
    }
    if(findscoremax<findscoremin)
    {
        printf("范围输入异常,自动更正\n");
        int temp=findscoremax;
        findscoremax=findscoremin;
        findscoremin=temp;    
    }
    printf("现为您查询分数由%d分到%d分范围的学生\n",findscoremin,findscoremax);
    LNode *p=L->next;
    LNode *r=Lsort;
    int find=0;
    int cntstu=0;
    printf("学生名单如下:\n");
    while(p!=NULL)
    {
        if(p->data.score<=findscoremax&&p->data.score>=findscoremin)
        {
            printf("学生姓名:%s\n学生学号:%d\n学生成绩:%d\n",p->data.name,p->data.id,p->data.score);
            printf("========================\n");
            cntstu++;
            //把学生成绩放到链表
            LNode *newsortscore=(LNode *)malloc(sizeof(LNode));
            newsortscore->data=p->data;
            newsortscore->next=NULL;
            r->next=newsortscore;
            r=newsortscore;
            find=1;
        }
        p=p->next;
    }
    if(!find)
    {
        printf("该分数段下未查询到学生\n");
    }
    else
    {
        int sort_op;
        printf("按成绩排序请按“1”,无需请按“0”\n");
        scanf("%d",&sort_op);
        if(sort_op!=1&&sort_op!=0)
        {
            printf("选择异常\n");
            return find;  
        }
        else if(!sort_op)
        {
            return find;
        }
        else
        {
            int op;
            printf("降序排列请按“1”,升序排列请按“2”\n");
            scanf("%d",&op);
            if(op!=1&&op!=2)
            {
            printf("选择异常\n");
            return find;  
            }
            else if(op)
            {
                PrintScore_HightoLow(Lsort,cntstu);
            }
            else
            {
                PrintScore_LowtoHigh(Lsort,cntstu);
            }
            
        }
    }
    return find;
}