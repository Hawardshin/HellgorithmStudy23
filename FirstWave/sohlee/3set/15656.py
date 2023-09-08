import sys

N,M=map(int,sys.stdin.readline().split())

li=list(map(int,sys.stdin.readline().split()))

li.sort()
ans=[]


def dfs():
    if len(ans) == M:
        for j in range(M):
            print(ans[j], end=" ")
        print()
        return
    for i in range(N):
        ans.append(li[i])
        dfs()
        ans.pop()

dfs()