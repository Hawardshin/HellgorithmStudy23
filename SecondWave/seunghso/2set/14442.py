import sys, math
from collections import deque

def solve():
    N, M, K = list(map(int, sys.stdin.readline().split()))
    arr = [list(map(int, list(sys.stdin.readline().rstrip()))) for _ in range(N)]

    MAX_SIZE = N*M
    visited = [[[MAX_SIZE] * M for _ in range(N)] for __ in range(K+1)]
    visited[0][0][0] = 1
    
    deq = deque([[0, 0, 0]])
    dx = [0, 0, -1, 1]
    dy = [1, -1, 0, 0]
    
    answer = -1
    
    while deq:
        dms, y, x = deq.pop()
        if y == N-1 and x == M-1:
            return visited[dms][y][x]
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            if nx < 0 or nx >= M or ny < 0 or ny >= N:
                continue
            if arr[ny][nx] and dms < K and visited[dms+1][ny][nx] == MAX_SIZE:
                visited[dms+1][ny][nx] = visited[dms][y][x]+1
                deq.appendleft([dms+1, ny, nx])
            if arr[ny][nx] == 0 and visited[dms][ny][nx] == MAX_SIZE:
                visited[dms][ny][nx] = visited[dms][y][x]+1
                deq.appendleft([dms, ny, nx])

    return -1
    
print(solve())

