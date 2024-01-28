import sys, math
from collections import deque

"""
N과 K가 0이라면 0
N이 0이라면 1로 바꾸고 시작
"""
visited = [math.inf] * 200000
N, K = list(map(int, sys.stdin.readline().split()))

def solve():
    global N, K

    time = 0
    visited[N] = 0
    
    if N == 0 and K == 0:
        return 0
    if N == 0:
        N += 1
        time += 1
        visited[1] = 1
    deq = deque([[N, time]])
    while deq:
        pos, time = deq.pop()
        if pos == K:
            continue
        if pos*2 < K*2 and visited[pos*2] > time:
            deq.append([pos*2, time])
            visited[pos*2] = time
        if pos+1 <= K and visited[pos+1] > time+1:
            deq.appendleft([pos+1, time+1])
            visited[pos+1] = time+1
        if pos-1 >= 0 and visited[pos-1] > time+1:
            deq.appendleft([pos-1, time+1])
            visited[pos-1] = time+1
        
solve()

print(visited[K])
