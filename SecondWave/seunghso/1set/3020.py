"""
짝수 홀수 따로 계산한다

odd = [0] * (H+1)
even = [0] * (H+1)
각각 높이별로 장애물이 몇개 있는지 탐색한다.

홀수의 경우, 동굴의 높이 부터 1까지 1씩 내려가면서 누적합을 구한다. -> odd
짝수의 경우, 1부터 동굴의 높이까지 1씩 올리면서 누적합을 구한다. -> even

idx 높이로 날 경우 홀수번째 구간에서 부딪히는 횟수 -> prefix_odd[idx]
idx 높이로 날 경우 짝수번째 구간에서 부딪히는 횟수 -> prefix_even[idx]

충돌 최솟값을 math.inf, cnt = 0 초기화
탐색하면서 최솟값을 갱신할 때마다 cnt=1로 초기화, 최솟값을 만날경우 cnt+=1
"""

import sys
import math

N, H = list(map(int, sys.stdin.readline().split()))
arr = [int(sys.stdin.readline()) for _ in range(N)]

odd = [0] * (H+1)
even = [0] * (H+1)

for i in range(0, N, 2):
    odd[arr[i]] += 1
for i in range(1, N, 2):
    even[arr[i]] += 1

prefix_odd = [0] * (H+1)
prefix_even = [0] * (H+1)

prefix_odd[H-1] = odd[H-1]
for i in range(H-2, 0, -1):
    prefix_odd[i] = prefix_odd[i+1] + odd[i]

prefix_even[2] = even[2]
for i in range(2, H+1):
    prefix_even[i] = prefix_even[i-1] + even[H-i+1]

answer1 = math.inf
answer2 = 0

for i in range(1, H+1):
    cnt = prefix_odd[i] + prefix_even[i]
    if answer1 > cnt:
        answer1 = cnt
        answer2 = 1
    elif answer1 == cnt:
        answer2 += 1

print(answer1, answer2)