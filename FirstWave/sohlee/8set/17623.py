import sys
t=int(sys.stdin.readline())
dp=['0']*(1001)
dp[1]='12'
dp[2]='34'
dp[3]='56'
def check(a,b):
    if b=='0':
        return a
    if len(a)<len(b):
        return a
    elif len(a)>len(b):
        return b
    else:
        return(min(a,b))
for i in range(4,1001):
    if i%2==0:
        dp[i]=check('1'+dp[i//2]+'2',dp[i])
    if i%3==0:
        dp[i]=check('3'+dp[i//3]+'4',dp[i])
    if i%5==0:
        dp[i]=check('5'+dp[i//5]+'6',dp[i])
    for j in range(1,i):
        dp[i]=check(dp[i-j]+dp[j],dp[i])

for i in range(t):
    n=int(sys.stdin.readline())
    for j in dp[n]:
        if j=="1":
            print("(",end="")
        elif j=="2":
            print(")",end="")
        elif j=="3":
            print("{",end="")
        elif j=="4":
            print("}",end="")
        elif j=="5":
            print("[",end="")
        else:
            print("]",end="")
    print()
