from collections import deque
dx = [-1,1,0,0]
dy = [0,0,-1,1]
 
def find_swan(swan_q, swan, visited, board):
    swan_nextq = deque()    # 백조가 얼음발견 시 값 저장 queue
    while swan_q:
        y, x = swan_q.popleft()
        if y == swan[1][0] and x == swan[1][1]: # 다른 백조를 만나는 경우
            return True, None
        # 다른 백조를 만나지 못하는 경우 
        for k in range(4):
            ny, nx = y+dy[k], x+dx[k]
            if (0<=ny<r) and (0<=nx<c) and (visited[ny][nx]==False):
                # 얼음이면 nextq에 저장
                if board[ny][nx] == 'X':
                    swan_nextq.append([ny, nx])
                # 물인 경우 계속 bfs진행
                else:
                    swan_q.append([ny,nx])
                visited[ny][nx] = True
    return False, swan_nextq
 
def melt_ice(water_q, board):
    water_nextq = deque()
    # 물의 위치 주변을 탐색
    while water_q:
        y, x = water_q.popleft()
        for k in range(4):
            ny, nx = y+dy[k], x+dx[k]
            if 0<=ny<r and 0<=nx<c:
                # 얼음인 경우 다음 탐색 대상으로 저장
                if board[ny][nx] == 'X':
                    water_nextq.append([ny,nx])
                    board[ny][nx] = '.'
    return water_nextq
 
def solution(board):
    water_q = deque()
    swan = []
    day = -1
    visited = [[False for _ in range(c)] for _ in range(r)]
 
    # board 위치 초기화 (물,백조)
    for row in range(r):
        for col, val in enumerate(board[row]):
            if val == '.' or val == 'L':
                water_q.append([row, col])
            if val == 'L':
                swan.append([row, col])
 
    # 백조의 위치 초기화
    swan_q = deque() # 백조가 다른백조 찾을때 사용
    y, x = swan[0][0], swan[0][1]
    swan_q.append([y,x])
    visited[y][x] = True
 
    while True:
        day += 1
        found_flag, swan_nextq = find_swan(swan_q, swan, visited, board)
        if found_flag: break
        water_q = melt_ice(water_q, board)
        swan_q = swan_nextq
 
    return day
 
 
r, c = map(int, input().split())
board = [list(input()) for _ in range(r)]
print(solution(board))