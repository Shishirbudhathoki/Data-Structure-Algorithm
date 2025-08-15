#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binary_search(int arr[], int n, int key)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}
void insertion_sort(int arr[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && temp < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
int find_all_index(int arr[], int result, int n, int key)
{
    int found = 0;
    int b[n], j = 0;
    for (int i = result; i >= 0; i--)
    {
        if (arr[i] == key)
        {
            found++;
            b[j] = i;
            j++;
        }
        else
            break;
    }
    for (int i = result + 1; i < n; i++)
    {
        if (arr[i] == key)
        {
            found++;
            b[j] = i;
            j++;
        }
        else
            break;
    }
    insertion_sort(b, j);
    printf("All indices: ");
    for (int i = 0; i < j; i++)
        printf("%d,", b[i]);
    printf("\n");
    return found;
}
int main()
{
    int arr[500], n=0, key, choice;
    do
    {
        printf("\n1.No. generator\n2.Search Element\n3.Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number of elements you want to generate: ");
            scanf("%d", &n);
            srand(time(NULL));
            for (int i = 0; i < n; i++)
                arr[i] = rand() % 100;
            break;
        case 2:
            if (n == 0) 
            {
                printf("Error: No array generated yet. Please use option 1 first.\n");
                break;
            }
            insertion_sort(arr, n);
            printf("\nSorted array:\n");
            for (int i = 0; i < n; i++)
                printf("%d ", arr[i]);
            printf("\n");
            printf("\nEnter the element to search: ");
            scanf("%d", &key);
            int result = binary_search(arr, n, key);
            if (result != -1)
            {
                printf("Element found at index: %d\n", result);
                int result2 = find_all_index(arr, result, n, key);
                printf("Total occurrences of %d: %d\n", key, result2);
            }
            else
                printf("Element not found in the array.\n");
            break;
        case 3:
            printf("Bye!!!\n");
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    } while (choice != 3);
    return 0;
}