import sys

n = int(sys.stdin.readline())
space = n*2 - 2
star = 1

for i in range(n):
    spaceList = [' ' for j in range(space)]
    starList = ['*' for j in range(star)]
    for j in range(len(starList)): print(starList[j], end='')
    for j in range(len(spaceList)): print(spaceList[j], end = '')
    for j in range(len(starList)): print(starList[j], end = '')
    print()
    space -= 2
    star += 1

space += 2
star -= 1

for i in range(n-1):
    space += 2
    star -= 1
    spaceList = [' ' for j in range(space)]
    starList = ['*' for j in range(star)]
    for j in range(len(starList)): print(starList[j], end='')
    for j in range(len(spaceList)): print(spaceList[j], end = '')
    for j in range(len(starList)): print(starList[j], end = '')
    print()
