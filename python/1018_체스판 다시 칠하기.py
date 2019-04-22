import sys

check = ['W', 'B']

y, x = map(int, sys.stdin.readline().split())
board = [[] * x] * y
xCheck, yCheck = 0, 0
minCount, countCheck = 99999999999999999999, 0

for i in range(y): board[i] = list(sys.stdin.readline().split())

while((x - xCheck >= 7) & (y - yCheck >= 7)):
    if (board[yCheck][xCheck] == check[1]):
        num = 0
        for i in range(7):
            for j in range(7):
                num ^= 1
                if (board[i + yCheck][j + xCheck] != check[num]): countCheck += 1
    else:
        num = 1
        for i in range(7):
            for j in range(7):
                num ^= 1
                if (board[i + yCheck][j + xCheck] != check[num]): countCheck += 1

    minCount = min(minCount, countCheck)
    xCheck += 1
    yCheck += 1

print(minCount)
