def tailFact(n,a): 
    if (n == 1):
        return a
    else:
        return tailFact(n - 1, a * n)

n = int(input("Enter value of n:"))
print(f"factorial of {n} using tail recursion is : {tailFact(n,1)}")