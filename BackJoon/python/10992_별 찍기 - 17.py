import sys

n = int(sys.stdin.readline())
stack = n
space = 1
if(n==1):print('*')
else:
    print(' ' * (stack-1)+'*')
    stack -= 2
    while(stack!=0):
        print(' '*(stack)+'*'+' '*(space)+'*')
        stack -= 1
        space += 2
    print('*'*(space+2))
