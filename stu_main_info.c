#include "manage_stu.h"
//主界面及功能调用
int main()
{
    //int size=0;
    LinkList L;
    L=(LNode *)malloc(sizeof(LNode));
    if(L==NULL)
    return -1;
    L->next=NULL;
    LNode *r=L;
    get_from_file(L,&r);

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
                AddStu(L,&r);
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
                printf("系统中无可显示的学生信息\n");
                break;
            }
            else
            {
            int op_print;
            int size=CountStu(L);
            printf("\n");
            printf("请选择打印方式\n");
            printf("按录入顺序打印请按“1”\n");
            printf("按成绩由高到低打印请按“2”\n");
            printf("按成绩由低到高打印请按“3”\n");
            printf("按学号由高到低打印请按“4”\n");
            printf("按学号由低到高打印请按“5”\n");
            scanf("%d",&op_print);
            
            if(op_print==1)
            {
                printf("学生信息如下:\n");
                PrintAllStu(L);
            }
            else if(op_print==2)
            {
                printf("学生信息如下:\n");
                PrintScore_HightoLow(L,size);
            }
            else if(op_print==3)
            {
                printf("学生信息如下:\n");
                PrintScore_LowtoHigh(L,size);
            }
            else if(op_print==4)
            {
                printf("学生信息如下:\n");
                PrintID_HightoLow(L,size);
            }
            else if(op_print==5)
            {
                printf("学生信息如下:\n");
                PrintID_LowtoHigh(L,size);
            }
            else
            {
                printf("选择错误\n");
                break;
            }
            printf("学生人数共计%d人\n",size);
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
            
            int sub_op;
            do{
                //判空
                if(L->next==NULL)
                {
                    printf("系统中无可删除信息\n");
                    break;
                }
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
            
            int sub_op;
            do{
                //判空
                if(L->next==NULL)
                {
                    printf("系统中无可删除信息\n");
                    break;
                }
                int ans5=DelStu_name(L,Lsame);
                if(!ans5)
                printf("操作失败\n");
                if(L->next==NULL)
                {
                    printf("系统中无可再删除信息\n");
                    break;
                }
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
            int count=CountStu(L);
            printf("系统中学生数量总计为%d\n",count);
            break;
        }
        case 8:
        {
            //判空
            if(L->next==NULL)
            {
                printf("系统中无可删除信息\n");
                break;
            }
            printf("请您确定是否删除全部学生信息\n");
            printf("确定请按“1”,返回菜单请按“0”\n");
            int op;
            scanf("%d",&op);
            if(op!=1&&op!=0)
            {
                printf("选择异常\n");
            }
            else if(op==1)
            {
                int ans=Clear(L);
                save_file(L);
                if(ans)
                {
                    printf("清空成功\n");
                }
            }
            break;
        }
        case 0:
        {
            save_file(L);
            return 0;
        }
        default:
            printf("选择异常\n");
            break;
        }
    }
    
}