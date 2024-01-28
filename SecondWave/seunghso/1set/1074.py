import sys


N, r, c = list(map(int, sys.stdin.readline().split()))

answer = 0

def solve(row, col, size):
    global answer
    if size == 1:
        return
    size = size // 2
    if r < row + size:
        if c < col + size:
            solve(row, col, size)
        else:
            answer += size * size
            solve(row, col+size, size)
    else:
        if c < col + size:
            answer += size * size * 2
            solve(row+size, col, size)
        else:
            answer += size * size * 3
            solve(row+size, col+size, size)
solve(0, 0, 2 << N)

print(answer)