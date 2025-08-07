#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int linear_search(int arr[], int n, int key)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == key)
            return i;
    }
    return -1;
}
int main()
{
    int arr[1000],n,i,key;
    printf("Enter the number of elements you want to generate: \n");
    scanf("%d", &n);
    srand(time(NULL));
    printf("Generated elements: ");
    for(i = 0; i < n; i++)
    {
        arr[i] = rand() % 100; 
        printf("%d ", arr[i]);
    }
    printf("\nEnter the element to search: ");
    scanf("%d", &key);
    int result = linear_search(arr, n, key);
    if(result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found in the array.\n");
    return 0;
}