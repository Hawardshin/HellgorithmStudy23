import sys

N,M=map(int,sys.stdin.readline().split())
ans=0
li=list(map(int,sys.stdin.readline().split()))
dp=[0]*(N+1)
cnt=[0]*(M+1)
for i in range(N):
    dp[i+1]=(dp[i]+li[i])%M
    cnt[dp[i+1]]+=1
ans=cnt[0]
for i in cnt:
    ans+=i*(i-1)//2
print(ans)
