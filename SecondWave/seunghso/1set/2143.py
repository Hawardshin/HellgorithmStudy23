import sys
from bisect import bisect_left, bisect_right 

answer = 0

T = int(sys.stdin.readline())
n = int(sys.stdin.readline())
arr_a = list(map(int, sys.stdin.readline().split()))
m = int(sys.stdin.readline())
arr_b = list(map(int, sys.stdin.readline().split()))

prefix_sum_a = []
prefix_sum_b = []

for i in range(n):
    s = 0
    for j in range(i, n):
        s += arr_a[j]
        prefix_sum_a.append(s)

for i in range(m):
    s = 0
    for j in range(i, m):
        s += arr_b[j]
        prefix_sum_b.append(s)

prefix_sum_a.sort()
prefix_sum_b.sort()

answer = 0

for psa in prefix_sum_a:
    target = T - psa
    l = bisect_left(prefix_sum_b, target)
    r = bisect_right(prefix_sum_b, target)
    answer += r - l

print(answer)