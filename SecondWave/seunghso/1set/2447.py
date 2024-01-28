import sys

N = int(sys.stdin.readline())

arr = [[' ']*N for _ in range(N)]

def draw(arr, row, col, size):
    if size == 1:
        arr[row-1][col-1] = '*'
        return
    size = size//3
    for y in range(3):
        for x in range(3):
            if y == 1 and x == 1:
                continue
            draw(arr, row + size*y, col + size*x, size)

draw(arr, 1, 1, N)
for i in range(len(arr)):
    arr[i] = ''.join(arr[i])
    print(arr[i])
    