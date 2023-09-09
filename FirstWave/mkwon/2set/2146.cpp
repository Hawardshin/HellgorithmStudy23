#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

#define INF 2147483647

int n,tab[105][105]={0,},label[105][105]={0,},vis[105][105]={0,};

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

int bfs(int num){
    queue<pair<int, int>> q;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (label[i][j] == num){
                q.push({i,j}); vis[i][j]=1;
            }
        }
    }

    int res=0;
    while(!q.empty()){
        int quesize = q.size();

        for(int i=0; i<quesize; i++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            //섬
            if (x!=0 && label[x-1][y]!=0 && label[x-1][y]!=num) return res;
            if (x!=n-1 && label[x+1][y]!=0 && label[x+1][y]!=num) return res;
            if (y!=0 && label[x][y-1]!=0 && label[x][y-1]!=num) return res;
            if (y!=n-1 && label[x][y+1]!=0 && label[x][y+1]!=num) return res;

            // 바다
            if (x!=0 && label[x-1][y]==0 && vis[x-1][y]==0){
                q.push({x-1,y}); vis[x-1][y]=1;
            }
            if (x!=n-1 && label[x+1][y]==0 && vis[x+1][y]==0){
                q.push({x+1,y}); vis[x+1][y]=1;
            }
            if (y!=0 && label[x][y-1]==0 && vis[x][y-1]==0){
                q.push({x,y-1}); vis[x][y-1]=1;
            }
            if (y!=n-1 && label[x][y+1]==0 && vis[x][y+1]==0){
                q.push({x,y+1}); vis[x][y+1]=1;
            }
        }
        res++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    queue<pair<int, int>> q;
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
        if (vis[x][y] == 0){
            label[x][y]=++num; 
            dfs(x,y,num); 
        }
    }

    // 각각의 섬 마다 도달할 수 있는 최단 거리
    int res = INF;
    for(int i=1; i<=num; i++){
        memset(vis, 0, sizeof(vis));
        res = min(res, bfs(i));
    }
    cout<<res;

    return 0;
}
