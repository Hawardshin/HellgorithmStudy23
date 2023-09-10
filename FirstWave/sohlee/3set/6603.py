import sys
def dfs(i):
    if len(ans)==6:
        for j in range(6):
            print(ans[j], end=" ")
        print()
        return
    for j in range(i,cnt):
        if j<cnt and li[j] not in ans:
            ans.append(li[j])
            dfs(j+1)
            ans.pop()
li=list(map(int,sys.stdin.readline().split()))
while True:
    if len(li)==1 and li[0]==0:
        break
    cnt=li.pop(0)
    ans=[]
    dfs(0)
    li=list(map(int,sys.stdin.readline().split()))
    if len(li)==1 and li[0]==0:
        break
    print()
