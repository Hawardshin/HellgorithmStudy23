import sys
n,m = map(int, sys.stdin.readline().split())
li = []
dp = [[0] * (n + 1) for i in range(n + 1)]
for i in range(n):
    tmp = list(map(int, sys.stdin.readline().split()))
    li.append(tmp)
for i in range(n):
    for j in range(n):
        dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] - dp[i][j] + li[i][j]
        #dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + li[i][j]
for j in range(m):
    x1,y1,x2,y2 = map(int, sys.stdin.readline().split())
    print(dp[x2][y2] - dp[x1-1][y2] - dp[x2][y1-1] + dp[x1-1][y1-1])
