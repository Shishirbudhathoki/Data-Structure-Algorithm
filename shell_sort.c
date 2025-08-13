/* Shell Sort is an improved version of Insertion Sort tthat allows the exchange of items that are far apart. 
When gap = 1, the array is sorted using normal insertion sort,but it's already almost sorted, so it's fast. */

#include<stdio.h>
void shell_sort (int arr[],int n){
    for(int gap=n/2;gap>0;gap/=2)
    {
        for(int i=gap;i<n;i++)
        {
            int temp=arr[i];
            int j;
            for(j=i; j>=gap && arr[j-gap]>temp;j-=gap)
                arr[j]=arr[j-gap];
            arr[j]=temp;
        }
    }
}
int main()
{
    int arr[] = {15,17,7,2,1,7,3,11};   
    int i,n = sizeof(arr) / sizeof(arr[0]);    
    printf("The size of array is : %d\n",n);
    printf("Sorted array: ");
    shell_sort(arr,n);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}