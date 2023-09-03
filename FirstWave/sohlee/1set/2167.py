import sys

N,M=map(int,sys.stdin.readline().split())
li=[]
for i in range(N):
    tmp=list(map(int,sys.stdin.readline().split()))
    li.append(tmp)
k=int(sys.stdin.readline())

dp=[[0]* (M+1) for i in range(N+1)]

for i in range(N):
    for j in range(M):
        dp[i+1][j+1]=dp[i][j+1]+dp[i+1][j]-dp[i][j]+li[i][j]

for a in range(k):
    i,j,x,y=map(int,sys.stdin.readline().split())
    print(dp[x][y] - dp[i-1][y]-dp[x][j-1]+dp[i-1][j-1])
