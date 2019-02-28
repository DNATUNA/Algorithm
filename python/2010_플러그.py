import sys

N = int(sys.stdin.readline())
list_a = [sys.stdin.readline() for i in range(N)]

print((sum(map(int, list_a)))-N+1)