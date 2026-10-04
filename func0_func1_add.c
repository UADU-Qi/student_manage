#include "manage_stu.h"
//页面显示
void welcome_ops()
{
    printf("\n===== 学生管理系统 =====\n");
    printf("1. 添加学生\n");
    printf("2. 显示所有学生信息\n");
    printf("3. 查找学生\n");
    printf("4. 修改学生成绩\n");
    printf("5. 删除学生\n");
    printf("6. 按成绩查询\n");
    printf("7. 统计功能\n");
    printf("0. 退出系统\n");
    printf("========================\n");
    printf("请输入你的选择：");
}
//功能实现
//添加学生
int AddStu(LinkList L,LNode **r,int *size)
{
    LNode *newstu=(LNode *)malloc(sizeof(LNode));
    if(newstu==NULL)
    return 0;
    printf("请输入学生姓名\n");
    scanf("%s",newstu->data.name);
    printf("请输入学生成绩\n");
    scanf("%d",&(newstu->data.score));
    printf("请输入学生学号\n");
    scanf("%d",&(newstu->data.id));
    LNode *moveAdd=L->next;
    int flag=1;
    if(newstu->data.score>100||newstu->data.score<0)
    {
        printf("学生成绩不合法\n");
        free(newstu);
        return 0;
    }
    while(moveAdd!=NULL)
    {
        if(strcmp(moveAdd->data.name,newstu->data.name)!=0&&moveAdd->data.id==newstu->data.id)
        {
            printf("学生学号已存在,输入错误\n");
            flag=0;
            break;
        }
        if(strcmp(moveAdd->data.name,newstu->data.name)==0&&moveAdd->data.id==newstu->data.id)
        {
            printf("学生已存在，请勿重复录入\n");
            flag=0;
            break;
        }
        
        moveAdd = moveAdd->next;
    }
    if(!flag)
    {
        free(newstu);
        return 0;
    }
    //重名情况
    // int same_name_cnt=0;
    // LNode *p=L->next;
    // while(p!=NULL)
    // {
    //     //查询有多少个重复这个名字的人
    //     if(strcmp(p->data.name,newstu->data.name)==0&&p->data.id!=newstu->data.id)
    //     same_name_cnt++;
    //     p=p->next;
    // }
    // if(same_name_cnt>0)
    //     {
    //         char num[5];
    //         sprintf(num,"%d",same_name_cnt);
    //         strcat(newstu->data.name,num);
    //         printf("监测到重名学生，学生姓名更名为%s\n",newstu->data.name);
    //     }
    newstu->next=NULL;
    (*r)->next=newstu;
    (*r)=newstu;
    (*size)++;
    int op_save;
    printf("是否保存学生信息\n");
    printf("保存请按“1”,不保存请按“0”\n");
    scanf("%d",&op_save);
    if(op_save){
        if(save_file(L))
    {
        printf("学生信息保存成功\n");
    }
    }
    
    return 1;
}
