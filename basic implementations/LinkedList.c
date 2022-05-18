#include <stdio.h>
#include <stdlib.h>

struct node
{
    int item;
    struct node *next;
};

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

void deleteFirst(struct node **s)
{
    struct node *temp;

    if((*s)==NULL)
        printf("Underflow");
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
            t1=*s;              //doubt
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

void getNode(struct node **s , int pos)
{
    struct node *c = *s , *p = NULL , *n = NULL , *t = *s;
    int len=0;
    while(t->next!=NULL)
    {
        t=t->next;
        len++;
    }

    while(c!=NULL)
    {
        n = c->next;
        c->next=p;
        p=c;
        c=n;
    }
    *s = p;

    int i=0;
    struct node *temp = *s;
    while(i < pos)
    {
        temp = temp->next;
        i++;
    }
    printf("%d",temp->item);
    printf("\n");
}

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
    printf("\n0.getNode\n1.insertAtStart\n2.insertAtLast\n3.insertAfter\n4.deleteFirst\n5.deleteLast\n6.deleteNode\n7.Search\n8.Display\n9.Exit\n");
}

int main()
{
    struct node *start = NULL;

    int ch , data=0,pos=0;
    while(1)
    {
        menu();
        printf("Enter : ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 0:
            printf("Position : ");
            scanf("%d",&pos);
            getNode(&start,pos);
            break;

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
            deleteFirst(&start);
            break;

        case 5:
            deleteLast(&start);
            break;

        case 7:
            printf("Data : ");
            scanf("%d",&data);
            search(start,data);
            break;

        case 8:
            display(start);
            break;

        case 9:
            exit(0);

        default:
            printf("Invalid\n");
        }
    }
    return 0;
}
