#include <stdio.h>
#include <stdlib.h>

struct node
{
    int item;
    struct node *next;
};

void removeDuplicates(struct node *head)
{
    struct node *t1=head , *t2=head->next , *pt=head ;

    while(pt->next!=NULL)
    {
        while(t2!=NULL)
        {
            if(t2->item == pt->item)
            {
                t1->next = t2->next;
                free(t2);
                t2 = t1;
            }

            t1=t2;
            t2=t2->next;
        }

        if(pt->next==NULL)
            break;

        t2 = pt->next->next;
        t1 = pt->next;

        pt=pt->next;
    }
}

struct node* search(struct node *s,int data)
{
    struct node *t;
    t=s;
    while(t)
    {
        if(t->item==data)
            return t;
        t=t->next;
    }
    return NULL;
}

void deleteNode(struct node **s, int pos)
{
    struct node *t1=*s , *t2=NULL ;
    int len=0,i=0;

    while(t1!=NULL)
    {
        len++;
        t1=t1->next;
    }
    t1=*s;

    if(pos == 0)        //first
    {
        *s = t1->next;
        free(t1);
    }
    else if(pos == len-1)       //last
    {
        while(t1->next!=NULL)
        {
            t2=t1;
            t1=t1->next;
        }
        t2->next=NULL;
        free(t1);
    }
    else        //particular
    {
        while(i<pos)
        {
            t2=t1;
            t1=t1->next;
            i++;
        }
        t2->next=t1->next;
        free(t1);
    }
}

void deleteFirst(struct node **s)
{
    struct node *temp;

    if((*s)==NULL)
        printf("Underflow........\n");
    else
    {
        temp = *s;
        *s=temp->next;
        free(temp);
    }
}

void deleteLast(struct node **s)
{
    struct node *t1 , *t2;

    if((*s)==NULL)
        printf("Underflow");
    else
    {
        if((*s)->next==NULL)
        {
            free(*s);
            *s=NULL;
        }
        else
        {
            t2=NULL;
            t1=*s;
            while(t1->next!=NULL)
            {
                t2=t1;
                t1=t1->next;
            }
            free(t1);
            t2->next=NULL;
        }
    }
}

void insertAtStart(struct node **s , int data)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->item=data;
    temp->next=*s;
    *s=temp;
}

void insertAtLast(struct node **s , int data)
{
    struct node *t,*temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->item=data;
    temp->next=NULL;
    if(*s==NULL)
        *s=temp;
    else
    {
        t=*s;
        while(t->next!=NULL)
            t=t->next;
        t->next=temp;
    }
}

void insertAfter(struct node *t , int data)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->item=data;
    temp->next=t->next;
    t->next=temp;
}

void insertAt(struct node **s , int data , int pos)
{
    struct node *t = *s,*temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->item=data;
    temp->next=NULL;

    int len=0,i=0;
    while(t!=NULL)
    {
        len++;
        t=t->next;
    }
    t=*s;

    if(pos == 0)
    {
        *s = temp;
        (*s)->next=t;
    }
    else
    {
        while(i<pos-1)
        {
            t=t->next;
            i++;
        }
        temp->next=t->next;
        t->next=temp;
    }
}

void reverseList(struct node **s)
{
    struct node *p=NULL , *n=NULL, *c = *s ;

    while(c!=NULL)
    {
        n = c->next;
        c->next=p;
        p=c;
        c=n;
    }
    *s = p;
}

void sortList(struct node *s)
{
    struct node *t1=s , *t2 = s->next;
    int len=0;
    while(t1->next!=NULL)
    {
        len++;
        t1=t1->next;
    }
    len++;
    t1=s;
    //printf("%d ",t1->item);
    int temp;

    int i=0;
    while(i<len-1)
    {
        while(t2!=NULL)
        {
            if(t2->item < t1->item)
            {
                temp = t2->item;
                t2->item = t1->item;
                t1->item = temp;
            }
            t2=t2->next;
            t1=t1->next;
        }
        t2=s->next;
        t1=s;
        i++;
    }

}

int detectLoop(struct node *s)
{
    struct node *t1 , *t2=s ,*p=s;
    int flag = 0;

    while(t2->next!=NULL)
    {
        t1 = p;
        t2 = t2->next;
        t2 = t2->next;
        p = p->next;

        if(t1 == t2)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}
/*
int lengthOFLoop()
{
    struct node *t1 , *t2 ,p = *s , *z;

    t2 = s->next;
    t1 = NULL;
    while(t2->next!=NULL)
    {
        t2 = t2->next;
        t1 = p;
        p = p->next;

        if(t1 == t2)
        {
            z = t1;
            break;
        }
    }
    return flag;
}
*/
void display(struct node *s)
{
    struct node *t;
    if(s == NULL)
        printf("Underflow\n");
    else
    {
        t = s;
        while(t->next != NULL)
        {
            printf("%d ",t->item);
            t=t->next;
        }
        printf("%d",t->item);
        printf("\n");
    }
}

void menu()
{
    printf("\n1.insertAtStart\n2.insertAtLast\n3.insertAfter\n4.insertAt\n5.deleteFirst\n6.deleteLast\n7.deleteNode\n8.Search\n9.Display\n10.reverse\n11.Exit\n12.Sort\n13.Remove duplicates\n");
}

int main()
{
    struct node *start = NULL;

    int ch , data=0,pos=0;
    while(1)
    {
        menu();
        printf("\nEnter : ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            printf("Data : ");
            scanf("%d",&data);
            insertAtStart(&start,data);
            break;

        case 2:
            printf("Data : ");
            scanf("%d",&data);
            insertAtLast(&start,data);
            break;

        case 3:
            printf("Data : ");
            scanf("%d",&data);
            insertAfter(start,data);
            break;

        case 4:
            pos=0;

            printf("Data : ");
            scanf("%d",&data);

            printf("Position : ");
            scanf("%d",&pos);
            insertAt(&start,data,pos);
            break;
        case 5:
            deleteFirst(&start);
            break;

        case 6:
            deleteLast(&start);
            break;

        case 7:
            printf("Position : ");
            scanf("%d",&pos);
            deleteNode(&start,pos);
            break;

        case 8:
            printf("Data : ");
            scanf("%d",&data);
            search(start,data);
            break;

        case 9:
            display(start);
            break;

        case 10:
            reverseList(&start);
            break;

        case 11:
            exit(0);

        case 12:
            sortList(start);
            break;

        case 13:
            removeDuplicates(start);
            break;

        default:
            printf("Invalid\n");
        }
    }
    free(start);
    return 0;
}
