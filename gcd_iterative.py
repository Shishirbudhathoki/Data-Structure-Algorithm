# Greatest Common Divisor
def GCD(a, b):
    if (b == 0):
        return a
    else:
        while (b != 0):
            r = a % b
            a = b
            b = r
        return a
a,b= map(int,input("Enter the value of two number :").split())
print(f"The GCD of {a} and {b} is : {GCD(a, b)}")