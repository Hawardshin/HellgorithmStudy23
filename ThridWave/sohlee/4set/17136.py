import sys
sys.setrecursionlimit(10**6)
li=[]
for i in range(10):
    li.append(list(map(int,sys.stdin.readline().split())))
cnt=1e9
paper=[5]*6

def check_board(width,x,y):
    for a in range(width):
        for b in range(width):
            if x+a>=10 or y+b>=10:
                return False
            if li[x+a][y+b]==0:
                return False
    return True


def backtracking(x,y,count):
    global cnt
    if x==10:
        cnt=min(cnt,count)
    elif y==10:
        backtracking(x+1,0,count)
    elif li[x][y]==0:
        backtracking(x,y+1,count)
    else:
        for i in range(1,6):
            if paper[i]==0:
                continue
            if x+i>10 or y+i>10:
                continue
            if check_board(i,x,y)==True:
                paper[i]-=1
                for a in range(i):
                    for b in range(i):
                        li[x+a][y+b]=0
                backtracking(x,y+i,count+1)
                paper[i]+=1
                for a in range(i):
                    for b in range(i):
                        li[x+a][y+b]=1
backtracking(0,0,0)
if cnt==1e9:
    print(-1)
else:
    print(cnt)
