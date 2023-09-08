import sys
N,M = map(int, sys.stdin.readline().split())
li=list(map(int,sys.stdin.readline().split()))
li.sort()

ans=[]
def dfs(i):
    if len(ans) == M:
        for j in range(M):
            print(ans[j], end=" ")
        print()
        return
    for j in range(i, N):
        if j < N and li[j] not in ans:
            ans.append(li[j])
            dfs(j + 1)
            ans.pop()

dfs(0)
    