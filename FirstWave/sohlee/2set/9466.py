import sys
sys.setrecursionlimit(10**9)
T=int(sys.stdin.readline())

def dfs(n):
    global team
    temp.append(n)
    visited[n]=1
    if visited[pair[n-1][1]] != 0:
        if pair[n-1][1] in temp:
            team+=temp[temp.index(pair[n-1][1]):]
        return
    else:
        dfs(pair[n-1][1])

for i in range(T):
    pair=[]
    n=int(sys.stdin.readline())
    team=[]
    li=list(map(int,sys.stdin.readline().split()))
    visited=[0]*(n+1)
    for a in range(n):
        pair.append([a+1,li[a]])
    for a in range(1,n+1):
        if visited[a] == 0:
            temp=[]
            dfs(a)
    print(n-len(team))
