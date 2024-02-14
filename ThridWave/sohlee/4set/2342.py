import sys
li=list(map(int,sys.stdin.readline().split()))
li.pop()

def get_move(k,i):
    if k==0:
        if i==0:
            return 0
        else:
            return 2
    elif k==i:#안움직이고 제자리밟기
        return 1
    elif abs(k-i)==1 or abs(k-i)==3:
        return 3
    else:
        return 4

n=len(li)
if len(li)==0:
    print(0)
else:
    dp=[[[1e9 for i in range(5)] for j in range(5)] for k in range(n+1)]
    dp[-1][0][0]=0
    for i in range(len(li)):
        for j in range(5):
            for k in range(5):
                move=get_move(k,li[i])
                dp[i][li[i]][j]=min(dp[i][li[i]][j],dp[i-1][k][j]+move)
        for j in range(5):
            for k in range(5):
                move=get_move(k,li[i])
                dp[i][j][li[i]]=min(dp[i][j][li[i]],dp[i-1][j][k]+move)
min_dp=min(dp[n-1])
print(min(min_dp))
