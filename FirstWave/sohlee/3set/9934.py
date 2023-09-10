import sys
k=int(sys.stdin.readline())
li=list(map(int,sys.stdin.readline().split()))

visited=[[] for i in range(k)]
def dfs(i, tmp):
    if i==k:
        return
    middle=len(tmp)//2
    visited[i].append(tmp[middle])
    dfs(i+1, tmp[:middle])
    dfs(i+1, tmp[middle+1:])


dfs(0, li)

for i in range(k):
    for j in range(len(visited[i])):
        print(visited[i][j], end=" ")
    print()
