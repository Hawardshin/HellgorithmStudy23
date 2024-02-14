import sys
n=int(sys.stdin.readline())
tmp=list(map(int,sys.stdin.readline().split()))
li=[0]+tmp

m=int(sys.stdin.readline())
dp=[[0]*(n+1) for i in range(n+1)]
for i in range(n+1):
    dp[i][i]=1
for i in range(1,n):
    start=1
    while start+i<=n:
        if i==1:#짝수개일때
            if li[start]==li[start+i]:
                dp[start][start+i]=1
        elif dp[start+1][start+i-1]==0:
                dp[start][start+i]=0
        else:
            if li[start]==li[start+i]:
                dp[start][start+i]=1
        start+=1
        
for i in range(m):
    a,b=map(int,sys.stdin.readline().split())
    print(dp[a][b])
