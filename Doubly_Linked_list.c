#include <stdio.h>
#include <stdlib.h>
struct DLL
{
    int data;
    struct DLL *prev;
    struct DLL *next;
};
struct DLL *First, *Last = NULL;
void display()
{
    struct DLL *temp;
    if (First == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = First;
        while (temp != NULL)
        {
            printf("%d <-> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
void insert_at_beginning(int element)
{
    struct DLL *NewNode;
    NewNode = (struct DLL *)malloc(sizeof(struct DLL));

    NewNode->data = element;
    NewNode->prev = NULL;
    NewNode->next = NULL;

    if (First == NULL)
    {
        First = Last = NewNode;
    }
    else
    {
        NewNode->next = First;
        First->prev = NewNode;
        First = NewNode;
    }
    printf("%d was inserted at beginning.\n", First->data);
}
void insert_at_end(int element)
{
    struct DLL *NewNode;
    NewNode = (struct DLL *)malloc(sizeof(struct DLL));

    NewNode->data = element;
    NewNode->prev = NULL;
    NewNode->next = NULL;

    if (First == NULL)
    {
        First = Last = NewNode;
    }
    else
    {
        NewNode->prev = Last;
        Last->next = NewNode;
        Last = NewNode;
    }
    printf("%d was inserted at end.\n", Last->data);
}
void insert_at_specificPosition(int element, int POS)
{
    struct DLL *NewNode, *temp, *tempp;
    NewNode = (struct DLL *)malloc(sizeof(struct DLL));

    NewNode->data = element;
    NewNode->prev = NULL;
    NewNode->next = NULL;

    if (First == NULL && POS == 1)
    {
        insert_at_beginning(element);
    }
    else if (POS < 1)
    {
        printf("Invalid position.\n");
        free(NewNode);
    }
    else
    {
        temp = First;
        for (int i = 1; (i < POS - 1) && (temp != NULL); i++)
        {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Invalid position: %d cannot be inserted at position %d.\n", NewNode->data, POS);
            free(NewNode);
            return;
        }
        if (temp == Last)
        {
            insert_at_end(element);
        }
        else
        {
            tempp = temp->next;
            NewNode->next = tempp;
            NewNode->prev = temp;
            tempp->prev = NewNode;
            temp->next = NewNode;
            printf("%d was inserted at position %d.\n", NewNode->data, POS);
        }
    }
}
void delete_at_beginning(){

    struct DLL *temp;


    if (First == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    else if (First->next == NULL)
    {
        temp = First;
        First = Last = NULL;
        free(temp);
    }
    else
    {
        temp = First;
        First = First->next;
        First->prev = NULL;
        free(temp);
    }
    printf("Data was deleted from beginning.\n");
}


void delete_at_end(){

    struct DLL *temp;

    if (First == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    else if (First->next == NULL)
    {
        temp = First;
        First = Last = NULL;
        free(temp);
    }
    else
    {
        temp = Last;
        Last = Last->prev;
        Last->next = NULL;
        free(temp);
    }
    printf("Data was deleted from end.\n");
}
void delete_at_specificPosition(int POS)
{
    struct DLL *temp, *tempp;
    if (First == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    else if (POS < 1)
    {
        printf("Invalid position.\n");
        return;
    }
    else if (POS == 1)
    {
        delete_at_beginning();
    }
    else
    {
        temp = First;
        for (int i = 1; (i < POS-1) && (temp->next != NULL); i++)
        
        {
            temp = temp->next;
        }
        if (temp->next == NULL) {
            printf("Data cannot be deleted : Position %d out of bounds.\n",POS);
            return;
        }
        if (temp->next == Last)
        {
            delete_at_end();
        }
        else
        {
            tempp = temp->next;
            temp->next = tempp->next;
            tempp->next->prev = temp;
            free(tempp);
            printf("Data was deleted from position %d.\n", POS);
        }
    }
}

int main()
{
    insert_at_beginning(10);
    display();
    insert_at_end(20);
    display();
    insert_at_specificPosition(15, 2);
    display();
    insert_at_specificPosition(15, 12);
    display();
    delete_at_beginning();
    display();
    delete_at_end();
    display();
    delete_at_specificPosition(7);
    display();
    return 0;
}