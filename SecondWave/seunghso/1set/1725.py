import sys, math

N = int(sys.stdin.readline())
arr = [int(sys.stdin.readline()) for _ in range(N)]

arr.append(0)

answer = 0
stack = [[0, arr[0]]]

for i in range(1, N+1):
    l = i
    while stack and stack[-1][1] > arr[i]:
        l, height = stack.pop()
        answer = max(answer, (i - l) * height)
    stack.append([l, arr[i]])

print(answer)