import sys
n,m,h=map(int,sys.stdin.readline().split())
li=[[0]*n for i in range(h)]
for i in range(m):
    a,b=map(int,sys.stdin.readline().split())
    li[a-1][b-1]=1
ans=4

def check():
    for start in range(n):
        now=start
        for j in range(h):
            if li[j][now]:
                now+=1
            elif now>0 and li[j][now-1]:
                now-=1
        if now!=start:
            return False
    return True

def dfs(x,y,count):
    global ans
    if check():
        ans=min(ans,count)
        return
    elif count==3 or ans<=count:
        return
    for i in range(x,h):
        if i==x:
            now=y
        else:
            now=0
        for j in range(now,n-1):
            if not li[i][j] and not li[i][j+1]:
                if j>0 and li[i][j-1]:
                    continue
                li[i][j]=True
                dfs(i,j+2,count+1)
                li[i][j]=False
                    

dfs(0,0,0)

if ans>=4:
    print(-1)
else:
    print(ans)
