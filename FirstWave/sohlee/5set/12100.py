import sys
from copy import deepcopy
n=int(sys.stdin.readline())
li=[]
for i in range(n):
    tmp=list(map(int,sys.stdin.readline().split()))
    li.append(tmp)

def move(board,direct):
    if direct==0:
        for i in range(n):
            top=n-1
            for j in range(n-2,-1,-1):
                if board[i][j]:
                    tmp=board[i][j]
                    board[i][j]=0
                    if board[i][top]==0:
                        board[i][top]=tmp
                    elif board[i][top]==tmp:
                        board[i][top]=tmp*2
                        top-=1
                    else:
                        top-=1
                        board[i][top]=tmp
    elif direct==1:
        for i in range(n):
            top=0
            for j in range(1,n):
                if board[i][j]:
                    tmp=board[i][j]
                    board[i][j]=0
                    if board[i][top]==0:
                        board[i][top]=tmp
                    elif board[i][top]==tmp:
                        board[i][top]=tmp*2
                        top+=1
                    else:
                        top+=1
                        board[i][top]=tmp
    elif direct==2:
        for i in range(n):
            top=n-1
            for j in range(n-2,-1,-1):
                if board[j][i]:
                    tmp=board[j][i]
                    board[j][i]=0
                    if board[top][i]==0:
                        board[top][i]=tmp
                    elif board[top][i]==tmp:
                        board[top][i]=tmp*2
                        top-=1
                    else:
                        top-=1
                        board[top][i]=tmp
    else:
        for i in range(n):
            top=0
            for j in range(1,n):
                if board[j][i]:
                    tmp=board[j][i]
                    board[j][i]=0
                    if board[top][i]==0:
                        board[top][i]=tmp
                    elif board[top][i]==tmp:
                        board[top][i]=tmp*2
                        top+=1
                    else:
                        top+=1
                        board[top][i]=tmp
    return board



def dfs(board,cnt):
    global ans
    if cnt==5:
        for i in range(n):
            for j in range(n):
                ans=max(ans,board[i][j])
        return

    for i in range(4):
        tmp_board=move(deepcopy(board),i)
        dfs(tmp_board,cnt+1)
ans=0
dfs(li,0)
print(ans)
