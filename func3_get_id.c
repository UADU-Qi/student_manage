#include "manage_stu.h"
//按照学生姓名查询
void FindStu_Name(LinkList L,SNLinkList Lsame)
{
    int flag_name=0;
    char findingname[30];
    printf("请输入学生姓名\n");
    scanf("%s",findingname);
    int ans=SameName(findingname,L,Lsame);
    if(!ans)
    {
        LNode *pfind=L->next;
        while(pfind!=NULL)
        {
            if(strcmp(pfind->data.name,findingname)==0)
            {
                printf("查询到该学生信息如下\n");
                printf("学生姓名:%s\n学生学号:%d\n学生成绩:%d\n",pfind->data.name,pfind->data.id,pfind->data.score);
                printf("========================\n");
                flag_name=1;
                break;
            }
            pfind=pfind->next;
        }
        if(!flag_name)
        printf("学生信息输入错误或学生不存在\n");
    }
    else
    {
        FindStu_ID(L);
    }
    
}
//按照学生学号查询
void FindStu_ID(LinkList L)
{
    int findingid;
    int flag_id=0;
    printf("请输入学生学号\n");
    scanf("%d",&findingid);
    LNode *pfind=L->next;
    while(pfind!=NULL)
    {
        if(findingid==pfind->data.id)
        {
            printf("查询到该学生信息如下\n");
            printf("学生姓名:%s\n学生学号:%d\n学生成绩:%d\n",pfind->data.name,pfind->data.id,pfind->data.score);
            printf("========================\n");
            flag_id=1;
            break;
        }
        else{
            pfind=pfind->next;
        }
    }
    if(!flag_id)
    printf("学生信息输入错误或学生不存在\n");
}