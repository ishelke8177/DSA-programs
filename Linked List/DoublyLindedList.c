#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    struct node *next;
    int item;
};

int totalNodes(struct node *s)
{
    int len = 0;
    while(s->next != NULL)
    {
        ++len;
        s=s->next;
    }
    return (len+1);
}

void search(struct node *s , int data)
{
    if(s == NULL)
        printf("there is no node");
    else
    {
        while(1)
        {
            if(s->item == data)
            {
                printf("Found\n");
                break;
            }
            s=s->next;
        }
    }
}

void insertAtStart(struct node **s , int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->prev=*s;
    temp->next=*s;
    temp->item=data;
    *s=temp;
}

void insertAtLast(struct node **s , int data)
{
    struct node *temp , *t;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->next=NULL;
    temp->item=data;

    if(*s == NULL)
        *s=temp;
    else
    {
        t = *s;
        while(t->next != NULL)
            t=t->next;
        t->next=temp;
        temp->prev=t;
    }
}

void insertAfter(struct node **s , int index , int data)
{
    struct node *temp ,*t;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->next=NULL;
    temp->item=data;
    int i=1;

    if(index > totalNodes(*s))
        printf("Invalid Index\n");
    else
    {
        t = *s;
        while(i < index)
        {
            t=t->next;
            i++;
        }
        //Right conn
        temp->next=t->next;
        t->next->prev=temp;

        //Left conn
        t->next=temp;
        temp->prev=t;
    }
}

void deleteFirst(struct node **s)
{
    struct node *t;
    t = *s;

    if((*s)==NULL)
        printf("Underflow");
    else
    {
        *s = t->next;
        free(t);
        printf("First node is deleted.......\n");
    }
}

void deleteLast(struct node **s)
{
    struct node *t1 , *t2;
    t2 = NULL;
    t1 = *s;
    while(t1->next != NULL)
    {
        t2=t1;
        t1=t1->next;
    }
    free(t1);
    t2->next=NULL;
    printf("Last node is deleted.......\n");
}

void deleteNode(struct node **s , int index)
{
    struct node *t1 , *t2;
    int i=1;
    if((*s)==NULL)
        printf("Underflow\n");
    else
    {
        if(index > totalNodes(*s))
            printf("Invalid Index\n");
        else if(index == totalNodes(*s))
            deleteLast(s);
        else
        {
            t1 = *s;
            t2 = t1->next;
            while(i < index-1)
            {
                t1=t1->next;
                i++;
            }
            t1->next=t2->next;
            t2->next->prev=t2->prev;

            free(t2);
        }
    }
}

void reverse(struct node **head)
{
    struct node *lst = *head , *ptr=(*head)->next , *temp;

    while(lst->next!=NULL)
    {
        lst=lst->next;
    }
    //printf("%d",lst->item);

    (*head)->prev=(*head)->next;
    (*head)->next=NULL;

    lst->next=lst->prev;
    lst->prev=NULL;

    while(ptr->next->next!=NULL)
    {
        temp=ptr->next;

        ptr->next=ptr->prev;
        ptr->prev=temp;

        ptr=temp;
    }

    *head=lst;
}

void display(struct node *s)
{
    if(s==NULL)
        printf("Underflow\n");
    else
    {
        while(s->next != NULL)
        {
            printf("%d ",s->item);
            s=s->next;
        }
        printf("%d ",s->item);
        printf("\n");
    }
}

void menu()
{
    printf("\n0.Reverse\n1.insertAtStart\n2.insertAtLast\n3.insertAfter\n4.deleteFirst\n5.deleteLast\n6.deleteNode\n7.Search\n8.Display\n9.totalNodes\n10.Exit\n");
}

int main()
{
    struct node *start=NULL;

    int index=0 , data=0 , ch;

    while(1)
    {
        menu();
        printf("\nEnter : ");
        scanf("%d",&ch);

        switch(ch)
        {
        case 0:
            reverse(&start);
            break;

        case 1:
            printf("Data : ");
            scanf("%d",&data);
            insertAtStart(&start,data);
            break;

        case 2:
            printf("Data  : ");
            scanf("%d",&data);
            insertAtLast(&start,data);
            break;

        case 3:
            printf("Data  : ");
            scanf("%d",&data);

            printf("Index : ");
            scanf("%d",&index);

            insertAfter(&start,index,data);
            break;

        case 4:
            deleteFirst(&start);
            break;

        case 5:
            deleteLast(&start);
            break;

        case 6:
            printf("index : ");
            scanf("%d",&index);
            deleteNode(&start,index);
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
            printf("%d",totalNodes(start));
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
