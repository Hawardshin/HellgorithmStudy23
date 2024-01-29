import sys
from collections import defaultdict

N = int(sys.stdin.readline())

dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]


def solve():
    h, w = map(int, sys.stdin.readline().split())
    arr = [list(sys.stdin.readline().rstrip()) for _ in range(h)]
    keys = list(sys.stdin.readline().rstrip())
    if keys[0] == '0':
        keys = []

    stack = []
    answer = 0
    _dict = defaultdict(list)

    visited = [[False]*w for _ in range(h)]
    new_keys = []

    for row in range(h):
        for col in range(w):
            if ((not (0<row<h-1)) or (not (0<col<w-1))) and arr[row][col] != '*':
                if arr[row][col] == '$':
                    answer += 1
                if arr[row][col].isupper():
                    key = arr[row][col].lower()
                    if not key in keys:
                        _dict[key].append((row, col))
                        continue
                if arr[row][col].islower():
                    new_keys.append(arr[row][col])
                arr[row][col] = '.'
                visited[row][col] = True
                stack.append((row, col))
                continue
            if arr[row][col].isupper():
                key = arr[row][col].lower()
                if not key in keys:
                    _dict[key].append((row, col))
                else:
                    arr[row][col] = '.'
    
    for key in new_keys:
        for row, col in _dict[key]:
            if (not (0<row<h-1)) or (not (0<col<w-1)):
                stack.append((row, col))
            arr[row][col] = '.'
            for j in range(4):
                nrow = row + dy[j]
                ncol = col + dx[j]
                if not (0 <= nrow < h and 0 <= ncol < w):
                    continue
                if visited[nrow][ncol]:
                    visited[row][col] = True
                    stack.append((row, col))

    while stack:
        y, x = stack.pop()
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if not (0 <= nx < w and 0 <= ny < h):
                continue
            if arr[ny][nx] == '$':
                answer += 1
                arr[ny][nx] = '.'
            if arr[ny][nx].islower():
                key = arr[ny][nx].lower()
                arr[ny][nx] = '.'
                for row, col in _dict[key]:
                    arr[row][col] = '.'
                    if (not (0<row<h-1)) or (not (0<col<w-1)):
                        stack.append((row, col))
                        continue
                    for j in range(4):
                        nrow = row + dy[j]
                        ncol = col + dx[j]
                        if not (0 <= nrow < h and 0 <= ncol < w):
                            continue
                        if visited[nrow][ncol]:
                            visited[row][col] = True
                            stack.append((row, col))
                            break
                        
            if arr[ny][nx] == '.' and not visited[ny][nx]:
                stack.append((ny, nx))
                visited[ny][nx] = True
    print(answer)

for i in range(N):
    solve()