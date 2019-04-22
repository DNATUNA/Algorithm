import sys

n = sys.stdin.readline()

min_x = 99999999999999
min_y = 99999999999999
min_num = min_x + min_y

for i in n:
    a, b = map(int, sys.stdin.readline().split())
    if(min_num > abs(a-b)): min_num = abs(a-b)

print(min_num)
