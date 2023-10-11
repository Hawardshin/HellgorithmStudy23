#공기가 안통하는건 0
#공기가 통하는건 3
#이번차례에 녹은건 2
#치즈있는곳은 1

import sys
from collections import deque
n,m=map(int,sys.stdin.readline().split())
board=[]
for i in range(n):
    tmp=list(map(int,sys.stdin.readline().split()))
    board.append(tmp)
flag=True
dx=[1,-1,0,0]
dy=[0,0,1,-1]
for i in range(m):
    board[0][i]=3
for i in range(n):
    board[i][0]=3

def bfs(i,j):
    q=deque()
    board[i][j]=3
    q.append((i,j))
    while q:
        x,y=q.popleft()
        for i in range(4):
            newx=x+dx[i]
            newy=y+dy[i]
            if 0<=newx<n and 0<=newy<m:
                if board[newx][newy]==0:
                    board[newx][newy]=3
                    q.append((newx,newy))

def make_new(board):
    for i in range(1,n):
        for j in range(1,m):
            if board[i][j]==0:
                for k in range(4):
                    newx=i+dx[k]
                    newy=j+dy[k]
                    if 0<=newx<n and 0<=newy<m:
                        if board[newx][newy]==3:
                            bfs(i,j)

ans=0
while flag:
    flag=False
    cnt=0
    for i in range(n):
        for j in range(m):
            if board[i][j]==2:
                cnt+=1
                board[i][j]=0
    make_new(board)
    for i in range(n):
        for j in range(m):
            if board[i][j]==1:
                for k in range(4):
                    newx=i+dx[k]
                    newy=j+dy[k]
                    if 0<=newx<n and 0<=newy<m:
                        if board[newx][newy]==3: ##맞닿은 부분이 3이면(공기가 통하는 곳이면)
                            board[i][j]=2
                            flag=True
    ans+=1
print(ans-1)
print(cnt)