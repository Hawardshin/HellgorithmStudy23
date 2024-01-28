import sys

N, B = list(map(int, sys.stdin.readline().split()))
matrix = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]

def matrix_multiply(X, Y):
    global N
    R = [[0] * N for _ in range(N)]

    for row in range(N):
        for col in range(N):
            for i in range(N):
                R[row][col] += X[row][i] * Y[i][col]
            R[row][col] %= 1000
    return R

def matrix_square(X, B):
    if B == 1:
        for row in range(N):
            for col in range(N):
                X[row][col] %= 1000
        return X
    tmp = matrix_square(X, B//2)
    if B % 2 == 0:
        return matrix_multiply(tmp, tmp)
    return matrix_multiply(matrix_multiply(tmp, tmp), X)

answer = matrix_square(matrix, B)

for row in answer:
    print(*row)
