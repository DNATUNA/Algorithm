import sys

n = int(sys.stdin.readline())
firstSpace = n-1
stack = 1

if(n==1):print('*')
else:
    print(' ' * (firstSpace)+'*')
    firstSpace -= 1
    while(firstSpace>=0):
        print(' '*(firstSpace)+'*', end='')
        print(' *'*stack)
        firstSpace -= 1
        stack += 1