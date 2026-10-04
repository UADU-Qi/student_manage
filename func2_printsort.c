#include "manage_stu.h"
//打印系统中全部学生信息
int PrintAllStu(LinkList L)
{
    LNode *moveprint=L->next;
    while(moveprint!=NULL)
    {
        printf("学生姓名:%s\n学生学号:%d\n学生成绩:%d\n",moveprint->data.name,moveprint->data.id,moveprint->data.score);
        printf("========================\n");
        moveprint=moveprint->next;
    }
    return 1;
}
int cmp1(const void *a,const void *b)
{
    Stu *sa=(Stu *)a;
    Stu *sb=(Stu *)b;
    return sb->score-sa->score;
}
//按成绩由高到低
void PrintScore_HightoLow(LinkList L,int size)
{
    if(size <= 0)
    {
        printf("暂无学生信息！\n");
        return;
    }
    Stu *s_sc_htol=(Stu *)malloc(sizeof(Stu)*size);//创建动态数组
    LNode *p=L->next;
    Stu *psc1=s_sc_htol;
    while(p!=NULL)
    {
        psc1->score=p->data.score;
        psc1->id=p->data.id;
        strcpy(psc1->name,p->data.name);
        psc1++;
        p=p->next;
    }
    qsort(s_sc_htol,size,sizeof(Stu),cmp1);
    Stu *psc2=s_sc_htol;
    for(int i=0;i<size;i++)
    {
        printf("学生姓名:%s\n学生学号:%d\n学生成绩:%d\n",psc2->name,psc2->id,psc2->score);
        printf("========================\n");
        psc2++;
    }
    free(s_sc_htol);
}
int cmp2(const void *a,const void *b)
{
    Stu *sa=(Stu *)a;
    Stu *sb=(Stu *)b;
    return sa->score-sb->score;
}
//按成绩由低到高
void PrintScore_LowtoHigh(LinkList L,int size)
{
    if(size <= 0)
    {
        printf("暂无学生信息！\n");
        return;
    }
    Stu *s_sc_ltoh=(Stu *)malloc(sizeof(Stu)*size);//创建动态数组
    LNode *p=L->next;
    Stu *psc1=s_sc_ltoh;
    while(p!=NULL)
    {
        psc1->score=p->data.score;
        psc1->id=p->data.id;
        strcpy(psc1->name,p->data.name);
        psc1++;
        p=p->next;
    }
    qsort(s_sc_ltoh,size,sizeof(Stu),cmp2);
    Stu *psc2=s_sc_ltoh;
    for(int i=0;i<size;i++)
    {
        printf("学生姓名:%s\n学生学号:%d\n学生成绩:%d\n",psc2->name,psc2->id,psc2->score);
        printf("========================\n");
        psc2++;
    }
    free(s_sc_ltoh);
}

int cmp3(const void *a,const void *b)
{
    Stu *sa=(Stu *)a;
    Stu *sb=(Stu *)b;
    return sb->id-sa->id;
}
//按学号由高到低
void PrintID_HightoLow(LinkList L,int size)
{
    if(size <= 0)
    {
        printf("暂无学生信息！\n");
        return;
    }
    Stu *s_id_htol=(Stu *)malloc(sizeof(Stu)*size);//创建动态数组
    LNode *p=L->next;
    Stu *pid1=s_id_htol;
    while(p!=NULL)
    {
        pid1->score=p->data.score;
        pid1->id=p->data.id;
        strcpy(pid1->name,p->data.name);
        pid1++;
        p=p->next;
    }
    qsort(s_id_htol,size,sizeof(Stu),cmp3);
    Stu *pid2=s_id_htol;
    for(int i=0;i<size;i++)
    {
        printf("学生姓名:%s\n学生学号:%d\n学生成绩:%d\n",pid2->name,pid2->id,pid2->score);
        printf("========================\n");
        pid2++;
    }
    free(s_id_htol);
}
int cmp4(const void *a,const void *b)
{
    Stu *sa=(Stu *)a;
    Stu *sb=(Stu *)b;
    return sa->id-sb->id;
}
//按学号由低到高
void PrintID_LowtoHigh(LinkList L,int size)
{
    if(size <= 0)
    {
        printf("暂无学生信息！\n");
        return;
    }
    Stu *s_id_ltoh=(Stu *)malloc(sizeof(Stu)*size);//创建动态数组
    LNode *p=L->next;
    Stu *pid1=s_id_ltoh;
    while(p!=NULL)
    {
        pid1->score=p->data.score;
        pid1->id=p->data.id;
        strcpy(pid1->name,p->data.name);
        pid1++;
        p=p->next;
    }
    qsort(s_id_ltoh,size,sizeof(Stu),cmp4);
    Stu *pid2=s_id_ltoh;
    for(int i=0;i<size;i++)
    {
        printf("学生姓名:%s\n学生学号:%d\n学生成绩:%d\n",pid2->name,pid2->id,pid2->score);
        printf("========================\n");
        pid2++;
    }
    free(s_id_ltoh);
}