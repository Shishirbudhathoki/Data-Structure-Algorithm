
#include <stdio.h>

long int tailSum(int n, long int a)
{
    if (n == 0)
        return a;
    else
        return tailSum(n - 1, a + n);
}
int main()
{
    int n;
    printf("Enter value of  n : \n");
    scanf("%d", &n);
    printf("The sum of %d natural number using tail recursion is  %ld.",n, tailSum(n, 0));
    return 0;
}