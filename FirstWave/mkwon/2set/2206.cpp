#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define INF 2147483647

typedef struct {
    int x;
    int y;
    int wall;
} pos;

int n,m,vis[1005][1005][2]={0,};
char tab[1005][1005];
queue <pos> q;

int main()
{
    ios_base::sync_with_stdio(false);

    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>tab[i][j];
        }
    }

    pos p; p.x=0; p.y=0; p.wall=0; q.push(p); vis[0][0][0]=1;
    while (!q.empty()){
        int x=q.front().x;
        int y=q.front().y;
        int wall=q.front().wall;
        q.pop();

        if (x==n-1 && y==m-1){
            cout<<vis[x][y][wall]; return 0;
        }

        // 벽 아닐때
        if (x!=0 && tab[x-1][y]=='0' && vis[x-1][y][wall]==0){
            vis[x-1][y][wall]=vis[x][y][wall]+1;
            pos temp; temp.x=x-1; temp.y=y; temp.wall=wall; q.push(temp);
        }
        if (x!=n-1 && tab[x+1][y]=='0' && vis[x+1][y][wall]==0){
            vis[x+1][y][wall]=vis[x][y][wall]+1;
            pos temp; temp.x=x+1; temp.y=y; temp.wall=wall; q.push(temp);
        }
        if (y!=0 && tab[x][y-1]=='0' && vis[x][y-1][wall]==0){
            vis[x][y-1][wall]=vis[x][y][wall]+1;
            pos temp; temp.x=x; temp.y=y-1; temp.wall=wall; q.push(temp);
        }
        if (y!=m-1 && tab[x][y+1]=='0' && vis[x][y+1][wall]==0){
            vis[x][y+1][wall]=vis[x][y][wall]+1;
            pos temp; temp.x=x; temp.y=y+1; temp.wall=wall; q.push(temp);
        }

        // 벽일때
        if (x!=0 && tab[x-1][y]=='1' && wall==0){
            vis[x-1][y][1]=vis[x][y][wall]+1;
            pos temp; temp.x=x-1; temp.y=y; temp.wall=1; q.push(temp);
        }
        if (x!=n-1 && tab[x+1][y]=='1' && wall==0){
            vis[x+1][y][1]=vis[x][y][wall]+1;
            pos temp; temp.x=x+1; temp.y=y; temp.wall=1; q.push(temp);
        }
        if (y!=0 && tab[x][y-1]=='1' && wall==0){
            vis[x][y-1][1]=vis[x][y][wall]+1;
            pos temp; temp.x=x; temp.y=y-1; temp.wall=1; q.push(temp);
        }
        if (y!=m-1 && tab[x][y+1]=='1' && wall==0){
            vis[x][y+1][1]=vis[x][y][wall]+1;
            pos temp; temp.x=x; temp.y=y+1; temp.wall=1; q.push(temp);
        }
    }

    cout<<"-1";

    return 0;
}
