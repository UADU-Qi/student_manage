#include "manage_stu.h"
//保存学生信息
int save_file(LinkList L)
{
    FILE *fp=fopen("stu_manage.txt","wb");
    if(fp==NULL)
    {
        perror("保存失败");
        return 0;
    }
    LNode *p=L->next;
    while(p!=NULL)
    {
        size_t x=fwrite(&(p->data),sizeof(Stu),1,fp);
        if(x!=1)
        {
            perror("保存失败");
            fclose(fp);
            return 0;
        }
        p=p->next;
    }
    fclose(fp);
    //printf("保存成功\n");
    return 1;
}
//从文件获取已保存的学生信息
int get_from_file(LinkList L,LNode **r)
{
    FILE *fp=fopen("stu_manage.txt","rb");
    if(fp==NULL)
    {
        return 0;
    }
    LNode *p=L->next;
    L->next=NULL;
    while(p!=NULL)
    {
        LNode *q=p;
        p=p->next;
        free(q);
    }

    //LNode *r=L;
    Stu temp;
    while(fread(&temp,sizeof(Stu),1,fp)==1)
    {
        LNode *newnode=(LNode *)malloc(sizeof(LNode));
        if(newnode==NULL)
        {
            fclose(fp);
            return 0;
        }
        
        newnode->data=temp;
        newnode->next=NULL;
        (*r)->next=newnode;
        (*r)=newnode;
    }
    fclose(fp);
    return 1;
}