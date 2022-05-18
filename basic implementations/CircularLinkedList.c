#include <stdio.h>
#include <stdlib.h>

struct node
{
    int item;
    struct node *next;
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
    struct node *t;

    t=l->next;
    while(t != l)
    {
        if(t->item == data)
            return t;
        t=t->next;
    }
    return NULL;
}

void insertAtFirst(struct node **l , int data)
{
    struct node *temp , *t;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->next=temp;
    temp->item=data;

    if((*l)==NULL)
        *l = temp;
    else
    {
        //(*l)->next=temp;
        //temp->next=(*l)->next;
        t = (*l)->next;
        (*l)->next=temp;
        temp->next=t;

    }
}

void insertAtLast(struct node **l , int data)
{
    struct node *temp , *t;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->next=temp;
    temp->item=data;

    if((*l)==NULL)
        *l = temp;
    else
    {
        t=(*l)->next;
        (*l)->next=temp;
        (*l)=temp;
        (*l)->next=t;
    }
}

void insertAfter(struct node **l , int data , int val)
{
    struct node *temp , *t1 , *t2;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->item=data;

    if((*l)->item == val)
        insertAtLast(l,data);
    else
    {
        t1 = search(*l,val);
        t2 = t1->next;

        t1->next=temp;
        temp->next=t2;
    }
}

void deleteFirst(struct node **l)
{
    struct node *t;
    if((*l)==NULL)
        printf("Underflow\n");
    else
    {
        if((*l)==(*l)->next)
        {
            t = *l;
            free(t);
            *l=NULL;
        }
        else
        {
            t = *l;
            t=t->next;
            (*l)->next=t->next;
            free(t);
        }
    }
}

void deleteLast(struct node **l)
{
    struct node *t1 , *t2;
    if((*l)==NULL)
        printf("Underflow\n");
    else
    {
        if((*l) == (*l)->next)
        {
            free(*l);
            *l=NULL;
        }
        else
        {
            t1 = (*l)->next;

            while((*l) != t1->next)
            {
                //t2 = t1;
                t1=t1->next;
            }
            t2 = *l;
            *l = t1;
            (*l)->next=t2->next;
            free(t2);
        }
    }
}

void deleteNode(struct node **l , int data)
{
    struct node *t1 , *t2;
    t1 = search(*l,data);


    if(t1=(*l))
        deleteLast(l);
    else
    {
        if((*l) == (*l)->next)
            deleteFirst(l);
        else
        {
            t2 = (*l)->next;

            while(t2->next != t1)
                t2=t2->next;

            t2->next = t1->next;
            free(t1);
        }
    }
}

void display(struct node *l)
{
    struct node *t;
    if(l==NULL)
        printf("Underflow\n");
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

    int index=0 , data=0 , ch , val=0;

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
                insertAtFirst(&last,data);
                break;

            case 2:
                printf("Data  : ");
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
                printf("data : ");
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
