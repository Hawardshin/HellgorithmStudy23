import sys
from collections import deque
R,C=map(int,sys.stdin.readline().split())
board=[]
dx=[1,-1,0,0]
dy=[0,0,1,-1]
alpha=[0]*27
ans=0

'''
def bfs():
    q=deque()
    q.append((0,0))
    visited[0][0]=1
    alpha[ord(board[0][0])-ord('A')]=1
    while q:
        x,y=q.popleft()
        for i in range(4):
            newx=x+dx[i]
            newy=y+dy[i]
            if 0<=newx<R and 0<=newy<C:
                currentalpha=ord(board[newx][newy])-ord('A')
                if visited[newx][newy]==0 and alpha[currentalpha]==0:
                    visited[newx][newy]=1
                    alpha[currentalpha]=1
                    q.append((newx,newy))
                    '''
def dfs(x,y,cnt):
    global ans
    ans=max(ans,cnt)
    for i in range(4):
        newx=x+dx[i]
        newy=y+dy[i]
        if 0<=newx<R and 0<=newy<C:
            if alpha[ord(board[newx][newy])-65]==0:
                alpha[ord(board[newx][newy])-65]=1
                dfs(newx,newy,cnt+1)

                alpha[ord(board[newx][newy])-65]=0
    
for i in range(R):
    tmp=str(input())
    board.append(tmp)
alpha[ord(board[0][0])-65]=1   
dfs(0,0,1)
print(ans)
