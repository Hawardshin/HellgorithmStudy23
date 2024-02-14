import sys
import math
import itertools

n,c=map(int,sys.stdin.readline().split())
li=list(map(int,sys.stdin.readline().split()))

def findSub(ar):
    sub=[]
    for select in range(len(ar)+1):
        pool=map(sum,itertools.combinations(ar,select))
        for p in pool:
            if p<=c:
                sub.append(p)
    return sub

def get_pair(ar,i):
    if i>c:
        return 0
    start=0
    end=len(ar)-1
    while start<=end:
        mid=(start+end)//2
        target=ar[mid]+i
        if target<=c:
            start=mid+1
        else:
            end=mid-1
    return start
cnt=0
div=n//2
wei_a=li[:div]
wei_b=li[div:]
subsum_a=findSub(wei_a)
subsum_b=findSub(wei_b)
subsum_a.sort()
for b in subsum_b:
    cnt+=get_pair(subsum_a,b)
print(cnt)
