import sys
n, k = map(int, sys.stdin.readline().split())
board = [list(map(int, sys.stdin.readline().split())) for i in range(n)]
chess = [[[] for i in range(n)] for j in range(n)]
horse = []
for i in range(k):
    x, y, d = map(int, sys.stdin.readline().split())
    horse.append([x-1, y-1, d-1])
    chess[x-1][y-1].append(i)

dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

count = 0

def move(a):
    if a in [0, 2]:
        a+=1
    elif a in [1, 3]:
        a-=1
    return a

def solve(num):
    x, y, d = horse[num]
    newx = x + dx[d]
    newy = y + dy[d]
    if 0 > newx or newx >= n or 0 > newy or newy >= n or board[newx][newy] == 2:
        d = move(d)
        horse[num][2] = d
        newx = x + dx[d]
        newy = y + dy[d]
        if 0 > newx or newx >= n or 0 > newy or newy >= n or board[newx][newy] == 2:
            return True
    horse_up = []
    for index, h_n in enumerate(chess[x][y]):
        if h_n == num:
            horse_up.extend(chess[x][y][index:])
            chess[x][y] = chess[x][y][:index]
            break
    if board[newx][newy] == 1:
        horse_up = horse_up[-1::-1]
    for h in horse_up:
        horse[h][0], horse[h][1] = newx, newy
        chess[newx][newy].append(h)
    if len(chess[newx][newy]) >= 4:
        return False
    return True

while True:
    flag = False
    if count>1000:
        print(-1)
        break
    for i in range(k):
        if solve(i) == False:
            flag = True
            break
    count+=1
    if flag:
        print(count)
        break