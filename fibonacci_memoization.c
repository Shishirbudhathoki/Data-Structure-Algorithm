#include<stdio.h>
long int table[100]= {0};
long int Fibonacci(int n){
    if(n==1 || n==2){
        return 1;
    }
    else{
        if(table[n]==0){
            table[n]=Fibonacci(n-1)+Fibonacci(n-2);
        }
        return table[n];
    }
}
int main(){
    int n;
    printf("Enter the value of n:\n");
    scanf("%d",&n);;
    printf("The %dth Fibonacci number is %ld\n",n,Fibonacci(n));
    return 0;
}