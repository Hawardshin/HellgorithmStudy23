#2번째,6번째 인덱스가 맞물리는거
import sys
t=int(sys.stdin.readline())
li=[]
def check_rotation(current_num,current_dir):
    if current_num-1>=0 and visited[current_num-1]==0:#첫번째톱니바퀴가 1
        if li[current_num][6]!=li[current_num-1][2]:#극이 같지 않으면
            stack.append([current_num-1,current_dir*-1])
            visited[current_num-1]=1
            check_rotation(current_num-1,current_dir*-1)
    if current_num+1<t and visited[current_num+1]==0:
        if li[current_num][2]!=li[current_num+1][6]:
            stack.append([current_num+1,current_dir*-1])
            visited[current_num+1]=1
            check_rotation(current_num+1,current_dir*-1)
    
for i in range(t):
    li.append(str(input()))
k=int(sys.stdin.readline())
for i in range(k):
    num,direction=map(int,sys.stdin.readline().split())
    stack=[]
    stack.append([num-1,direction])#인덱스기준
    visited=[0]*(t+1)
    visited[num-1]=1
    check_rotation(num-1,direction)
    for i in range(len(stack)):
        tmp_num,tmp_dir=stack.pop()
        if tmp_dir==1:
            li[tmp_num]=li[tmp_num][-1]+li[tmp_num][:7]
        else:
            li[tmp_num]=li[tmp_num][1:]+li[tmp_num][0]
cnt=0
for i in range(t):
    if li[i][0]=='1':
        cnt+=1
print(cnt)
