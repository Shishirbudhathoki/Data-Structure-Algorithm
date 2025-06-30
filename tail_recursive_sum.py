def tailSum(n, a):
    if (n == 0):
        return a
    else:
        return tailSum(n - 1, a + n)
n= int(input("Enter the value of n :"))
print(f"The sum of {n} natural number using tail recursion is  {tailSum(n, 0)}.")