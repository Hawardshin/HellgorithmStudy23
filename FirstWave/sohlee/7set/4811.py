import sys
n=int(sys.stdin.readline())
li=[]
dp=[[0]*(31) for i in range(31)]
for i in range(1,31): #i가 H 
    for j in range(1,31): #j가 W 
        if i==1:
            dp[i][j]=1
        elif i>j:#H가 W보다 많으면 갱신 안함
            dp[i][j]=dp[i-1][j]
        else:
            dp[i][j]=dp[i-1][j]+dp[i][j-1]
print(dp[n][n])

while n!=0:
    n=int(sys.stdin.readline())
    if n!=0:
        print(dp[n][n])
