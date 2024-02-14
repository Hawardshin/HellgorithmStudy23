import sys
from collections import deque


a,b,c,d=map(int,sys.stdin.readline().split())
visited={}


def bfs():
    while q:
        cur_a,cur_b=q.popleft()
        cnt=visited.get((cur_a,cur_b))
        if not visited.get((a,cur_b)):
            visited[(a,cur_b)]=cnt+1
            q.append((a,cur_b))
        if not visited.get((cur_a,b)):
            visited[(cur_a,b)]=cnt+1
            q.append((cur_a,b))
        if not visited.get((0,cur_b)):
            visited[(0,cur_b)]=cnt+1
            q.append((0,cur_b))
        if not visited.get((cur_a,0)):
            visited[(cur_a,0)]=cnt+1
            q.append((cur_a,0))

        if (cur_a+cur_b)>b:
            if not visited.get((cur_a+cur_b-b,b)):#a->b물이 넘칠때
                visited[(cur_a+cur_b-b,b)]=cnt+1
                q.append((cur_a+cur_b-b,b))
        else:
            if not visited.get((0,cur_b+cur_a)):
                visited[(0,cur_b+cur_a)]=cnt+1
                q.append((0,cur_b+cur_a))
        if (cur_a+cur_b)>a:
            if not visited.get((a,cur_a+cur_b-a)):
                visited[(a,cur_a+cur_b-a)]=cnt+1
                q.append((a,cur_a+cur_b-a))
        else:
            if not visited.get((cur_b+cur_a,0)):
                visited[(cur_b+cur_a,0)]=cnt+1
                q.append((cur_b+cur_a,0))
        
            
        

q=deque()
visited[(0,0)]=0
q.append((0,0))
bfs()
if c==0 and d==0:
    print(0)
elif not visited.get((c,d)):
    print(-1)
else:
    print(visited.get((c,d)))
