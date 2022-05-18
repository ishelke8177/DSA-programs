#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class CLL
{
    struct node
    {
        int item;
        node *next;
    }*last;
public:
    int totalNodes();
    node* Search(int);
    void insertAtFirst(int);
    void insertAtLast(int);
    void insertAfter(int,int);
    void deleteFirst();
    void deleteLast();
    void deleteNode(int);
    void display();
    ~CLL()
    {
        while(last!=NULL)
            deleteFirst();
    }
};


int CLL::totalNodes()
{
    int len=0;
    node *t = last->next;
    while(t != last)
    {
        len++;
        t=t->next;
    }
    return(len+1);
}

node* CLL::Search(int data)
{
    node *t;

    t=last->next;
    while(t != last)
    {
        if(t->item == data)
            return t;
        t=t->next;
    }
    return NULL;
}

void CLL::insertAtFirst(int data)
{
    node *temp , *t;
    temp = new node;;
    temp->next=temp;
    temp->item=data;

    if(last==NULL)
        last = temp;
    else
    {
        t = last->next;
        last->next=temp;
        temp->next=t;
    }
}

void CLL::insertAtLast(int data)
{
    node *temp , *t;
    temp = new node;
    temp->next=temp;
    temp->item=data;

    if(last==NULL)
        last = temp;
    else
    {
        t=last->next;
        last->next=temp;
        last=temp;
        last->next=t;
    }
}

void CLL::insertAfter(int data , int val)
{
    node *temp , *t1 , *t2;
    temp = new node;
    temp->item=data;

    if(last->item == val)
        insertAtLast(data);
    else
    {
        t1 = Search(val);
        t2 = t1->next;

        t1->next=temp;
        temp->next=t2;
    }
}

void CLL::deleteFirst()
{
    node *t;
    if(last==NULL)
        printf("Underflow\n");
    else
    {
        if(last==last->next)
        {
            t = last;
            free(t);
            last=NULL;
        }
        else
        {
            t = last;
            t=t->next;
            last->next=t->next;
            free(t);
        }
    }
}

void CLL::deleteLast()
{
    node *t1 , *t2;
    if(last==NULL)
        printf("Underflow\n");
    else
    {
        if(last == last->next)
        {
            free(last);
            last=NULL;
        }
        else
        {
            t1 = last->next;

            while(last != t1->next)
            {
                t1=t1->next;
            }
            t2 = last;
            last = t1;
            last->next=t2->next;
            free(t2);
        }
    }
}

void CLL::deleteNode(int data)
{
    node *t1 , *t2;
    t1 = Search(data);

    if(t1=last)
        deleteLast();
    else
    {
        if(last == last->next)
            deleteFirst();
        else
        {
            t2 = last->next;

            while(t2->next != t1)
                t2=t2->next;

            t2->next = t1->next;
            free(t1);
        }
    }
}

void CLL::display()
{
    node *t;
    if(last==NULL)
        printf("Underflow\n");
    else
    {
        t = last->next;
        while(t->next != last->next)
        {
            printf("%d ",t->item);
            t=t->next;
        }
        printf("%d ",last->item);
        printf("\n");
    }
}

void menu()
{
    printf("\n1.insertAtStart\n2.insertAtLast\n3.insertAfter\n4.deleteFirst\n5.deleteLast\n6.deleteNode\n7.Search\n8.Display\n9.totalNodes\n10.Exit\n");
}

int main()
{
    CLL myObj;
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
                myObj.insertAtFirst(data);
                break;

            case 2:
                printf("Data  : ");
                scanf("%d",&data);
                myObj.insertAtLast(data);
                break;

            case 3:
                printf("Data  : ");
                scanf("%d",&data);

                printf("Insert after value : ");
                scanf("%d",&val);

                myObj.insertAfter(data,val);
                break;

            case 4:
                myObj.deleteFirst();
                break;

            case 5:
                myObj.deleteLast();
                break;

            case 6:
                printf("data : ");
                scanf("%d",&data);
                myObj.deleteNode(data);
                break;

            case 7:
                printf("Data : ");
                scanf("%d",&data);
                printf("%d",myObj.Search(data));
                printf("\n");
                break;

            case 8:
                myObj.display();
                break;

            case 9:
                printf("%d",myObj.totalNodes());
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

