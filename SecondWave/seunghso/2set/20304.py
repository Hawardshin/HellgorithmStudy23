import sys
from collections import deque

N = int(sys.stdin.readline())
M = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))

MAX = 0
while True:
    MAX += 1
    if (1 << MAX) > N:
        break
        
safety = [MAX+1] * (N+1)
for num in arr:
    safety[num] = 0

answer = 0
deq = deque(arr)
while deq:
    num = deq.popleft()
    for i in range(MAX):
        new_num = num ^ (1 << i)
        if new_num > N:
            continue
        if safety[new_num] > safety[num]+1:
            safety[new_num] = safety[num]+1
            answer = max(answer, safety[new_num])
            deq.append(new_num)

print(answer)

