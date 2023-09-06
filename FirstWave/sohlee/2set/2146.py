import sys
from collections import deque
sys.setrecursionlimit(10**9)
N=int(sys.stdin.readline())
dx=[1,-1,0,0]
dy=[0,0,1,-1]
cnt=2
li=[]

visited=[[0]*(N) for i in range(N)]
for i in range(N):
    tmp=list(map(int,sys.stdin.readline().split()))
    li.append(tmp)
ans=1e9

def bfs(n):
    global ans
    q=deque()
    check=[[-1]*(N) for i in range(N)]
    for i in range(N):
        for j in range(N):
            if li[i][j]==n:
                q.append((i,j))
                check[i][j]=0
    while(q):
        x,y=q.popleft()
        for i in range(4):
            newx=x+dx[i]
            newy=y+dy[i]
            if 0<=newx<N and 0<=newy<N:
                if li[newx][newy]>0 and li[newx][newy]!=n:
                    ans=min(ans,check[x][y])
                    return
                if li[newx][newy]==0 and check[newx][newy]==-1:
                    check[newx][newy]=check[x][y]+1
                    q.append((newx,newy))
def dfs(i,j):
    for a in range(4):
        newx=i+dx[a]
        newy=j+dy[a]
        if 0<=newx<N and 0<=newy<N:
            if li[newx][newy]==1:
                li[newx][newy]=cnt
                dfs(newx,newy)



for i in range(N):
    for j in range(N):
        if (li[i][j]==1):
            li[i][j]=cnt
            dfs(i,j)
            cnt+=1
for i in range(2, cnt+1):
    bfs(i)
print(ans)
