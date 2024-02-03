import sys
from collections import deque
sys.setrecursionlimit(10**6)
n,k=map(int,sys.stdin.readline().split())
visited=[0]*200001
min_time=1e9
count=0
def bfs():
    global min_time
    global count
    while q:
        x,time=q.popleft()
        if x==k:
            if time<min_time:
                min_time=time
                count=1
            elif time==min_time:
                count+=1
            continue
        if time>=min_time:
            continue
        if x-1>=0 and (visited[x-1]==0 or visited[x-1]==time+1):
            q.append((x-1,time+1))
            visited[x-1]=time+1
        if x+1<=100000 and (visited[x+1]==0 or visited[x+1]==time+1):
            q.append((x+1,time+1))
            visited[x+1]=time+1
        if 2*x<=100000 and (visited[2*x]==0 or visited[2*x]==time+1):
            q.append((2*x,time+1))
            visited[2*x]=time+1


q=deque()
q.append((n,0))
visited[n]=0
bfs()
print(min_time)
print(count)
