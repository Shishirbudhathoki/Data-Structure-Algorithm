#include<stdio.h>
void merge(int [],int, int ,int);
void merge_sort(int arr[],int l,int r){
    if(l<r){
        int m;
        m = (l+r)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merge(arr,l,m+1,r);
    }
}
void merge(int arr[],int l,int m ,int r){
    int i,j,k,brr[100];
    i=l;
    j=m;
    k=l;
    while(i<m && j<=r)
    {
        if(arr[i]<arr[j])
            brr[k++]=arr[i++];
        else
            brr[k++]=arr[j++];
    }
    for( ;i<m;i++,k++)
        brr[k]=arr[i];
    for( ;j<=r;j++,k++)
        brr[k]=arr[j];
    for(k=l;k<=r;k++)
        arr[k]=brr[k];
}
int main()
{
    int arr[] = {11,17,1,13,19,3,21};
    int i,n = sizeof(arr) / sizeof(arr[0]);    
    printf("The size of array is : %d\n",n);
    printf("Sorted array: ");
    merge_sort(arr,0,n-1);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}