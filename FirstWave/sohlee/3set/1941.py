import sys
from collections import deque
li=[list(input()) for i in range(5)]

arr=[]
result=0
dx=[1, -1, 0, 0]
dy=[0, 0, 1, -1]
def bfs(arr):
    check=1
    visited=[[1] * 5 for i in range(5)]
    for i in arr:
        visited[i[0]][i[1]]=0
    visited[arr[0][0]][arr[0][1]] = 1
    q=deque()
    q.append([arr[0][0], arr[0][1]])
    while q:
        x,y=q.popleft()
        for i in range(4):
            newx=x+dx[i]
            newy=y+dy[i]
            if 0<=newx<5 and 0<=newy<5:
                if visited[newx][newy]==0:
                    visited[newx][newy]=1
                    check+=1
                    q.append((newx, newy))
    if check==7:
        return True
    return False       

def dfs(people, start, cnt):
    global result
    if cnt >= 4:
        return
    if people==7:
        if bfs(arr):
            result+=1
        return
    for i in range(start, 25):
        r=i//5
        c=i%5
        arr.append((r,c))
        dfs(people+1, i+1, cnt+ (li[r][c] == 'Y'))
        arr.pop()
dfs(0,0,0)
print(result)