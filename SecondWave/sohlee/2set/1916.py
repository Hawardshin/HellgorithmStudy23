import sys
import heapq
n=int(sys.stdin.readline())
m=int(sys.stdin.readline())
li=[[] for i in range(n+1)]
distance=[1e9]*(n+1)
for i in range(m):
    a,b,c=map(int,sys.stdin.readline().split())
    li[a].append((c,b))
last_a,last_b=map(int,sys.stdin.readline().split())
def dijkstra(start):
    q=[]
    heapq.heappush(q,(0,start))
    distance[start]=0
    while q:
        dist,now=heapq.heappop(q)
        if distance[now]<dist:
            continue
        for i in li[now]:
            cost=dist+i[0]
            if cost<distance[i[1]]:
                distance[i[1]]=cost
                heapq.heappush(q,(cost,i[1]))
dijkstra(last_a)
print(distance[last_b])