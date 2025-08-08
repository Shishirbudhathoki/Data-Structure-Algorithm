#include <stdio.h>
#include <stdlib.h>

struct BinaryTree
{
    int data;
    struct BinaryTree *Left;
    struct BinaryTree *Right;
    struct BinaryTree *parent;
};
struct BinaryTree *temp, *root = NULL;

struct BinaryTree *CreateNode(int value)
{
    struct BinaryTree *NewNode;
    NewNode = (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
    NewNode->data = value;
    NewNode->Left = NULL;
    NewNode->Right = NULL;
    NewNode->parent = NULL;
    return NewNode;
}

void preorder(struct BinaryTree *root)
{
    if (root != NULL)
    {
        printf("%d, ", root->data);
        preorder(root->Left);
        preorder(root->Right);
    }
}

void inorder(struct BinaryTree *root)
{
    if (root != NULL)
    {
        inorder(root->Left);
        printf("%d, ", root->data);
        inorder(root->Right);
    }
}

void postorder(struct BinaryTree *root)
{
    if (root != NULL)
    {
        postorder(root->Left);
        postorder(root->Right);
        printf("%d, ", root->data);
    }
}

struct BinaryTree *insert(struct BinaryTree *root, int value)
{
    if (root == NULL)
        root = CreateNode(value);
    else if (value < root->data)
    {
        root->Left = insert(root->Left, value);
        root->Left->parent = root;
    }
    else
    {
        root->Right = insert(root->Right, value);
        root->Right->parent = root;
    }
    return root;
}

struct BinaryTree *search(struct BinaryTree *root, int value)
{
    if (root == NULL || root->data == value)
        return root;
    else if (value < root->data)
        return search(root->Left, value);
    else
        return search(root->Right, value);
}

struct BinaryTree *findMin(struct BinaryTree *root)
{
    if (root == NULL)
    {
        printf("\nThere is no any element.So,NO min value.\n");
        return NULL;
    }
    else
    {
        while (root->Left != NULL)
            root = root->Left;
        return root;
    }
}

struct BinaryTree *findMax(struct BinaryTree *root)
{
    if (root == NULL)
    {
        printf("\nThere is no any element.So,NO max value.\n");
        return NULL;
    }
    else
    {
        while (root->Right != NULL)
            root = root->Right;
        return root;
    }
}

struct BinaryTree *deleteNode(struct BinaryTree *root, int value)
{
    if (root == NULL)
        return NULL;
    else if (value < root->data)
    {
        root->Left = deleteNode(root->Left, value);
        if (root->Left != NULL)
            root->Left->parent = root;
    }
    else if (value > root->data)
    {
        root->Right = deleteNode(root->Right, value);
        if (root->Right != NULL)
            root->Right->parent = root;
    }
    else
    {
        if (root->Left == NULL)
        {
            temp = root->Right;
            if (temp != NULL)
                temp->parent = root->parent;
            free(root);
            return temp;
        }
        else if (root->Right == NULL)
        {
            temp = root->Left;
            if (temp != NULL)
                temp->parent = root->parent;
            free(root);
            return temp;
        }
        else
        {
            temp = findMin(root->Right);
            root->data = temp->data;
            root->Right = deleteNode(root->Right, temp->data);
            if (root->Right != NULL)
                root->Right->parent = root;
        }
    }
    return root;
}
int main()
{
    int i, element, choice;
    struct BinaryTree *temp;
    // int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
   // int arr[] = {5,3,7,2,4,6,9,8,10};
    int arr[] = {7,3,5,2,4,6,9,8,10};
    do 
    {
        printf("\n1.Insert\n2.Delete\n3.Search\n4.Preorder\n5.Inorder\n6.Postorder\n");
        printf("7.Findmax\n8.Findmin\n9.Create\n10.Exit\nEnter your choice : ");
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
            printf("Enter the element to delete.\n");
            scanf("%d", &element);
            if(search(root, element) !=NULL){
                root=deleteNode(root, element);
                printf("\n%d is deleted.\n", element);
            }
            else
                printf("\n%d is not found,so no delete operation perform.\n",element);
            break;
        case 3:
            printf("Enter the element to search: ");
            scanf("%d", &element);
            temp = search(root, element);
            if (temp == NULL)
                printf("\n%d is not found in BST.\n", element);
            else
                printf("\n%d is found.\n", temp->data);
            break;
        case 4:
            if (root == NULL)
            {
                printf("\nTree is empty.\n");
            }
            else
            {
                printf("\nThe preorder traversal is : ");
                preorder(root);
                printf("\n");
            }
            break;
        case 5:
            if (root == NULL)
            {
                printf("\nTree is empty.\n");
            }
            else
            {
                printf("\nThe inorder traversal is : ");
                inorder(root);
                printf("\n");
            }
            break;
        case 6:
            if (root == NULL)
            {
                printf("\nTree is empty.\n");
            }
            else
            {
                printf("\nThe postorder traversal is : ");
                postorder(root);
                printf("\n");
            }
            break;
        case 7:
            temp = findMax(root);
            if (temp != NULL)
                printf("\n%d is the largest element in the BST.\n", temp->data);
            break;
        case 8:
            temp = findMin(root);
            if (temp != NULL)
                printf("\n%d is the smallest element in the BST.\n", temp->data);
            break;
        case 9:
            for (i = 0; i < 9; i++)
                root = insert(root, arr[i]);
            printf("All elements inserted.\n");
            break;
        case 10:
            printf("Bye!!!\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    } while (choice != 10);
    return 0;
}