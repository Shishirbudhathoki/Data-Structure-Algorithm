#include<stdio.h>
void insertion_sort (int arr[],int n){
    int i,j,temp;
    for(i=0;i<n;i++){
        temp=arr[i];
        j=i-1;
        while(j>=0 && temp<arr[j]){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
int main()
{
    int arr[] = {15,17,7,2,1,7,3,11};
    int i,n = sizeof(arr) / sizeof(arr[0]);    
    printf("The size of array is : %d\n",n);
    printf("Sorted array: ");
    insertion_sort(arr,n);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}