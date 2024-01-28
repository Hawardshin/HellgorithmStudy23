import sys
"""
압축이 되면 해당 숫자 추가
안되면 괄호추가하고 호출4번
"""
N = int(sys.stdin.readline())
arr = [list(map(int, list(sys.stdin.readline().rstrip()))) for _ in range(N)]

answer = []
def solve(row, col, size):
    for i in range(size):
        if not all(arr[row+i][col:col+size]):
            break
    else:
        answer.append('1')
        return
    for i in range(size):
        if any(arr[row+i][col:col+size]):
            break
    else:
        answer.append('0')
        return

    answer.append('(')
    size = size // 2
    solve(row, col, size)
    solve(row, col+size, size)
    solve(row+size, col, size)
    solve(row+size, col+size, size)
    answer.append(')')
solve(0, 0, N)
print(''.join(answer))
