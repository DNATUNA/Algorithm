import sys

n, k = map(int, sys.stdin.readline().split())
ground = [[0]*n for i in range(n)]
score_a = dict(zip([i for i in range(n)], [0 for i in range(n)]))
score_b = dict(zip([i for i in range(n)], [0 for i in range(n)]))

for i in range(k):
    a, b = map(int, sys.stdin.readline().split())
    ground[a-1][b-1] = 1
    score_a[b-1] += 1
    score_b[a-1] += 1

dol, ans = 0, 0

while(dol != k):
    if(max(score_a.items(), key = lambda x: x[1])[1] >= max(score_b.items(), key = lambda x: x[1])[1]):
        a = max(score_a.items(), key=lambda x: x[1])[0]
        for i in range(n):
            if(ground[i][a] == 1):
                ground[i][a] = 0
                score_a[a] -= 1
                score_b[i] -= 1
                dol += 1

        ans += 1
    else:
        b = max(score_b.items(), key=lambda x: x[1])[0]
        for i in range(n):
            if (ground[b][i] == 1):
                ground[b][i] = 0
                score_a[i] -= 1
                score_b[b] -= 1
                dol += 1

        ans += 1

print(ans)