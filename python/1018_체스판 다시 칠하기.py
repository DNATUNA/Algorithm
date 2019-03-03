import sys

whiteStart=["WBWBWBWB"]
blackStart=["BWBWBWBW"]

y, x = map(int, sys.stdin.readline().split())
board = [[]*x for i in range(y)]
xCheck, yCheck = 0, 0
minCount, countCheck = 99999999999999999999, 0

for i in range(y): board[i] = sys.stdin.readline()

while(y-yCheck-7 != 0):
    while(x-xCheck-7 != 0):
         if(board[yCheck][xCheck]=='W'):
