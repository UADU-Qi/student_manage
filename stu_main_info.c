#include "manage_stu.h"
//主界面及功能调用
int main()
{
    int size=0;
    LinkList L;
    L=(LNode *)malloc(sizeof(LNode));
    if(L==NULL)
    return -1;
    L->next=NULL;
    LNode *r=L;
    get_from_file(L);

    //存在重名
    SNLinkList Lsame;
    Lsame=(SNNode *)malloc(sizeof(SNNode));
    if(Lsame==NULL)
    return -1;
    Lsame->next=NULL;

    //部分学生成绩排序
    LinkList Lsort;
    Lsort=(LNode *)malloc(sizeof(LNode));
    if(Lsort==NULL)
    return -1;
    Lsort->next=NULL;
    
    //添加学生
    while(1)
    {
        int op;
        welcome_ops();
        scanf("%d",&op);
        switch (op)
        {
        case 1:
        //添加学生
        {
            int sub_op;
            do
            {
                AddStu(L,&r,&size);
                printf("继续添加请按“1”,返回菜单请按“0”\n");
                scanf("%d",&sub_op); 
                if(sub_op!=1&&sub_op!=0)
                {
                    printf("选择异常\n");
                    sub_op=0;
                }   
            } while (sub_op==1);
            printf("退出添加学生功能,返回菜单\n");
            break;
        }
        
        case 2:
        {
            if(L->next==NULL)
            {
                printf("系统中无可查询信息\n");
                break;
            }
            else
            {
            int op_print;
            printf("\n");
            printf("请选择打印方式\n");
            printf("按录入顺序打印请按“1”\n");
            printf("按成绩由高到低打印请按“2”\n");
            printf("按成绩由低到高打印请按“3”\n");
            printf("按学号由高到低打印请按“4”\n");
            printf("按学号由低到高打印请按“5”\n");
            scanf("%d",&op_print);
            printf("学生信息如下:\n");
            if(op_print==1)
            {
                PrintAllStu(L);
            }
            else if(op_print==2)
            {
                PrintScore_HightoLow(L,size);
            }
            else if(op_print==3)
            {
                PrintScore_LowtoHigh(L,size);
            }
            else if(op_print==4)
            {
                PrintID_HightoLow(L,size);
            }
            else if(op_print==5)
            {
                PrintID_LowtoHigh(L,size);
            }
            else
            {
                printf("选择错误\n");
            }
            break;
            }
        }
        case 3:
        {
            if(L->next==NULL)
            {
                printf("系统中无可查询信息\n");
                break;
            }
            int op_find;
            printf("请选择查找方式\n");
            printf("按姓名查找请按“1”\n");
            printf("按学号查找请按“2”\n");
            scanf("%d",&op_find);
            if(op_find==1)
            {
                FindStu_Name(L,Lsame);
            }
            else if(op_find==2)
            {
                FindStu_ID(L);
            }
            else
            {
                printf("选择错误\n");
            }
            break;
        }
        case 4:
        {
            if(L->next==NULL)
            {
                printf("系统中无可修改信息\n");
                break;
            }
            int sub_op;
            do{

                int ans4=ChangeScore(L,Lsame);
                if(ans4)
                printf("学生成绩修改并保存成功\n");
                else
                printf("操作失败\n");
                printf("继续更改请按“1”,返回菜单请按“0”\n");
                scanf("%d",&sub_op);
                if(sub_op!=1&&sub_op!=0)
                {
                    printf("选择异常\n");
                    sub_op=0;
                }
            }while(sub_op==1);
            printf("退出更改学生成绩功能,返回菜单\n");
            break;
            
        }
        case 5:
        {
            //判空
            if(L->next==NULL)
            {
                printf("系统中无可删除信息\n");
                break;
            }
            int sub_op;
            do{

                int ans5=DelStu_name(L,Lsame);
                if(!ans5)
                printf("操作失败\n");
                printf("继续删除请按“1”,返回菜单请按“0”\n");
                scanf("%d",&sub_op);
                if(sub_op!=1&&sub_op!=0)
                {
                    printf("选择异常\n");
                    sub_op=0;
                }
            }while(sub_op==1);
            printf("退出删除学生信息功能,返回菜单\n");
            break;
        }
        case 6:
        {
            int sub_op;
            do{
            int ans6=FindScoreStu(L,Lsort);
            if(ans6==-1)
            {
                break;
            }
            else
            {
                printf("继续查询请按“1”,返回菜单请按“0”\n");
                scanf("%d",&sub_op);
                if(sub_op!=1&&sub_op!=0)
                {
                    printf("选择异常\n");
                    sub_op=0;
                }
            }
            
            }while(sub_op==1);
            printf("退出按成绩查询功能,返回菜单\n");
            break;
        }
        case 7:
        {
            break;
        }
        default:
            break;
        }
    }
    return 0;
}
