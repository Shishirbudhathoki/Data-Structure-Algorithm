#include<stdio.h>
void bubble_sort (int arr[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main()
{
    int arr[] = {7,111,6,15,7,27,2,13};
    int i,n = sizeof(arr) / sizeof(arr[0]);    
    printf("The size of array is : %d\n",n);
    printf("Sorted array: ");
    bubble_sort(arr,n);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}