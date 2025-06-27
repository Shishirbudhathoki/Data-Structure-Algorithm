#include <stdio.h>
#include <stdlib.h>
struct SLL
{
    int data;
    struct SLL *next;
};
struct SLL *First, *Last = NULL;
void display()
{
    struct SLL *temp;
    if (First == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = First;
        while (temp != NULL)
        {
            printf("%d ->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
void insert_at_beginning(int element)
{
    struct SLL *NewNode;
    NewNode = (struct SLL *)malloc(sizeof(struct SLL));

    NewNode->data = element;
    NewNode->next = NULL;

    if (First == NULL)
    {
        First = Last = NewNode;
    }
    else
    {
        NewNode->next = First;
        First = NewNode;
    }
    printf("%d was inserted at beginning.\n", First->data);
}
void insert_at_end(int element)
{
    struct SLL *NewNode;
    NewNode = (struct SLL *)malloc(sizeof(struct SLL));

    NewNode->data = element;
    NewNode->next = NULL;

    if (First == NULL)
    {
        First = Last = NewNode;
    }
    else
    {
        Last->next = NewNode;
        Last = NewNode;
    }
    printf("%d was inserted at end.\n", Last->data);
}
void insert_at_specificPosition(int element, int POS)
{
    struct SLL *NewNode, *temp;
    NewNode = (struct SLL *)malloc(sizeof(struct SLL));

    NewNode->data = element;
    NewNode->next = NULL;

    int i;
    if (POS <= 0)
    {
        printf("Invalid Position.\n");
    }
    else if (POS == 1)
    {
        insert_at_beginning(element);
    }
    else
    {
        temp = First;
        for (i = 1; i < (POS - 1) && (temp != NULL); i++)
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
            NewNode->next = temp->next;
            temp->next = NewNode;
        }
    }
    printf("%d was inserted at position %d.\n", NewNode->data, POS);
    
}
void delete_at_beginning()
{
    struct SLL *temp;
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
        First = temp->next;
        free(temp);
    }
    printf("Data was deleted from beginning.\n");
}
void delete_at_end()
{
    struct SLL *temp;
    if (First == NULL)
    {
        printf("List is empty.\n");
    }
    else if (First->next == NULL)
    {
        temp = Last;
        First = Last = NULL;
        free(temp);
    }
    else
    {
        temp = First;
        while (temp->next != Last)
        {
            temp = temp->next;
        }
        Last = temp;
        temp = temp->next;
        free(temp);
        Last->next = NULL;
    }
    printf("Data was deleted from end.\n");
}
void delete_at_specificPosition(int POS)
{
    struct SLL *temp,*tempp;
    int i;
    if (POS <= 0)
    {
        printf("Invalid Deletion.\n");
    }
    else if (First == NULL)
    {
        printf("List is empty.\n");
    }
    else if (POS == 1)
    {
        delete_at_beginning();
    }
    else
    {
        temp = First;
        for (i = 1; (i < POS - 1) && (temp->next != NULL);i++)
        {
            temp=temp->next;
        }
        if (temp->next == NULL) {
            printf("Data cannot be deleted : Position %d out of bounds.\n",POS);
            return;
        }
        if(temp ->next == Last){
            delete_at_end();
        }
        else{
            tempp = temp->next;
            temp->next = tempp->next;
            free(tempp);
        }
    }
    printf("Data was deleted from the %d position.\n",POS);
}
int main()
{
    insert_at_beginning(3);
    display();
    insert_at_end(5);
    display();
    insert_at_beginning(4);
    display();
    insert_at_specificPosition(1, 2);
    display();
    insert_at_specificPosition(9, 4);
    display();
    insert_at_specificPosition(6, 9);
    display();
    delete_at_beginning();
    display();
    delete_at_end();
    display();
    delete_at_specificPosition(2);
    display();
    delete_at_specificPosition(5);
    display();
    insert_at_specificPosition(7, 3);
    display();

    return 0;
}