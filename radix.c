#include<stdio.h>
void radix_sort (int arr[],int n);
int getMax(int arr[],int n)
{
    int max=arr[0];
    for(int i=1;i<n;i++)
        if(arr[i]>max)
            max=arr[i];
    return max;
}
void counting_sort(int arr[],int n,int pos)
{
    int output[n];
    int i,count[10]={0};

    for(i=0;i<n;i++)
        count[(arr[i]/pos)%10]++;
    
    for(int i=1;i<10;i++)
        count[i]+=count[i-1];

    // For descending order, we modify the counting array   
    // for(int i=8;i>=0;i--)
    //     count[i]+=count[i+1];
    
    for(int i = n-1;i>=0;i--)
    {
        int digit = (arr[i]/pos)%10;
        output[--count[digit]]=arr[i];
    }

    for(int i=0;i<n;i++){
        arr[i]=output[i];
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void radix_sort (int arr[],int n){
    int max = getMax(arr,n);
    
    for(int pos=1;max/pos>0;pos*=10){
        counting_sort(arr,n,pos);
    }
} 
int main()
{
    int arr[] = {141,456,342,789,90,2,870,192,938,243};//{15,17,7,2,1,7,3,11};   
    int i,n = sizeof(arr) / sizeof(arr[0]);    
    printf("The size of array is : %d\n",n);
    printf("Sorted array: ");
    radix_sort(arr,n);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}