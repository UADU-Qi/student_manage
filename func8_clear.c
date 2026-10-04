#include "manage_stu.h"
int Clear(LinkList L)
{
    LNode *p=L->next;
    L->next=NULL;
    while(p!=NULL)
    {
        LNode *q=p;
        p=p->next;
        free(q);
    }
    return 1;
}