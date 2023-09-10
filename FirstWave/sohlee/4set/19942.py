import sys
import itertools

N=int(sys.stdin.readline())
mp,mf,ms,mv=map(int,sys.stdin.readline().split())
li=[]

combi=[i for i in range(N)]
all=[]
ans=1e9
for i in range(N):
    tmp=list(map(int,sys.stdin.readline().split()))
    li.append(tmp)
finalcombi=[]
for i in range(N+1):
    tmp=list(itertools.combinations(combi,i))
    all.append(tmp)

for i in range(1, len(all)):
    for j in range(len(all[i])):
        pi,fi,si,vi,ci=0,0,0,0,0
        for k in all[i][j]:
            pi+=li[k][0]
            fi+=li[k][1]
            si+=li[k][2]
            vi+=li[k][3]
            ci+=li[k][4]
        if pi>=mp and fi>=mf and si>=ms and vi>=mv:
            if ans>ci:
                ans=ci
                finalcombi=all[i][j]
            if ans==ci:
                if finalcombi>all[i][j]:
                    finalcombi=all[i][j]
if ans==1e9:
    print(-1)
else:
    print(ans)
    for i in range(len(finalcombi)):
        if i!=len(finalcombi)-1:
            print(finalcombi[i]+1, end= " ")
        else:
            print(finalcombi[i]+1)