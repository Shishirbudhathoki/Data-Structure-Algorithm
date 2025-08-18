// How can you solve polynomial equations using linked list.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    float coeff;
    int expo;
    struct node *link;
};
struct node *head = NULL;
void insert( float co, int ex)
{
    struct node *temp ;
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode->coeff = co;
    newNode->expo = ex;
    newNode->link = NULL;

    if (head == NULL || ex > head->expo)
    {
        newNode->link = head;
        head = newNode;
    }
    else if (head->expo == ex)  
    {
        head->coeff += co;
        free(newNode);
    }
    else
    {
        temp = head;
        while (temp->link != NULL && temp->link->expo > ex)
        {
            temp = temp->link;
        }
        if (temp->link != NULL && temp->link->expo == ex) {
            temp->link->coeff += co;
            free(newNode);
        }

        else
        {
            newNode->link = temp->link;
            temp->link = newNode;
        }
    }
}

void create()
{
    int n, expo;
    float coeff;
    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("Enter coefficient for term %d: ", i);
        scanf("%f", &coeff);
        printf("Enter exponent for term %d: ", i);
        scanf("%d", &expo);
        insert(coeff, expo);
    }

}

void display()
{
    if (head == NULL)
    {
        printf("No Polynomial.\n");
    }
    else
    {
        struct node* temp = head;
        while (temp != NULL)
        {
            printf("(%.1f)x^%d", temp->coeff, temp->expo);
            temp = temp->link;
            if (temp != NULL)
            {
                printf(" + ");
            }
        }
        printf("\n");
    }
}


float evaluate(float x)
{
    float result = 0.0;
    struct node *temp = head;
    while (temp != NULL)
    {
        result += temp->coeff * pow(x, temp->expo);
        temp = temp->link;
    }
    return result;
}


int main()
{

    float x, result;

    printf("Enter the polynomial:\n");
    create();

    printf("The polynomial is: ");
    display();

    printf("Enter the value of x to evaluate: ");
    scanf("%f", &x);

    result = evaluate(x);
    printf("Result of polynomial when x = %.2f is: %.2f\n", x, result);

    return 0;
}