import sys

n = int(sys.stdin.readline())

for i in range(n):
    time, word = input().split()
    for a in word: print(a*int(time), end='')
    print()