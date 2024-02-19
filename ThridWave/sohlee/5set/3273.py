import sys
n=int(sys.stdin.readline())
li=list(map(int,sys.stdin.readline().split()))
li.sort()
x=int(sys.stdin.readline())
ans=0
for i in range(n):
    if li[i]>x//2:
        break
    for j in range(i+1,n):
        if x-li[i]==li[j]:
            ans+=1
        if x-li[i]<li[j]:
            break
print(ans)
