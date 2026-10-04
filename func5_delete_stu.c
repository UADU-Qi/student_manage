#include "manage_stu.h"
int DelStu_name(LinkList L,SNLinkList Lsame)
{
    
    char deletename[30];
    printf("请输入学生姓名\n");
    scanf("%s",deletename);
    int ans=SameName(deletename,L,Lsame);
    int delete_flag=1;
    int find=0;
    //未重名
    if(ans==0)
    {
        LNode *pdelete=L;
        while(pdelete->next!=NULL)
        {
            
            if(strcmp(pdelete->next->data.name,deletename)==0)
            {
                find=1;
                LNode *q=pdelete->next;
                pdelete->next=pdelete->next->next;
                free(q);
                break;
            }
            
            pdelete=pdelete->next;
        }
        if(!find)
        {
            printf("学生信息输入错误\n");
            delete_flag=0;
        }
    }
    else
    {
        int deletestu_id;
        LNode *pdelete=L;
        printf("查询到重名情况,请输入对应学生学号\n");
        scanf("%d",&deletestu_id);
        while(pdelete->next!=NULL)
        {
            if(pdelete->next->data.id==deletestu_id)
            {
                find=1;
                LNode *q=pdelete->next;
                pdelete->next=pdelete->next->next;
                free(q);
                break;
            }
            pdelete=pdelete->next;
        }
        if(!find)
        {
            printf("学生学号输入错误\n");
            delete_flag=0;
        }
    }
    if(delete_flag)
    {
        save_file(L);
        printf("学生删除成功\n");
    }
    return delete_flag;
}