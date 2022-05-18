#include <stdio.h>
#include <stdlib.h>

struct node
{
    int item;
    struct node *next;
    struct node *prev;
};

int totalNodes(struct node *l)
{
    int len=0;
    struct node *t = l->next;
    while(t != l)
    {
        len++;
        t=t->next;
    }
    return(len+1);
}

struct node* search(struct node *l , int data)
{
    struct node* t;
    t = l->next;
    while(t != l)
    {
        if(t->item==data)
            return t;
        t = t->next;
    }
    return NULL;
}

void insertAtFirst(struct node **l , int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->item=data;
    temp->prev=NULL;

    if((*l)==NULL)
    {
        (*l) = temp;
        temp->next=temp;
        temp->prev=temp;
    }
    else
    {
        temp->next=(*l)->next;
        (*l)->next->prev=temp;
        temp->prev=(*l);
        (*l)->next=temp;
    }
}

void insertAtLast(struct node **l , int data)
{
    struct node *temp , *t;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->item=data;
    temp->prev=NULL;

    if((*l)==NULL)
    {
        (*l) = temp;
        temp->next=temp;
        temp->prev=temp;
    }
    else
    {
        t = (*l)->next;
        //left conn
        (*l)->next=temp;
        temp->prev= *l;
        (*l)=temp;

        (*l)->next=t;
        t->prev=temp;
    }
}

void insertAfter(struct node **l , int data , int val)
{
    struct node *temp , *t , *p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->next=NULL;
    temp->item=data;
    temp->prev=NULL;

    if((*l)->item == val)
        insertAtLast(l,data);
    else
    {
        if((*l)->next->item == val)
            insertAtFirst(l,data);
        else
        {
            t = search(*l,val);

            p = t->next;
            t->next=temp;
            temp->prev=t;
            temp->next=p;
            temp->next->prev=temp;
        }
    }
}

void deleteFirst(struct node **l)
{
    struct node *t = (*l)->next;

    if((*l)==NULL)
        printf("Underflow.....\n");
    else
    {
        t->next->prev=(*l);
        (*l)->next=t->next;
        free(t);
        (*l)=NULL;
    }
}

void deleteLast(struct node **l)
{
    struct node *t = (*l);

    if((*l)==NULL)
        printf("Underflow......\n");
    else
    {
        if(t->prev == (*l)->next)
        {
            free(t);
            (*l)=NULL;
        }
        else
        {
            (*l)=t->prev;
            (*l)->next=t->next;
            t->next->prev=(*l);
            free(t);
        }
    }
}

void deleteNode(struct node **l , int val)
{
    struct node *t=search(*l,val);
    if((*l)->item==val)
        deleteLast(l);
    else
    {
        if((*l)==t)
            deleteFirst(l);
        else
        {
            t->prev->next=t->next;
            t->next->prev=t->prev;
            free(t);
        }
    }
}

void display(struct node *l)
{
    struct node *t;
    if(l==NULL)
        printf("Underflow......\n");
    else
    {
        t = l->next;
        while(t->next != l->next)
        {
            printf("%d ",t->item);
            t=t->next;
        }
        printf("%d ",l->item);
        printf("\n");
    }
}

void menu()
{
    printf("\n1.insertAtStart\n2.insertAtLast\n3.insertAfter\n4.deleteFirst\n5.deleteLast\n6.deleteNode\n7.Search\n8.Display\n9.totalNodes\n10.Exit\n");
}

int main()
{
    struct node *last=NULL;

    int index=0 , data=0 , ch=0 , val=0;

    while(1)
    {
        menu();
        printf("\nEnter : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Data  : ");
                scanf("%d",&data);
                insertAtFirst(&last,data);
                break;

            case 2:
                printf("Data : ");
                scanf("%d",&data);
                insertAtLast(&last,data);
                break;

            case 3:
                printf("Data  : ");
                scanf("%d",&data);

                printf("Insert after value : ");
                scanf("%d",&val);

                insertAfter(&last,data,val);
                break;

            case 4:
                deleteFirst(&last);
                break;

            case 5:
                deleteLast(&last);
                break;

            case 6:
                printf("Val : ");
                scanf("%d",&data);
                deleteNode(&last,data);
                break;

            case 7:
                printf("Data : ");
                scanf("%d",&data);
                printf("%d",search(last,data));
                printf("\n");
                break;

            case 8:
                display(last);
                break;

            case 9:
                printf("%d",totalNodes(last));
                printf("\n");
                break;

            case 10:
                exit(0);

            default:
                printf("Invalid\n");
            }
    }
    return 0;
}
