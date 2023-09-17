import sys
N,L=map(int,sys.stdin.readline().split())
li=[]
ans=0
for i in range(N):
    tmp=list(map(int,sys.stdin.readline().split()))
    li.append(tmp)

def check(line):
    for i in range(1,N):
        if abs(line[i]-line[i-1])>1:
            return 0
        if line[i]<line[i-1]:
            for j in range(L):
                if i+j>=N or line[i]!=line[i+j] or slope[i+j]==1:
                    return False
                if line[i]==line[i+j]:
                    slope[i+j]=True
        elif line[i]>line[i-1]:
            for j in range(L):
                if i-j-1 <0 or line[i-1]!=line[i-j-1] or slope[i-j-1]==1:
                    return False
                if line[i-1]==line[i-j-1]:
                    slope[i-j-1]=True
    return True

for i in range(N):
    slope=[0]*N
    if check([li[i][j] for j in range(N)]):
        ans+=1
for j in range(N):
    slope=[0]*N
    if check([li[i][j] for i in range(N)]):
        ans+=1
print(ans)