#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

typedef tuple<int, int, int, int> pos;

int n, m, k, vis[1005][1005][11]={0,};
char tab[1005][1005];
queue <pos> q;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin>>n>>m>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>tab[i][j];
        }
    }

    vis[0][0][k]=1;
    q.push({0, 0, k, 1});
    while(!q.empty()){
        int x, y, wall, cnt;
        tie(x, y, wall, cnt) = q.front();
        q.pop();

        if(x==n-1 && y==m-1){
            cout<<cnt;
            return 0;
        }

        for (int dir=0; dir<4; ++dir) {
            int nx = x+dx[dir];
            int ny = y+dy[dir];

            if (nx>=0 && nx<n && ny>=0 && ny<m) {
                if (tab[nx][ny]=='0' && vis[nx][ny][wall]==0) {
                    vis[nx][ny][wall] = 1;
                    q.push({nx, ny, wall, cnt+1});
                } else if (tab[nx][ny]=='1' && wall > 0 && !vis[nx][ny][wall-1]) {
                    vis[nx][ny][wall-1] = 1;
                    q.push({nx, ny, wall-1, cnt+1});
                }
            }
        }
    }

    cout<<"-1";

    return 0;
}
