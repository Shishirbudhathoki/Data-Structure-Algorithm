table = [0]*100
def Fibonacci(n):
    if(n==1 or n==2):
        return 1
    else:
        if(table[n]==0):
            table[n]=Fibonacci(n-1)+Fibonacci(n-2)
        return table[n]
n= int(input("Enter the value of n: "))
print(f"The {n}th Fibonacci number is {Fibonacci(n)}")
