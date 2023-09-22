import sys
n,k=map(int,sys.stdin.readline().split())
li=[[0,0]]
for i in range(n):
    w,v=map(int,sys.stdin.readline().split())
    li.append([w,v])
li.sort(key=lambda x:x[0])
dp=[[0]*(k+1) for i in range(n+1)]

for i in range(1,n+1):
    for j in range(k+1):
        if j-li[i][0]>=0:
            dp[i][j]=max(dp[i-1][j-li[i][0]]+li[i][1],dp[i-1][j])
        else:
            dp[i][j]=dp[i-1][j]
print(dp[n][-1])
