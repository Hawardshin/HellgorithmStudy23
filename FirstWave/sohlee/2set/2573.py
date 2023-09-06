import sys
import copy
from collections import deque
sys.setrecursionlimit(10**9)

N,M=map(int,sys.stdin.readline().split())
li=[]
dx=[1,-1,0,0]
dy=[0,0,1,-1]
ans=0
cnt=1
check=[[-1]*M for i in range(N)]
for i in range(N):
    tmp=list(map(int,sys.stdin.readline().split()))
    li.append(tmp)

def check_division():
    global cnt
    global check
    flag=False
    check=[[0]*M for i in range(N)]
    cnt=1
    for x in range(N):
        for y in range(M):
            if li[x][y] > 0 and check[x][y]==0:
                cnt+=1
                flag=True
                q=deque()
                q.append((x,y))
                check[x][y]=1
                while q:
                    cur_x,cur_y=q.popleft()
                    for i in range(4):
                        newx=cur_x+dx[i]
                        newy=cur_y+dy[i]
                        if 0<=newx<N and 0<=newy<M:
                            if li[newx][newy]<=0:
                                check[cur_x][cur_y]+=1
                            if li[newx][newy]>0 and check[newx][newy]==0:
                                check[newx][newy]=1
                                q.append((newx,newy))
    return flag

def check_ice():
    for a in range(N):
        for b in range(M):
            if check[a][b]>0:
                li[a][b]-=(check[a][b]-1)

while cnt<3:
    if check_division() == False:
        print(0)
        exit()
    else:
        check_ice()
        ans+=1
print(ans-1)
