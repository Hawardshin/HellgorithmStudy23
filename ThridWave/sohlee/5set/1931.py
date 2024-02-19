import sys
n=int(sys.stdin.readline())
li=[]
ans=[]
for i in range(n):
    li.append(list(map(int,sys.stdin.readline().split())))
li.sort(key=lambda x:(x[1],x[0]))
max_room=1
ans.append(li[0][1])
for i in range(1,n):
    if ans[-1]<=li[i][0]:
        ans.append(li[i][1])
print(len(ans))
