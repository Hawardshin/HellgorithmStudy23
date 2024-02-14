import sys
n=int(sys.stdin.readline())
dp=[[0]*(21) for i in range(n)]
li=list(map(int,sys.stdin.readline().split()))
dp[0][li[0]]=1

for i in range(1,n-1):
    for j in range(21):
        if dp[i-1][j]:
            if j+li[i]<=20:
                dp[i][j+li[i]]+=dp[i-1][j]
            if j-li[i]>=0:
                dp[i][j-li[i]]+=dp[i-1][j]
print(dp[n-2][li[n-1]])
