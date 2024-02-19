import sys
n=int(sys.stdin.readline())
li=[]
ans=[[] for i in range(n)]
max_count=1
line=0
for i in range(n):
    li.append(list(map(int,sys.stdin.readline().split())))
li.sort(key=lambda x:(x[0],x[1]))

ans[0].append(li[0][0])
ans[0].append(li[0][1])
line=li[0][1]-li[0][0]
for i in range(1,n):
    flag=False
    for j in range(max_count):
        #스타트가 기존거에 포함되어있지 않은 경우 -> 그런 경우는 있을 수 없음
        if li[i][0]<=ans[j][1]:
            tmp=li[i][1]-ans[j][1]
            if tmp>0:
                line+=tmp
                ans[j][1]=li[i][1]
            flag=True
            break
    if flag==False:
        ans[max_count].append(li[i][0])
        ans[max_count].append(li[i][1])
        line+=li[i][1]-li[i][0]
        max_count+=1
print(line)
            
