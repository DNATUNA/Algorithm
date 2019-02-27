import sys

E, S, M = map(int, sys.stdin.readline().split())
a, b ,c = 1, 1, 1
for i in range(1, 7981):
    if((a==E)&(b==S)&(c==M)):
        print(i)
        break
    a += 1
    b += 1
    c += 1
    if(a>15):a=1
    if(b>28):b=1
    if(c>19):c=1