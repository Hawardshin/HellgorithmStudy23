import sys
n,m=map(int,sys.stdin.readline().split())
h=list(map(int,sys.stdin.readline().split()))
current=m
h.sort()
for i in h:
    if i<=current:
        current+=1
print(current)

