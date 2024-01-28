import sys
from collections import deque

N, M, P = map(int, sys.stdin.readline().split())
S = list(map(int, sys.stdin.readline().split()))
arr = [list(sys.stdin.readline().rstrip()) for _ in range(N)]

deqs = [deque() for _ in range(P+1)]
answer = [0] * (P+1)
for row in range(N):
    for col in range(M):
        if arr[row][col].isdigit():
            deqs[int(arr[row][col])].append([0, row, col])
            answer[int(arr[row][col])] += 1

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

round = 0

while True:
    cnt = 0
    round += 1
    for p in range(1, P+1):
        limit = S[p-1]
        deq = deqs[p]
        while deq:
            depth, y, x = deq.popleft()
            if depth+1 > limit * round:
                deq.appendleft([depth, y, x])
                break
                
            for i in range(4):
                ny = y + dy[i]
                nx = x + dx[i]
                if not (0 <= nx < M and 0 <= ny < N):
                    continue
                if arr[ny][nx] == '.':
                    answer[p] += 1
                    deq.append([depth+1, ny, nx])
                    arr[ny][nx] = str(p)
                    cnt += 1
    if not cnt:
        break

print(*answer[1:])