import sys
import copy
n,m=map(int,sys.stdin.readline().split())
li=[]

for i in range(n):
    li.append(list(map(int,sys.stdin.readline().split())))
cctv=[]
for i in range(n):
    for j in range(m):
        if li[i][j]!=0 and li[i][j]!=6:
            cctv.append([i,j,li[i][j]])#x,y,cctv번호
len_cctv=len(cctv)

def up(x,y,cur_li):
    tmp=copy.deepcopy(cur_li)
    x-=1
    while x>=0:
        if tmp[x][y]!=6:
            if tmp[x][y]==0:
                tmp[x][y]=-1
            x-=1
        else:
            break
    return tmp
def down(x,y,cur_li):
    tmp=copy.deepcopy(cur_li)
    x+=1
    while x<n:
        if tmp[x][y]!=6:
            if tmp[x][y]==0:
                tmp[x][y]=-1
            x+=1
        else:
            break
    return tmp
def left(x,y,cur_li):
    tmp=copy.deepcopy(cur_li)
    y-=1
    while y>=0:
        if tmp[x][y]!=6:
            if tmp[x][y]==0:
                tmp[x][y]=-1
            y-=1
        else:
            break
    return tmp
def right(x,y,cur_li):
    tmp=copy.deepcopy(cur_li)
    y+=1
    while y<m:
        if tmp[x][y]!=6:
            if tmp[x][y]==0:
                tmp[x][y]=-1
            y+=1
        else:
            break
    return tmp

def check_zero(current_list):

    cnt=0
    for i in range(n):
        for j in range(m):
            if current_list[i][j]==0:
                cnt+=1
    return cnt
ans=1e9
def dfs(i,cur_li):
    global ans
    if i==len_cctv:
        ans=min(ans,check_zero(cur_li))
        return
    x,y,num=cctv[i][0],cctv[i][1],cctv[i][2]
    if num==1:
        tmp_li=up(x,y,cur_li)
        dfs(i+1,tmp_li)
        tmp_li=down(x,y,cur_li)
        dfs(i+1,tmp_li)
        tmp_li=left(x,y,cur_li)
        dfs(i+1,tmp_li)
        tmp_li=right(x,y,cur_li)
        dfs(i+1,tmp_li)
    elif num==2:
        tmp_li=up(x,y,cur_li)
        tmp2_li=down(x,y,tmp_li)
        dfs(i+1,tmp2_li)
        tmp_li=left(x,y,cur_li)
        tmp2_li=right(x,y,tmp_li)
        dfs(i+1,tmp2_li)
    elif num==3:
        tmp_li=up(x,y,cur_li)
        tmp2_li=right(x,y,tmp_li)
        dfs(i+1,tmp2_li)
        tmp_li=right(x,y,cur_li)
        tmp2_li=down(x,y,tmp_li)
        dfs(i+1,tmp2_li)
        tmp_li=down(x,y,cur_li)
        tmp2_li=left(x,y,tmp_li)
        dfs(i+1,tmp2_li)
        tmp_li=left(x,y,cur_li)
        tmp2_li=up(x,y,tmp_li)
        dfs(i+1,tmp2_li)
    elif num==4:
        tmp_li=up(x,y,cur_li)
        tmp2_li=down(x,y,tmp_li)
        tmp3_li=left(x,y,tmp2_li)
        dfs(i+1,tmp3_li)
        tmp_li=up(x,y,cur_li)
        tmp2_li=down(x,y,tmp_li)
        tmp3_li=right(x,y,tmp2_li)
        dfs(i+1,tmp3_li)
        tmp_li=right(x,y,cur_li)
        tmp2_li=down(x,y,tmp_li)
        tmp3_li=left(x,y,tmp2_li)
        dfs(i+1,tmp3_li)
        tmp_li=up(x,y,cur_li)
        tmp2_li=right(x,y,tmp_li)
        tmp3_li=left(x,y,tmp2_li)
        dfs(i+1,tmp3_li)
    else:
        tmp_li=up(x,y,cur_li)
        tmp2_li=down(x,y,tmp_li)
        tmp3_li=left(x,y,tmp2_li)
        tmp4_li=right(x,y,tmp3_li)
        dfs(i+1,tmp4_li)
dfs(0,li)
print(ans)
