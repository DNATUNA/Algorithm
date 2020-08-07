import sys

n = int(sys.stdin.readline())
starList = [[' ']*6600 for i in range(6600)]
check = 1
count = check
starList[0][0] = '*'
while(check != n):
    for i in range(2):
        for j in range(check):
            for k in range(check):
                starList[count+j][k] = starList[j][k]
        count += check
    count = check
    for j in range(check):
        for k in range(check):
            starList[j][check+k] = starList[j][k]
    for j in range(check):
        for k in range(check):
            starList[count+count+j][check+k] = starList[j][k]
    count = 0
    for i in range(3):
        for j in range(check):
            for k in range(check):
                starList[count+j][check + check + k] = starList[j][k]
        count += check
    check *= 3

for i in range(n):
    for j in range(n):
        print(starList[i][j], end='')
    print()
