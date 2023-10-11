import sys
n=int(sys.stdin.readline())
li=list(map(int,sys.stdin.readline().split()))
stack=[]
i=1
j=0
while j<n:
    if li[j]==i:
        j+=1 ##바로 빼는 경우
        i+=1
        continue
    if len(stack)!=0:
        tmp=stack.pop()
        if tmp==i:
            i+=1
        else:
            stack.append(tmp)
            stack.append(li[j])
            j+=1
    else:
        stack.append(li[j])
        j+=1
if len(stack)!=0:
    while True:
        if i==n:
            break
        tmp=stack.pop()
        if tmp==i:
            i+=1
        else:
            break
if (i>=n):
    print("Nice")
else:
    print("Sad")