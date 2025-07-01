def GCD(a,b):
    if (b == 0):
        return a
    else:
        return GCD(b,a%b)

a,b= map(int,input("Enter the value of two number :").split())
print(f"The GCD of {a} and {b} is : {GCD(a, b)}")
