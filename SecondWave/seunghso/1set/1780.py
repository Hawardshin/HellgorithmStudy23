import sys
N = int(sys.stdin.readline())
arr = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

answer = []

def is_not_negative(num):
    return num != -1

def is_not_positive(num):
    return num != 1

def solve(row, col, size):
    for i in range(size):
        if any(arr[row+i][col:col+size]):
            break
    else:
        answer.append('0')
        return
    for i in range(size):
        if any(map(is_not_positive, arr[row+i][col:col+size])):
            break
    else:
        answer.append('1')
        return
    for i in range(size):
        if any(map(is_not_negative, arr[row+i][col:col+size])):
            break
    else:
        answer.append('-1')
        return

    size = size // 3
    for i in range(3):
        for j in range(3):
            solve(row + size*i, col + size * j, size)
    
solve(0, 0, N)
print(answer.count('-1'))
print(answer.count('0'))
print(answer.count('1'))