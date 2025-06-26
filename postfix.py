def isIntOrFLoat(value):
    try:
        
        float(value)
        return True
    except:
        return False

def eval_postfix(expression):
    stack = []
    for e in expression:
        if isIntOrFLoat(e):
            stack.append(float(e))
        else:
            if len(stack) < 2:
                print("Error: insufficient values in expression")
                return
            op2 = stack.pop()
            op1 = stack.pop()
            if e == '+':
                result = op1 + op2
            elif e == '-':
                result = op1 - op2
            elif e == '*':
                result = op1 * op2
            elif e == '/':
                if op2 == 0:
                    print("Error: Division by zero.")
                    return
                result = op1 / op2
            elif e in ('^', '$'):
                result = op1 ** op2
            else:
                print("Unknown operator:", e)
                return
            
            stack.append(result)
    
    if len(stack) == 1:
        print("result is", stack.pop())
    else:
        print("Error: Invalid expression")


expression = input("Enter the expression each term separated by space: ")
eval_postfix(expression.split(" "))