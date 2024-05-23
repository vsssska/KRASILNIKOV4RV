
# Online Python - IDE, Editor, Compiler, Interpreter

def fun1(n):
    return n/((1 + (2 * n))*(1 + (2 * n))*(1 + (2 * n)))
    
def fun2(a, b):
    return (a + b)
    
def fun3(a, b):
    if a == b:
        return fun1(a)
    return fun2(fun1(a), fun3(a+1, b))

def fun4():
    a = 1
    b = 5
    return fun3(a, b)
    
print(f'Sum is {fun4()}')