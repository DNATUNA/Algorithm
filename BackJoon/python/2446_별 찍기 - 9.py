import sys

n = int(sys.stdin.readline())
space = 0
star = (n-1) * 2 + 1

for i in range(n):
    spaceList = [' ' for j in range(space)]
    starList = ['*' for j in range(star)]
    for j in range(len(spaceList)): print(spaceList[j], end = '')
    for j in range(len(starList)): print(starList[j], end = '')
    print()
    space += 1
    star -= 2

space -= 1
star += 2

for i in range(n-1):
    space -= 1
    star += 2
    spaceList = [' ' for j in range(space)]
    starList = ['*' for j in range(star)]
    for j in range(len(spaceList)): print(spaceList[j], end = '')
    for j in range(len(starList)): print(starList[j], end = '')
    print()
