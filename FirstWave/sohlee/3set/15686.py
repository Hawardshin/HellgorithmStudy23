import sys
import itertools
N,M=map(int,sys.stdin.readline().split())
li=[]
for i in range(N):
    tmp=list(map(int,sys.stdin.readline().split()))
    li.append(tmp)
home=[]
chicken=[]
cost=[]
for i in range(N):
    for j in range(N):
        if li[i][j]==1:
            home.append([i,j])
        elif li[i][j]==2:
            chicken.append([i,j])
chickencombi=[i for i in range(len(chicken))]

for i in range(len(chicken)):
    tmp=[]
    for j in range(len(home)):
        tmp.append(abs(chicken[i][0]-home[j][0]) + abs(chicken[i][1]-home[j][1]))
    cost.append(tmp)
final=len(chicken) - M
ans=0
current=0
if final<=0:
    for i in range(len(home)):
        perhome=1e9
        for j in range(len(chicken)):
            perhome=min(perhome,cost[j][i])
        ans+=perhome
else:
    ans=1e9

    combi=list(itertools.combinations(chickencombi, M))
    for i in range(len(combi)):
        tmp=[]
        current=0
        for j in range(M):
            tmp.append(cost[combi[i][j]])
        for j in range(len(home)):
            perhome=1e9
            for k in range(len(tmp)):
                perhome=min(perhome,tmp[k][j])
            current+=perhome
        ans=min(ans, current)
print(ans)