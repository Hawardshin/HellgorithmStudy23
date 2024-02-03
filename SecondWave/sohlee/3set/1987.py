import sys
r,c=map(int,sys.stdin.readline().split())
li=[]
alpha=[0]*27
visited=[[0]*c for i in range(r)]
for i in range(r):
    li.append(list(str(input())))
dx=[0,0,1,-1]
dy=[1,-1,0,0]
ans=-1
def dfs(count,x,y):
    global ans
    for i in range(4):
        newx=x+dx[i]
        newy=y+dy[i]
        if 0<=newx<r and 0<=newy<c and visited[newx][newy]==0:
            if alpha[ord(li[newx][newy])-ord('A')]==0:
                visited[newx][newy]=1
                alpha[ord(li[newx][newy])-ord('A')]=1
                dfs(count+1,newx,newy)
                visited[newx][newy]=0
                alpha[ord(li[newx][newy])-ord('A')]=0
    ans=max(ans,count)
visited[0][0]=1
alpha[ord(li[0][0])-ord('A')]=1
dfs(1,0,0)

print(ans)
