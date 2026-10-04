#include "manage_stu.h"
int ChangeScore(LinkList L, SNLinkList Lsame)
{
    char changername[30];
    printf("请输入学生姓名\n");
    scanf("%s",changername);
    int ans=SameName(changername,L,Lsame);
    
    int change_flag=1;
    int newscore;
    int oldscore;
    //未重名
    if(ans==0)
    {
        int find=0;
        LNode *pchange=L->next;
        while(pchange!=NULL)
        {
            
            if(strcmp(pchange->data.name,changername)==0)
            {
                
                printf("请输入学生%s的新成绩:\n",changername);
                scanf("%d",&newscore);
                if(newscore>100||newscore<0)
                {
                    printf("成绩异常\n");
                    change_flag=0;
                }
                else
                {
                    oldscore=pchange->data.score;
                    pchange->data.score=newscore;
                }
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
                printf("请输入学生%s学号%d的新成绩:\n",changername,samestu_id);
                scanf("%d",&newscore);
                if(newscore>100||newscore<0)
                {
                    printf("成绩异常\n");
                    change_flag=0;
                }
                else
                {
                    oldscore=pchange->data.score;
                    pchange->data.score=newscore;
                }
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
        printf("学生成绩由%d更改为%d\n",oldscore,newscore);
        save_file(L);    
    }
    return change_flag;
}