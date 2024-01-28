import sys, math
from collections import deque

"""
N과 K가 0이라면 0
N이 0이라면 1로 바꾸고 시작
"""
MAX_SIZE = 100001
visited = [MAX_SIZE] * MAX_SIZE
N, K = list(map(int, sys.stdin.readline().split()))
answer = ''


def solve():
    global N, K, answer

    path = str(N)
    time = 0
    visited[N] = 0
    
    if N == 0 and K == 0:
        answer = path
        return 0
    if N > K:
        path = ''
        visited[K] = N-K
        for i in range(N, K-1, -1):
            path += str(i) + ' '
        answer = path
        return
    if N == 0:
        N += 1
        time += 1
        visited[1] = 1
        path += ' 1'
    
    deq = deque([[N, time, path]])
    while deq:
        pos, time, path = deq.pop()
        if pos == K:
            answer = path
            continue
        if pos*2 < K*2 and pos*2 < MAX_SIZE and visited[pos*2] > time:
            deq.append([pos*2, time+1, path+' '+str(pos*2)])
            visited[pos*2] = time+1
        if pos+1 <= K and visited[pos+1] > time+1:
            deq.appendleft([pos+1, time+1, path+' '+str(pos+1)])
            visited[pos+1] = time+1
        if pos-1 >= 0 and visited[pos-1] > time+1:
            deq.appendleft([pos-1, time+1, path+' '+str(pos-1)])
            visited[pos-1] = time+1
        
solve()

print(visited[K])
print(answer)
