import sys
n=int(sys.stdin.readline())
li=[]
for i in range(n):
    tmp=list(map(int,sys.stdin.readline().split()))
    li.append(tmp)

dp=[[0]*(n+1) for i in range(n+1)]
dp[0][0]=1
for i in range(n):
    for j in range(n):
        if i==n-1 and j==n-1:
            break
        newx=i+li[i][j]
        newy=j+li[i][j]
        if 0<=newx<n:
            dp[newx][j]+=dp[i][j]
        if 0<=newy<n:
            dp[i][newy]+=dp[i][j]
print(dp[n-1][n-1])