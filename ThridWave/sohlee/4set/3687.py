import sys
t=int(sys.stdin.readline())
number=[6,2,5,5,4,5,6,3,7,6]
dp=[-1,-1,1,7,4,2,6,8,10,18,22]
def find_max(n):
    ans=[1]*(n//2)
    if n%2==1:
        ans[0]=7
    return ans

def find_min(n):
    ans=[8]*((n+6)//7)
    if n%7==1:
        ans[0]=1
        ans[1]=0
    elif n%7==2:
        ans[0]=1
    elif n%7==3:
        ans[0]=2
        ans[1]=0
        ans[2]=0
    elif n%7==4:
        ans[0]=2
        ans[1]=0
    elif n%7==5:
        ans[0]=2
    elif n%7==6:
        ans[0]=6
    return ans
        
for i in range(t):
    n=int(sys.stdin.readline())
    if n<11:
        print(dp[n],end=" ")
    else:
        print(*find_min(n), sep='', end= " ")
    print(*find_max(n),sep='')
