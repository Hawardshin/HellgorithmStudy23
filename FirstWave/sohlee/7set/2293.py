import sys
n,k=map(int,sys.stdin.readline().split())
dp=[0]*(k+1)
money=[]
for i in range(n):
    money.append(int(sys.stdin.readline()))
dp[0]=1
for i in money:
    for j in range(1,k+1):
        if j-i>=0:
            dp[j]+=dp[j-i]
print(dp[-1])
