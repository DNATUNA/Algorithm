import sys

n = int(sys.stdin.readline())
space = n - 1
starList = [[' ']*(n*2) for i in range(n*2)]

starList[0][0] = '*'
starList[1][0] = '*'
starList[1][2] = '*'
starList[2][0] = '*'
starList[2][1] = '*'
starList[2][2] = '*'
starList[2][3] = '*'
starList[2][4] = '*'

count = 3
listLen = 1
spaceLen = count*2-1

while(count!=n):
    for i in range(count):
        for j in range(listLen):
            starList[count + i][j]=starList[i][j]
        listLen += 2
    listLen = 1
    for i in range(count):
        for k in range(spaceLen): starList[count + i][k + listLen] = ' '
        for j in range(listLen):
            starList[count + i][spaceLen + j + listLen] = starList[i][j]
        listLen += 2
        spaceLen -= 2
    count *= 2
    spaceLen = count*2-1

count = 1

for i in range(n):
    print(' '*space, end='')
    print(''.join(starList[i][:count]), end='')
    print(' '*space)
    space -= 1
    count += 2
