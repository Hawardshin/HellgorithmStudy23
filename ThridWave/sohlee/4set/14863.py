import sys
n,k=map(int,sys.stdin.readline().split())
dp=[[-1]*(k+1) for i in range(n)]
li=[]
for i in range(n):
    tmp=list(map(int,sys.stdin.readline().split()))
    li.append(tmp)
def calculate(index, total):
    if total<0:
        return -1e9
    if index==n:
        return 0
    if dp[index][total]!=-1:
        return dp[index][total]
    dp[index][total]=max(calculate(index+1,total-li[index][0])+li[index][1], calculate(index+1,total-li[index][2])+li[index][3])
    return dp[index][total]
print(calculate(0,k))
    
