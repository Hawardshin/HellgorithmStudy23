import sys
import itertools
from collections import deque
N=int(sys.stdin.readline())
people=list(map(int,sys.stdin.readline().split()))
people.insert(0,0)
visited=[[0]*(N+1) for i in range(N+1)]
ans=1e9
def bfs(sec):
    check=[1]*(N+1)
    for i in sec:
            check[i]=0
    q=deque()
    cnt=1
    check[sec[0]]=1
    q.append(sec[0])
    while q:
        current=q.popleft()
        for i in range(len(visited[current])):
                if visited[current][i]==1 and check[i]==0:
                        q.append(i)
                        check[i]=1
                        cnt+=1
    if cnt==len(sec):
            return True
    else:
            return False

for i in range(N):
		near=list(map(int,sys.stdin.readline().split()))
		near.pop(0)
		for j in near:
				visited[i+1][j]=1
combi=[i+1 for i in range(N)]
section=[]
for i in range(1,N):
    tmp=list(itertools.combinations(combi,i))
    section+=tmp
for i in range(len(section)//2):
    A=section[i]
    B=section[len(section)-i-1]
    if bfs(A) and bfs(B):
            Acnt=0
            Bcnt=0
            for i in A:
                    Acnt+=people[i]
            for i in B:
                    Bcnt+=people[i]
            ans=min(ans,abs(Acnt-Bcnt))
if ans==1e9:
        print(-1)
else:
        print(ans)
