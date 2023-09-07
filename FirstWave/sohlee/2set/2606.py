import sys
sys.setrecursionlimit(10**6)

N=int(sys.stdin.readline())
M=int(sys.stdin.readline())
li=[[0]*(N+1) for i in range(N+1)]
visited=[0]*(N+1)
for i in range(M):
    a,b=map(int,sys.stdin.readline().split())
    li[a][b]=1
    li[b][a]=1

def dfs(num):
    for i in range(1, N+1):
        if li[num][i]==1 and visited[i]==0:
            visited[i]=1
            dfs(i)
visited[1]=1
dfs(1)
print(visited.count(1)-1)
