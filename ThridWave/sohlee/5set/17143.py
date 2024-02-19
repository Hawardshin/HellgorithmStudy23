import sys
r,c,m = map(int, sys.stdin.readline().split())                                                                      
dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]                                                                          
li = [[[] for i in range(c)] for j in range(r)]                                    
for i in range(m):
    x,y,s,d,z = map(int,sys.stdin.readline().split())
    li[x-1][y-1].append([z,s,d-1])
def move():
    g = [[[] for i in range(c)] for j in range(r)]
    for i in range(r):
        for j in range(c):
            if li[i][j]:
                x,y=i,j
                z,s,d = li[i][j][0]
                cnt=s
                while cnt>0:
                    newx = x + dx[d]
                    newy = y + dy[d]
                    if 0>newx or newx>=r or newy<0 or newy>=c:
                        if d in [0, 2]:
                            d+=1
                        elif d in [1, 3]:
                            d-=1
                        continue
                    else:
                        x, y = newx, newy
                        cnt-=1
                g[x][y].append([z, s, d])
    for i in range(r):
        for j in range(c):
            li[i][j] = g[i][j]

eat_count = 0

for i in range(c):
    for j in range(r):
        if li[j][i]:
            val = li[j][i][0]
            eat_count += val[0]
            li[j][i].remove(val)
            break
    move()

    for p in range(r):
        for q in range(c):
            if len(li[p][q])>=2:
                li[p][q].sort(reverse=True)
                while len(li[p][q]) >= 2:
                    li[p][q].pop()                                                                                     
print(eat_count)
