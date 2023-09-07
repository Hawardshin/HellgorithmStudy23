import sys
from collections import deque
sys.setrecursionlimit(10**6)

dx,dy,dz=[1,-1,0,0,0,0],[0,0,1,-1,0,0],[0,0,0,0,1,-1]
L,R,C=map(int,sys.stdin.readline().split())
while L!=0 and R!=0 and C!=0:
    li=[]
    ans=[[[0]*(C) for i in range(R)] for j in range(L)]
    for i in range(L):
        tmp=[]
        for j in range(R):
            temp=str(sys.stdin.readline())
            if 'S' in temp:
                start=[j,temp.find('S'),i]
            if 'E' in temp:
                end=[j,temp.find('E'),i]
            tmp.append(temp)
        s=str(sys.stdin.readline())
        li.append(tmp)
    q=deque([(start[0],start[1],start[2])])
    ans[start[2]][start[0]][start[1]]=1
    while q:
        x,y,z=q.popleft()
        for a in range(6):
            newx=x+dx[a]
            newy=y+dy[a]
            newz=z+dz[a]
            if 0<=newx<R and 0<=newy<C and 0<=newz<L:
                if ans[newz][newx][newy]==0 and li[newz][newx][newy]!='#':
                    ans[newz][newx][newy]=ans[z][x][y]+1
                    q.append((newx,newy,newz))
    if ans[end[2]][end[0]][end[1]] != 0:
        print("Escaped in",ans[end[2]][end[0]][end[1]]-1,"minute(s).")
    else:
        print("Trapped!")
    L,R,C=map(int,sys.stdin.readline().split())
