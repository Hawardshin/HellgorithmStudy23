import sys
k = int(sys.stdin.readline())
li = list(map(str,sys.stdin.readline().split()))
ans=[]
final=[]
current=[]
def dfs():
    if len(current) == k+1:
        s=''
        for j in range(k+1):
            s+=str(current[j])
        ans.append(s)
        return
    for i in range(10):
        if i not in current:
            current.append(i)
            dfs()
            current.pop()

dfs()

for i in range(len(ans)):
    flag=True
    for j in range(len(li)):
        if li[j]=="<":
            if ans[i][j] > ans[i][j+1]:
                flag=False
                break
        else:
            if ans[i][j] < ans[i][j+1]:
                flag=False
                break
    if flag==True:
        final.append(ans[i])
print(final[-1])
print(final[0])
