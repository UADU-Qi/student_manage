#include "manage_stu.h"
int ChangeName(LinkList L,SNLinkList Lsame)
{
    char oldname[30];
    char newname[30];
    char temp[30];
    printf("请输入旧学生姓名\n");
    scanf("%s",oldname);
    int ans=SameName(oldname,L,Lsame);

    int change_flag=1;
    if(ans==0)
    {
        int find=0;
        LNode *pchange=L->next;
        
        while(pchange!=NULL)
        {
            
            if(strcmp(pchange->data.name,oldname)==0)
            {
                
                printf("请输入学生%s学号%d的新姓名:\n",oldname,pchange->data.id);
                
                strcpy(temp,oldname);
                scanf("%s",newname);
                strcpy(pchange->data.name,newname);
                find=1;
                break;
            }
            pchange=pchange->next;
        }
        if(!find)
        {
            printf("学生姓名输入错误\n");
            change_flag=0;
        }
    }
    //重名
    else
    {
        int samestu_id;
        int find=0;
        LNode *pchange=L->next;
        
        printf("查询到重名情况,请输入对应学生学号\n");
        scanf("%d",&samestu_id);
        while(pchange!=NULL)
        {
            if(pchange->data.id==samestu_id)
            {
                printf("请输入学生%s学号%d的新姓名:\n",oldname,samestu_id);
                
                strcpy(temp,oldname);
                scanf("%s",newname);
                strcpy(pchange->data.name,newname);
                find=1;
                break;   
            }
            pchange=pchange->next;
        }
        if(!find)
        {
            printf("学生学号输入错误\n");
            change_flag=0;
        }
    }
    if(change_flag)
    {
        printf("学生姓名由%s更改为%s\n",temp,newname);
        save_file(L);    
    }
    return change_flag;
}