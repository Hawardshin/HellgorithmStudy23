import sys

N,M=map(int,sys.stdin.readline().split())
li=list(map(int,sys.stdin.readline().split()))
ans=0
end=0
total=0
for i in range(N):
    while (total < M and end < N):
        total+=li[end]
        end+=1
    if (total == M):
        ans+=1
    total-=li[i]
print(ans)
