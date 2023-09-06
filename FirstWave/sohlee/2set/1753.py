import sys
import heapq
V,E=map(int,sys.stdin.readline().split())

start=int(sys.stdin.readline())
li=[[] for i in range(V+1)]
for i in range(E):
    u,v,w=map(int,sys.stdin.readline().split())
    li[u].append([v,w])
q=[]
heapq.heappush(q,(0, start))
dist=[1e9]*(V+1)
dist[start]=0
while q:
    cur_dist,index = heapq.heappop(q)
    if dist[index] < cur_dist:
        continue
    for i in range(len(li[index])):
        cost = cur_dist+li[index][i][1]
        if cost < dist[li[index][i][0]]:
            dist[li[index][i][0]]=cost
            heapq.heappush(q, (cost, li[index][i][0]))
for i in range(1, len(dist)):
    if dist[i] == 1e9:
        print("INF")
    else:
        print(dist[i])
