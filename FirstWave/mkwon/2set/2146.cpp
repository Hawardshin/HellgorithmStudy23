#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

#define INF 2147483647

int n,tab[105][105]={0,},label[105][105]={0,},vis[105][105]={0,};
queue <pair<int,int>> q;

typedef struct {
    int x;
    int y;
    int cnt;
} pos;

void dfs(int x, int y, int num){
    if (x!=0 && tab[x-1][y]==1 && vis[x-1][y]==0){
        vis[x-1][y]=1; label[x-1][y]=num; dfs(x-1,y,num);
    }
    if (x!=n-1 && tab[x+1][y]==1 && vis[x+1][y]==0){
        vis[x+1][y]=1; label[x+1][y]=num; dfs(x+1,y,num);
    }
    if (y!=0 && tab[x][y-1]==1 && vis[x][y-1]==0){
        vis[x][y-1]=1; label[x][y-1]=num; dfs(x,y-1,num);
    }
    if (y!=n-1 && tab[x][y+1]==1 && vis[x][y+1]==0){
        vis[x][y+1]=1; label[x][y+1]=num; dfs(x,y+1,num);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>tab[i][j];
            if (tab[i][j]) q.push({i,j});
        }
    }

    // 섬 라벨링
    int num=0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (vis[x][y] == 0){dfs(x,y,++num); label[x][y]=num; }
    }

    // 각각의 섬 마다 도달할 수 있는 최단 거리
    int res = INF;
    for(int i=0; i<num; i++){

        queue <pos> posq;
        for(int i=0; i<n; i++) memset(vis[i], 0, sizeof(vis[i]));

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if (label[i][j]==num){
                    vis[i][j]=1;
                    pos p; p.x=i; p.y=j; p.cnt=0;
                    posq.push(p);
                } 
            }
        }

        while (!posq.empty()){
            int x = posq.front().x;
            int y = posq.front().y;
            int cnt = posq.front().cnt;
            posq.pop();
            // cout<<"num : "<<i<<", pos : "<<x<<" "<<y<<" "<<cnt<<" \n";

            // 다른 섬 도달
            if (x!=0 && tab[x-1][y]==1 && vis[x-1][y]==0){
                if (res > cnt){ res = cnt; break; }
            }
            if (x!=n-1 && tab[x+1][y]==1 && vis[x+1][y]==0){
                if (res > cnt){ res = cnt; break; }
            }
            if (y!=0 && tab[x][y-1]==1 && vis[x][y-1]==0){
                if (res > cnt){ res = cnt; break; }
            }
            if (y!=n-1 && tab[x][y+1]==1 && vis[x][y+1]==0){
                if (res > cnt){ res = cnt; break; }
            }
            
            // 다리 놓기
            if (x!=0 && tab[x-1][y]==0 && vis[x-1][y]==0){
                vis[x-1][y]=1; pos p; p.x=x-1; p.y=y; p.cnt=cnt+1; posq.push(p);
            }
            if (x!=n-1 && tab[x+1][y]==0 && vis[x+1][y]==0){
                vis[x+1][y]=1; pos p; p.x=x+1; p.y=y; p.cnt=cnt+1; posq.push(p);
            }
            if (y!=0 && tab[x][y-1]==0 && vis[x][y-1]==0){
                vis[x][y-1]=1; pos p; p.x=x; p.y=y-1; p.cnt=cnt+1; posq.push(p);
            }
            if (y!=n-1 && tab[x][y+1]==0 && vis[x][y+1]==0){
                vis[x][y+1]=1; pos p; p.x=x; p.y=y+1; p.cnt=cnt+1; posq.push(p);
            }
        }
    }
    cout<<res;

    return 0;
}
