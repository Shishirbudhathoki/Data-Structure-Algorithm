#include<stdio.h>
int partition(int [],int,int);
void quick_sort(int arr[],int l,int r){
    if(l<r){
        int p;
        p = partition(arr,l,r);
        quick_sort(arr,l,p-1);
        quick_sort(arr,p+1,r);
    }
}
int partition(int arr[],int l ,int r){
    int x,y,pivot,temp;
    x=l;
    y=r;
    pivot=arr[l];
    while(x<y)
    {
        while(arr[x]<=pivot && x<=r)
            x++;
        while(arr[y]>pivot && y>=l)
            y--;
        if(x<y){
            temp=arr[x];
            arr[x]=arr[y];
            arr[y]=temp;
        }
    }
    temp=arr[l];
    arr[l]=arr[y];
    arr[y]=temp;
    return y;
}
int main()
{
    int arr[] = {11,17,9,5,19,3,15,16};
    int i,n = sizeof(arr) / sizeof(arr[0]);    
    printf("The size of array is : %d\n",n);
    printf("Sorted array: ");
    quick_sort(arr,0,n-1);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}