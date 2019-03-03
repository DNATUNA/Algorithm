import sys

n = int(sys.stdin.readline())
star = 1

for i in range(n):
    for j in range(star): print('*', end = '')
    print()
    star += 1

star -= 1

for i in range(n-1):
    star -= 1
    for j in range(star): print('*', end='')
    print()
