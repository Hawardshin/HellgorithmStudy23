import sys, math
from collections import deque


def solve():
    N, M, K = list(map(int, sys.stdin.readline().split()))
    arr = [list(map(int, list(sys.stdin.readline().rstrip()))) for _ in range(N)]

    MAX_SIZE = N*M*2
    visited = [[[MAX_SIZE] * M for _ in range(N)] for __ in range(K+1)]
    visited[0][0][0] = 1
    
    deq = deque([[0, 0, 0, 1]])
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    
    answer = MAX_SIZE
    
    while deq:
        cnt, y, x, day = deq.pop()
        breakable = day % 2
        if y == N-1 and x == M-1:
            answer = min(answer, day)
            continue
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            if nx < 0 or nx >= M or ny < 0 or ny >= N:
                continue
            if arr[ny][nx] and cnt < K and visited[cnt+1][ny][nx] == MAX_SIZE:
                if breakable:
                    visited[cnt+1][ny][nx] = day+1
                    deq.appendleft([cnt+1, ny, nx, day+1])
                else:
                    deq.appendleft([cnt, y, x, day+1])
            if arr[ny][nx] == 0 and visited[cnt][ny][nx] == MAX_SIZE:
                visited[cnt][ny][nx] = day+1
                deq.appendleft([cnt, ny, nx, day+1])
    print(answer if answer != MAX_SIZE else -1)
solve()