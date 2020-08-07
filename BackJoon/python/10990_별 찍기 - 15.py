import sys

n = int(sys.stdin.readline())
stack = n
space = 1
if(n==1):print('*')
else:
    print(' ' * (stack-1)+'*')
    stack -= 1
    while(stack!=0):
        print(' '*(stack-1)+'*'+' '*(space)+'*')
        stack -= 1
        space += 2