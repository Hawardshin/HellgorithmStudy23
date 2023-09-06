import sys
from collections import deque

sys.setrecursionlimit(10**9)
N,M=map(int,sys.stdin.readline().split())
dx=[1,-1,0,0]
dy=[0,0,1,-1]
li=[]
for i in range(N):
    tmp=list(map(int,list(input())))
    li.append(tmp)
visited = [[[0]*2 for i in range(M)] for j in range(N)]
visited[0][0][0]=1

q=deque()
q.append((0,0,0))
while q:
    x,y,z=q.popleft()
    for i in range(4):
        newx=x+dx[i]
        newy=y+dy[i]
        if 0<=newx<N and 0<=newy<M:
            if li[newx][newy]== 1 and z!=1:
                visited[newx][newy][1]=visited[x][y][0] + 1
                q.append((newx,newy,1))
            elif li[newx][newy]==0 and visited[newx][newy][z]==0:
                visited[newx][newy][z]=visited[x][y][z]+1
                q.append((newx,newy,z))
if visited[-1][-1][0]==0 and visited[-1][-1][1]==0:
    print(-1)
elif visited[-1][-1][0]==0:
    print(visited[-1][-1][1])
elif visited[-1][-1][1]==0:
    print(visited[-1][-1][0])
else:
    print(min(visited[-1][-1][0],visited[-1][-1][1]))
