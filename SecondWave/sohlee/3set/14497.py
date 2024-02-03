import sys
from collections import deque
n,m=map(int,sys.stdin.readline().split())
x1,y1,x2,y2=map(int,sys.stdin.readline().split())
li=[]
visited=[[0]*m for i in range(n)]
for i in range(n):
    li.append(list(str(input())))
dx=[0,0,-1,1]
dy=[1,-1,0,0]
def bfs():
    while q:
        count,cur_x,cur_y=q.popleft()
        if cur_x==x2-1 and cur_y==y2-1:
            return count
        for i in range(4):
            newx=cur_x+dx[i]
            newy=cur_y+dy[i]
            if 0<=newx<n and 0<=newy<m and visited[newx][newy]==0:
                if li[newx][newy]=='0':
                    q.appendleft((count,newx,newy))
                    visited[newx][newy]=visited[cur_x][cur_y]
                else:
                    q.append((count+1,newx,newy))
                    visited[newx][newy]=visited[cur_x][cur_y]

                

q=deque()
q.append((0,x1-1,y1-1))
visited[x1-1][y1-1]=1
print(bfs())
