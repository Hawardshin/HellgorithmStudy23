import sys
from collections import deque
N,M=map(int,sys.stdin.readline().split())
li=[]
roomcnt=0
dx=[1,0,-1,0]
dy=[0,1,0,-1]
visited=[[0]*N for i in range(M)]
rooms=[]
def bfs(x,y):
    global room
    width=1
    visited[x][y]=1
    q=deque()
    q.append((x,y))
    room.append([x,y])
    while q:
        x,y=q.popleft()
        for i in range(4):
            newx=x+dx[i]
            newy=y+dy[i]
            if 0<=newx<M and 0<=newy<N:
                if visited[newx][newy]==0 and li[x][y][i]=='0':
                    visited[newx][newy]=1
                    width+=1
                    q.append((newx,newy))
                    room.append([newx,newy])
    return width


for i in range(M):
    binary=[]
    tmp=list(map(int,sys.stdin.readline().split()))
    for j in tmp:
        s=''
        two=8
        while two:
            s+=str(j//two)
            j%=two
            two//=2
        binary.append(s)
    li.append(binary)


totalwidth=[]
for i in range(M):
    for j in range(N):
        if visited[i][j]==0:
            roomcnt+=1
            room=[]
            totalwidth.append(bfs(i,j))
            rooms.append(room)
wallbreak=max(totalwidth)
rooms = sorted(rooms, key = lambda x : len(x))
for i in range(roomcnt):
    for j in range(i+1,roomcnt):
        for x,y in rooms[i]:
            for k in range(4):
                newx=x+dx[k]
                newy=y+dy[k]
                if 0<=newx<M and 0<=newy<N and [newx,newy] in rooms[j]:
                    totalarea=len(rooms[i])+len(rooms[j])
                    if totalarea>wallbreak:
                        wallbreak=totalarea
                        break
print(roomcnt)
print(max(totalwidth))
print(wallbreak)

