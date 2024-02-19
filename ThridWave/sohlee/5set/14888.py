import sys
n=int(sys.stdin.readline())
a=list(map(int,sys.stdin.readline().split()))
min_val=int(1e9)
max_val=int(-1e9)
plus,minus,multiply,divide=map(int,sys.stdin.readline().split())

def dfs(current,i):
    global plus,minus,multiply,divide,min_val,max_val
    if i==n:
        min_val=min(min_val,current)
        max_val=max(max_val,current)
        return
    if plus>=1:
        plus-=1
        dfs(current+a[i],i+1)
        plus+=1
    if minus>=1:
        minus-=1
        dfs(current-a[i],i+1)
        minus+=1
    if multiply>=1:
        multiply-=1
        dfs(current*a[i],i+1)
        multiply+=1
    if divide>=1:
        divide-=1
        if current<0:
            dfs(((-1*current)//a[i])*-1,i+1)
        else:
            dfs(current//a[i],i+1)
        divide+=1
dfs(a[0],1)
print(max_val)
print(min_val)
