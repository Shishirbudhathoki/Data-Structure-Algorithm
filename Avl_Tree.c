#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *Left;
    struct Node *Right;
    struct Node *Parent;
    int height;
};

struct Node *createNode(struct Node *root, int data)
{
    struct Node *NewNode = (struct Node *)malloc(sizeof(struct Node));
    NewNode->data = data;
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->Parent = root;
    NewNode->height = 0;
    return NewNode;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getHeight(struct Node *n)
{
    if (n == NULL)
        return -1;
    return n->height;
}

int getBalanceFactor(struct Node *n)
{
    if (n == NULL)
        return 0;
    return getHeight(n->Left) - getHeight(n->Right);
}

struct Node *LeftRotate(struct Node *x)
{
    struct Node *y = x->Right;
    struct Node *T2 = y->Left;

    y->Left = x;
    x->Right = T2;

    y->Parent = x->Parent;
    x->Parent = y;
    if (T2)
        T2->Parent = x;

    x->height = max(getHeight(x->Left), getHeight(x->Right)) + 1;
    y->height = max(getHeight(y->Left), getHeight(y->Right)) + 1;

    return y;
}

struct Node *RightRotate(struct Node *y)
{
    struct Node *x = y->Left;
    struct Node *T2 = x->Right;

    x->Right = y;
    y->Left = T2;

    x->Parent = y->Parent;
    y->Parent = x;
    if (T2)
        T2->Parent = y;

    y->height = max(getHeight(y->Left), getHeight(y->Right)) + 1;
    x->height = max(getHeight(x->Left), getHeight(x->Right)) + 1;

    return x;
}

struct Node *RightLeft(struct Node *root)
{
    root->Right = RightRotate(root->Right);
    return LeftRotate(root);
}

struct Node *LeftRight(struct Node *root)
{
    root->Left = LeftRotate(root->Left);
    return RightRotate(root);
}

struct Node *rebalance(struct Node *root, int value)
{
    int bf = getBalanceFactor(root);

    if (bf > 1 && value <= root->Left->data) // Left Left Case
    {
        printf("\nFor node-%d,bf: %d\n", root->data, bf);
        printf("Left Left rotation for node: %d\n", value);
        return RightRotate(root);
    }
    else if (bf < -1 && value > root->Right->data) // Right Right Case
    {
        printf("\nFor node-%d,bf: %d\n", root->data, bf);
        printf("Right Right rotation for node: %d\n", value);
        return LeftRotate(root);
    }
    else if (bf > 1 && value > root->Left->data) // Left Right Case
    {
        printf("\nFor node-%d,bf: %d\n", root->data, bf);
        printf("Left Right rotation for node: %d\n", value);
        return LeftRight(root);
    }
    else if (bf < -1 && value < root->Right->data) // Right Left Case
    {
        printf("\nFor node-%d,bf: %d\n", root->data, bf);
        printf("Right Left rotation for node: %d\n", value);
        return RightLeft(root);
    }

    return root;
}
struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
        return createNode(NULL, value);
    else if (value <= root->data)
    {
        root->Left = insert(root->Left, value);
    }
    else
    {
        root->Right = insert(root->Right, value);
    }

    root->height = max(getHeight(root->Left), getHeight(root->Right)) + 1;
    return rebalance(root, value);
}
struct Node *findMin(struct Node *root)
{
    if (root == NULL)
        return NULL;
    while (root->Left != NULL)
        root = root->Left;
    return root;
}

struct Node *deleteNode(struct Node *root, int value)
{
    if (root == NULL)
        return NULL;

    if (value < root->data)
    {
        root->Left = deleteNode(root->Left, value);
    }
    else if (value > root->data)
    {
        root->Right = deleteNode(root->Right, value);
    }
    else
    {
        if (root->Left == NULL)
        {
            struct Node *temp = root->Right;
            free(root);
            return temp;
        }
        else if (root->Right == NULL)
        {
            struct Node *temp = root->Left;
            free(root);
            return temp;
        }
        else
        {
            struct Node *temp = findMin(root->Right);
            root->data = temp->data;
            root->Right = deleteNode(root->Right, temp->data);
        }
    }

    root->height = max(getHeight(root->Left), getHeight(root->Right)) + 1;
    return rebalance(root, value);
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d, ", root->data);
        preorder(root->Left);
        preorder(root->Right);
    }
}
void freeTree(struct Node *root)
{
    if (root != NULL)
    {
        freeTree(root->Left);
        freeTree(root->Right);
        free(root);
    }
}

int main()
{
    struct Node *root = NULL;
    int choice, element, arr[] = {10, 9, 8, 4, 5, 7, 32, 16, 11, 1, 12, 2};
    do
    {
        printf("\n1.Insert\n2.Preorder\n3.Create\n4.Empty\n5.Delete\n6.Exit\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &element);
            root = insert(root, element);
            printf("\n%d is inserted.\n", element);
            break;
        case 2:
            if (root == NULL)
                printf("\nTree is empty.\n");
            else
            {
                printf("\nThe preorder traversal is : ");
                preorder(root);
                printf("\n");
            }
            break;
        case 3:
            for (int i = 0; i < 12; i++)
                root = insert(root, arr[i]);
            printf("All elements inserted.\n");
            break;
        case 4:
            if (root != NULL)
            {
                freeTree(root);
                root = NULL;
                printf("Tree is empty now.\n");
            }
            else
                printf("Tree is already empty.\n");
            break;
        case 5:
            printf("Enter the element to delete: ");
            scanf("%d", &element);
            if (root == NULL)
            {
                printf("Tree is empty.\n");
            }
            else
            {
                root = deleteNode(root, element);
                printf("%d is deleted .\n", element);
            }
            break;
        case 6:
            printf("Bye!!!\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    } while (choice != 6);
    return 0;
}