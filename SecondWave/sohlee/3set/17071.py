from collections import deque
import sys
n,k=map(int,sys.stdin.readline().split())
visited=[[-1,-1] for i in range(500001)]
def move(index,now):
    if index==0:
        return now+1
    if index==1:
        return now-1
    return 2*now
def bfs(now,k):
    q=deque()
    second=0
    q.append((now,second))
    visited[now][0]=0
    while q:
        for i in range(len(q)):
            now,second=q.popleft()
            for index in range(3):
                next=move(index,now)
                if not (0<=next<500001):
                    continue
                if visited[next][(second+1)%2]!=-1:
                    continue
                q.append((next,second+1))
                visited[next][(second+1)%2]=second+1
bfs(n,k)
ans=-1
second=0
for i in range(500001):
    k+=i
    if k>500000:
        break
    if visited[k][second%2]<=second:
        ans=second
        break
    second+=1
print(ans)
