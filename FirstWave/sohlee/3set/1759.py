import sys

L,C=map(int,sys.stdin.readline().split())

li=list(map(str,sys.stdin.readline().split()))
li.sort()
ans=[]
vowel=['a','e','i','o','u']
v=0
c=0
def dfs(i):
    global v
    global c
    if len(ans)==L:
        if v>=1 and c>=2:
            for j in range(L):
                print(ans[j], end="")
            print()
            return
    for j in range(i, C):
        if li[j] not in ans:
            ans.append(li[j])
            if li[j] in vowel:
                v+=1
            else:
                c+=1
            dfs(j+1)
            current=ans.pop()
            if current in vowel:
                v-=1
            else:
                c-=1
dfs(0)