// For index 0
#include<stdio.h>
#include<conio.h>
void heap_sort(int arr[],int n);
void build_max_heap(int arr[],int n);
void max_heaping(int arr[],int i ,int n){
    
    int l=2*i+1,r=2*i+2,largest=i,temp;
    if(l<n && arr[l]>arr[largest])
        largest=l;
    if(r<n && arr[r]>arr[largest])
        largest=r;
    if(i!=largest)
    {
        temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        max_heaping(arr,largest,n);
    }
}
void build_max_heap(int arr[],int n)
{
    int i;
    for(i=n/2-1;i>=0;i--)
        max_heaping(arr,i,n);
}
void heap_sort(int arr[],int n)
{
    int i,temp;
    build_max_heap(arr,n);
    for(i=n-1;i>=1;i--)
    {
        temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        n=n-1;
        max_heaping(arr,0,n);     
    }
}
int main()
{
    int arr[] = {11,17,19,100,99,27,7,3,13};
    int i,n = sizeof(arr) / sizeof(arr[0]);    
    printf("The size of array is : %d\n",n);
    heap_sort(arr,n);
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}