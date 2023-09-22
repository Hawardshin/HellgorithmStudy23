import sys
n,k=map(int,sys.stdin.readline().split())
money=[]
for i in range(n):
    money.append(int(sys.stdin.readline()))
dp=[1e9]*(k+1)
dp[0]=0
for i in money:
    for j in range(1,k+1):
        if j-i>=0:
            dp[j]=min(dp[j],dp[j-i]+1)
if dp[-1]==1e9:
    print(-1)
else:
    print(dp[-1])
