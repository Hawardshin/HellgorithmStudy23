import sys
N=int(sys.stdin.readline())
board=[]
reverse_board=[]
ans=1e9
for i in range(N):
    tmp=str(input())
    board.append(tmp)
for i in range(N):
    tmp=[]
    for j in range(N):
        if board[i][j]=='H':
            tmp.append('T')
        else:
            tmp.append('H')
    reverse_board.append(tmp)
for i in range(2**N):
    current=[]
    for j in range(N):
        if i & (1<<j):
            current.append(reverse_board[j])
        else:
            current.append(board[j])
    cnt=0
    for a in range(N):
        Tcnt=0
        for b in range(N):
            if current[b][a]=='T':
                Tcnt+=1
        cnt+=min(Tcnt, N-Tcnt)
    ans=min(ans,cnt)
print(ans)
    