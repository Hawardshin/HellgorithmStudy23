import sys
import itertools
n,m,k=map(int,sys.stdin.readline().split())
li=[]
for i in range(n):
    tmp=list(map(int,sys.stdin.readline().split()))
    li.append(tmp)
rotation=[]
for i in range(k):
    tmp=list(map(int,sys.stdin.readline().split()))
    rotation.append(tmp)

def rotate(r,c,s):
    for i in range(s):
        r1, c1, r2, c2 = r-s+i, c-s+i, r+s-i, c+s-i
        one=tmp[r1][c1]
        for i in range(r1,r2):
            tmp[i][c1]=tmp[i+1][c1]
        for i in range(c1, c2):
            tmp[r2][i]=tmp[r2][i+1]
        for i in range(r2,r1,-1):
            tmp[i][c2]=tmp[i-1][c2]
        for i in range(c2,c1+1,-1):
            tmp[r1][i]=tmp[r1][i-1]
        tmp[r1][c1+1]=one
    
combi=[i for i in range(k)]
permut=list(itertools.permutations(combi,k))
ans=1e9
for i in permut:
    tmp=[a[:] for a in li]
    for j in i:
        r,c,s=rotation[j]
        for i in range(s):
            r1, c1, r2, c2 = r-s+i-1, c-s+i-1, r+s-i-1, c+s-i-1
            one=tmp[r1][c1]
            for i in range(r1,r2):
                tmp[i][c1]=tmp[i+1][c1]
            for i in range(c1, c2):
                tmp[r2][i]=tmp[r2][i+1]
            for i in range(r2,r1,-1):
                tmp[i][c2]=tmp[i-1][c2]
            for i in range(c2,c1+1,-1):
                tmp[r1][i]=tmp[r1][i-1]
            tmp[r1][c1+1]=one

    for k in range(n):
        ans=min(ans,sum(tmp[k]))
print(ans)
