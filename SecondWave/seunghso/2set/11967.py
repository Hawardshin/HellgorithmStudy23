import sys

"""
nx = col + dx[i]
ny = row + dy[i]
를
nx = x + dx[i]
ny = y + dy[i]
로 적는 실수를 범하지 말 것
"""

N, M = map(int, sys.stdin.readline().split())
arr = [list(map(int, sys.stdin.readline().split())) for _ in range(M)]

switches = [[[] for _ in range(N+1)] for __ in range(N+1)]
for x, y, a, b in arr:
    switches[y][x].append([b, a])

visited = [[False]*(N+1) for _ in range(N+1)]
visited[1][1] = True
rooms = [[False]*(N+1) for _ in range(N+1)]
rooms[1][1] = True
answer = 1

dy = [0, 0, -1, 1]
dx = [1, -1, 0, 0]

stack = [[1, 1]]
while stack:
    y, x = stack.pop()
    for row, col in switches[y][x]:
        if rooms[row][col] == True:
            continue
        rooms[row][col] = True
        answer += 1
        # (row, col) 주변을 이미 다녀왔을 경우 stack에 추가
        for i in range(4):
            nx = col + dx[i]
            ny = row + dy[i]
            if not (1 <= nx <= N and 1 <= ny <= N):
                continue
            if visited[ny][nx]:
                stack.append([ny, nx])
    switches[y][x] = []
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if not (1 <= nx <= N and 1 <= ny <= N):
            continue
        if not visited[ny][nx] and rooms[ny][nx]:
            visited[ny][nx] = True
            stack.append([ny, nx])
print(answer)