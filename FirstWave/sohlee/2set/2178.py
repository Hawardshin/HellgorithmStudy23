import sys
from collections import deque
sys.setrecursionlimit(10**6)
N,M=map(int,sys.stdin.readline().split())
li=[]
ans=[[0]*M for i in range(N)]
ans[0][0]=1
q=deque([(0,0)])
dx,dy=[1,-1,0,0],[0,0,1,-1]
for i in range(N):
    tmp=str(sys.stdin.readline())
    li.append(tmp)

while q:
    x,y=q.popleft()
    for i in range(4):
        newx=x+dx[i]
        newy=y+dy[i]
        if 0<=newx<N and 0<=newy<M:
            if ans[newx][newy]==0 and li[newx][newy]=='1':
                ans[newx][newy]=ans[x][y]+1
                q.append((newx,newy))
print(ans[-1][-1])
                
