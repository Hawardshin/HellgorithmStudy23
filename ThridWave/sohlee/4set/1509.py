import sys
sys.setrecursionlimit(10**6)
tmp=str(input())
li='a'+tmp
n=len(tmp)
dp=[[0]*(n+1) for i in range(n+1)]
final=[1e9]*(n+1)
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
final[0]=0
final[1]=1
for i in range(1,n+1):
    for j in range(1,i):
        if dp[j][i]==1: #펠린드롭일때
            final[i]=min(final[i],final[j-1]+1)
        else:
            final[i]=min(final[i],final[i-1]+1)
print(final[-1])
