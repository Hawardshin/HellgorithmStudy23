import sys
n=int(sys.stdin.readline())
li=[[0]*101 for i in range(101)]
dx=[0,-1,0,1]
dy=[1,0,-1,0]

for i in range(n):
    y,x,d,g=map(int,sys.stdin.readline().split())
    li[x][y]=1
    curve=[d]
    for j in range(g):
        for k in range(len(curve)-1,-1,-1):
            curve.append((curve[k]+1)%4)
    for j in range(len(curve)):
        x+=dx[curve[j]]
        y+=dy[curve[j]]
        if 0<=x<101 and 0<=y<101:
            li[x][y] = 1

ans=0
for i in range(100):
    for j in range(100):
        if li[i][j]==1 and li[i+1][j]==1 and li[i][j+1]==1 and li[i+1][j+1]==1:
            ans+=1
print(ans)
