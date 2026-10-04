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
    printf("7. 统计人数功能\n");
    printf("8. 清空系统内全部学生信息\n");
    printf("9. 修改学生姓名\n");
    printf("0. 关闭程序\n");
    printf("========================\n");
    printf("请输入你的选择：");
}
//功能实现
//添加学生
int AddStu(LinkList L,LNode **r)
{
    LNode *newstu=(LNode *)malloc(sizeof(LNode));
    if(newstu==NULL)
    return 0;
    printf("请输入学生姓名\n");
    scanf("%s",newstu->data.name);
    printf("请输入学生成绩\n");
    scanf("%d",&(newstu->data.score));
    if(newstu->data.score>100||newstu->data.score<0)
    {
        printf("学生成绩不合法\n");
        free(newstu);
        return 0;
    }
    printf("请输入学生学号\n");
    scanf("%d",&(newstu->data.id));
    if(newstu->data.id<0)
    {
        printf("学生学号不合法\n");
        free(newstu);
        return 0;
    }
    LNode *moveAdd=L->next;
    int flag=1;
    
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
    newstu->next=NULL;
    (*r)->next=newstu;
    (*r)=newstu;
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
