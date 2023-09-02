import sys
n,m = map(int, sys.stdin.readline().split())
li = list(map(int, sys.stdin.readline().split()))
for i in range(1, len(li)):
    li[i] = li[i -1] + li[i]
li.insert(0, 0)
for a in range(m):
    i,j = map(int, sys.stdin.readline().split())
    print(li[j] - li[i - 1])