#include<stdio.h>
void selection_sort (int arr[],int n){
    int least,pos,i,j,temp;
    for(i=0;i<n;i++){
        least=arr[i];
        pos=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<least){
                least=arr[j];
                pos=j;
            }
        }
        if(i!=pos){
            temp=arr[i];
            arr[i]=arr[pos];
            arr[pos]=temp;
        }
    }
}
int main()
{
    int arr[] = {15,17,7,2,1,7,3,11};
    int i,n = sizeof(arr) / sizeof(arr[0]);    
    printf("The size of array is : %d\n",n);
    printf("Sorted array: ");
    selection_sort(arr,n);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}