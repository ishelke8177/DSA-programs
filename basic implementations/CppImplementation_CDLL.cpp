#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class DCLL
{
    struct node
    {
        int item;
        node *next;
        node *prev;
    }*last;

public:
    DCLL()
    {
        last = NULL;
    }

    void insertAtFirst(int);
    void insertAtLast(int);
    void deleteFirst();
    void deleteLast();
    void display();
    void menu();
    ~DCLL()
    {
        while(last!=NULL)
            deleteFirst();
    }
};

void DCLL::insertAtFirst(int data)
{
    node *temp = new node;
    temp->next=NULL;
    temp->item=data;
    temp->prev=NULL;

    if(last==NULL)
    {
        last = temp;
        temp->next=temp;
        temp->prev=temp;
    }
    else
    {
        temp->next=last->next;
        last->next->prev=temp;
        temp->prev=last;
        last->next=temp;
    }
}

void DCLL::insertAtLast(int data)
{
    node *temp , *t;
    temp = new node;
    temp->next=NULL;
    temp->item=data;
    temp->prev=NULL;

    if(last==NULL)
    {
        last = temp;
        temp->next=temp;
        temp->prev=temp;
    }
    else
    {
        t = last->next;
        //left conn
        last->next=temp;
        temp->prev= last;
        last=temp;

        last->next=t;
        t->prev=temp;
    }
}

void DCLL::deleteFirst()
{
    node *t = last->next;

    if(last==NULL)
        printf("Underflow.....\n");
    else
    {
        t->next->prev=last;
        last->next=t->next;
        free(t);
        last=NULL;
    }
}

void DCLL::deleteLast()
{
    node *t = last;

    if(last==NULL)
        printf("Underflow......\n");
    else
    {
        if(t->prev == last->next)
        {
            free(t);
            last=NULL;
        }
        else
        {
            last=t->prev;
            last->next=t->next;
            t->next->prev=last;
            free(t);
        }
    }
}

void DCLL::display()
{
    node *t;
    if(last==NULL)
        printf("Underflow......\n");
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

void DCLL::menu()
{
    printf("\n1.insertAtStart\n2.insertAtLast\n3.deleteFirst\n4.deleteLast\n5.Display\n6.Exit\n");
}

int main()
{
    DCLL myObj;
    int index=0 , data=0 , ch=0 , val=0;

    while(1)
    {
        myObj.menu();
        printf("\nEnter : ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Data  : ");
                scanf("%d",&data);
                myObj.insertAtFirst(data);
                break;

            case 2:
                printf("Data : ");
                scanf("%d",&data);
                myObj.insertAtLast(data);
                break;

            case 3:
                myObj.deleteFirst();
                break;

            case 4:
                myObj.deleteLast();
                break;

            case 5:
                myObj.display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid\n");
            }
    }
    return 0;
}
