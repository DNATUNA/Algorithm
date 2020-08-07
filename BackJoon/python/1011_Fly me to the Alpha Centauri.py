import sys

n = int(sys.stdin.readline())

for i in range(n):
    a, b = map(int, sys.stdin.readline().split())
    len = b-a
    checkNum = 2
    checkSum = 2
    sum = 0

    while(len > checkSum):
        sum += checkNum
        checkNum += 2
        checkSum += checkNum

    if(len-sum>checkNum/2): print(checkNum)
    else: print(checkNum-1)
