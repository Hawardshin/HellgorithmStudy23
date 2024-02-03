import sys
n=int(sys.stdin.readline())
scv=list(map(int,sys.stdin.readline().split()))
while len(scv)!=3:
    scv.append(0)
dp=[[[61]*61 for i in range(61)] for j in range(61)]
ans=1e9
def dfs(x,y,z):
    global ans
    if x<=0 and y<=0 and z<=0:
        ans=min(ans,dp[x][y][z])
        return
    for i in ((9, 3, 1), (9, 1, 3), (3, 1, 9), (3, 9, 1), (1, 9, 3), (1, 3, 9)):
        newx=x-i[0]
        newy=y-i[1]
        newz=z-i[2]
        if newx<0:
            newx=0
        if newy<0:
            newy=0
        if newz<0:
            newz=0
        if dp[newx][newy][newz]>dp[x][y][z]+1:
            dp[newx][newy][newz]=dp[x][y][z]+1
            dfs(newx,newy,newz)
dp[scv[0]][scv[1]][scv[2]]=0
dfs(scv[0],scv[1],scv[2])
print(ans)
