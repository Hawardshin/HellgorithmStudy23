import sys
n=int(sys.stdin.readline())
li=[]
for i in range(n):
    li.append(list(map(int,sys.stdin.readline().split())))
li.sort(key=lambda x:(x[0],x[1]))
time=0

for i in range(n):
    if time>=li[i][0]:
        time+=li[i][1]
    else:
        time=li[i][0]+li[i][1]
print(time)
