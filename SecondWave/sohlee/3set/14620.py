import sys
n=int(sys.stdin.readline())
li=[]
for i in range(n):
    li.append(list(map(int,sys.stdin.readline().split())))
cost=[]
visited=[[0]*n for i in range(n)]

def check(x,y):
    if 1<=x<n-1 and 1<=y<n-1:
        if visited[x-1][y]==0 and visited[x+1][y]==0 and visited[x][y-1]==0 and visited[x][y+1]==0:
            return 1
        else:
            return 0
    return 0
        
    

def dfs(tmp,count):
    if count==3:
        cost.append(tmp)
        return
    for i in range(n):
        for j in range(n):
            if visited[i][j]==0:
                if check(i,j)==1:
                    visited[i][j]=1
                    visited[i-1][j]=1
                    visited[i+1][j]=1
                    visited[i][j-1]=1
                    visited[i][j+1]=1
                    tmp_cost=li[i][j]+li[i-1][j]+li[i+1][j]+li[i][j+1]+li[i][j-1]
                    tmp+=tmp_cost
                    dfs(tmp,count+1)
                    visited[i][j]=0
                    visited[i-1][j]=0
                    visited[i+1][j]=0
                    visited[i][j-1]=0
                    visited[i][j+1]=0
                    tmp-=tmp_cost
dfs(0,0)
print(min(cost))
