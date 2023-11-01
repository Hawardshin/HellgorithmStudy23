import sys
n=int(sys.stdin.readline())

dp=[-1]*(n+1)
if n<5:
    if n==2:
        print(1)
    elif n==4:
        print(2)
    elif n==5:
        print(1)
    else:
        print(-1)
else:
    dp[2]=1
    dp[5]=1
    dp[4]=2
    for i in range(5,n+1):
        if dp[i-5]!=-1 and dp[i-2]!=-1:
            dp[i]=min(dp[i-5],dp[i-2])+1
        elif dp[i-5]!=-1:
            dp[i]=dp[i-5]+1
        elif dp[i-2]!=-1:
            dp[i]=dp[i-2]+1
    print(dp[n])