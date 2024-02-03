import sys
n=int(sys.stdin.readline())
li=str(input())
ans=-1e9
def operation(num1,num2,op):
    if op =='+':
        return num1+num2
    if op =='-':
        return num1-num2
    if op =='*':
        return num1*num2
def dfs(i,x):
    global ans
    if i==n-1:
        ans=max(ans,int(x))
    if i+2<n:
        dfs(i+2,operation(x,int(li[i+2]),li[i+1]))
    if i+4<n:
        dfs(i+4,operation(x,operation(int(li[i+2]),int(li[i+4]),li[i+3]),li[i+1]))
dfs(0,int(li[0]))
print(ans)
