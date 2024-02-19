import sys
import heapq

n,k=map(int,sys.stdin.readline().split())
jewel=[]
for i in range(n):
    heapq.heappush(jewel,list(map(int,sys.stdin.readline().split())))
bags=[]
for i in range(k):
    bags.append(int(sys.stdin.readline()))
bags.sort()
ans=0
tmp_jewel=[]
for i in bags:
    while jewel and i>=jewel[0][0]:
        heapq.heappush(tmp_jewel,-heapq.heappop(jewel)[1])
    if tmp_jewel:
        ans-=heapq.heappop(tmp_jewel)
    elif not jewel:
        break
print(ans)
