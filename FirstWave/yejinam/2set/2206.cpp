#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
 
using namespace std;
 
#define MAX 1000
 
typedef struct {
    int y, x;
}Dir;
 
Dir moveDir[4] = { {1,0},{0,1},{-1,0},{0,-1} };
 
int N, M;
char graph[MAX + 1][MAX + 1];
int visited[MAX + 1][MAX + 1][2]; 
bool is_inside(int _ny, int _nx) {
    return (_ny >= 1 && _ny <= N && _nx >= 1 && _nx <= M);
}
 
int bfs() {
    queue<pair<pair<int, int>, int > > q;
    q.push({ {1,1} , 1});
    visited[1][1][1] = 1;
 
    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int block = q.front().second;
        q.pop();
 
        if (y == N  && x == M ) {
            return visited[y][x][block];
        }
 
        for (int i = 0; i < 4; i++) {
            int ny = y + moveDir[i].y;
            int nx = x + moveDir[i].x;
 
            if (is_inside(ny, nx)) {
                if (graph[ny][nx] == '1' && block) {
                    visited[ny][nx][block - 1] = visited[y][x][block] + 1;
                    q.push({ { ny,nx }, block - 1 });
                }
                if (graph[ny][nx] == '0' && visited[ny][nx][block] == 0) {
                    visited[ny][nx][block] = visited[y][x][block] + 1;
                    q.push({ { ny,nx }, block });
                }
            }
        }
    }
    return -1;
}
 
int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%s", &graph[i][1]);
    }
        
    printf("%d\n", bfs());
    return 0;
}
