import sys
n,m,c=map(int,sys.stdin.readline().split())
li=list(map(int,sys.stdin.readline().split()))
dp=[[[0 for i in range(c+1)] for j in range(m+1)] for k in range(1<<14)]

def sol(jewel,index,cap):
    if jewel==((1<<n)-1):
        return 0
    if index>=m:
        return 0
    if dp[jewel][index][cap]!=0:
        return dp[jewel][index][cap]
    tmp=0
    for i in range(n):
        if (jewel & (1<<i))!=0 or li[i] > c:
            continue
        if cap>=li[i]:
            tmp=max(tmp,sol(jewel|(1<<i),index,cap-li[i])+1)
        else:
            tmp=max(tmp,sol(jewel,index+1,c))
    dp[jewel][index][cap]=tmp
    return tmp
print(sol(0,0,c))
