import sys
N,M=map(int,sys.stdin.readline().split())
li=list(map(int,sys.stdin.readline().split()))
ans=[]
total=0
end=0
for i in range(N):
    while (total < M and end < N):
        total+=li[end]
        end+=1
    if total >= M:
        ans.append(end - i)
    total-=li[i]
if len(ans)==0:
    print(0)
else:
    print(min(ans))
