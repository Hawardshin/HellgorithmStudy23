#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

#define INF 2147483647

struct W{
    int r, c, d;
};
 
struct cmp{
    bool operator()(const W &a, const W &b){
        return a.d > b.d;
    }
};

int n,m,t,d,tab[30][30]={0,},vis[30][30],maxtop;
int dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0};

void dijkstra(int r, int c, int flag){
    int temp[27][27];
    for(int i = 0; i < 27; i++){
        for(int j = 0; j < 27; j++){
            temp[i][j] = INF;
        }
    }
    priority_queue<W, vector<W>, cmp> pq;
    pq.push({r, c, 0});

    while(!pq.empty()){
        W now = pq.top();
        pq.pop();
        
        if(!flag && now.r == 0 && now.c == 0){
            vis[r][c] = now.d;
            return;
        }
        
        if(flag && now.d + vis[now.r][now.c] > d) continue;
        if(flag && tab[now.r][now.c] > maxtop) maxtop = tab[now.r][now.c];
        
        for(int k = 0; k < 4; k++){
            int nr = now.r + dr[k];
            int nc = now.c + dc[k];
            int next_d = now.d;
            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(abs(tab[nr][nc] - tab[now.r][now.c]) > t) continue;
            
            if(tab[nr][nc] > tab[now.r][now.c]){
                next_d += pow(tab[nr][nc] - tab[now.r][now.c], 2);
            }
            else next_d += 1;
            
            if(next_d >= temp[nr][nc] || next_d > d) continue;
            temp[nr][nc] = next_d;
            pq.push({nr, nc, next_d});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin>>n>>m>>t>>d;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            char c; cin>>c;
            if (c>='A' && c<='Z') tab[i][j]=c-'A';
            else tab[i][j]=c-'a'+26;
        }
    }
    maxtop = tab[0][0];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            vis[i][j]=INF;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            dijkstra(i,j,0);
        }
    }
    dijkstra(0,0,1);
    cout<<maxtop;

    return 0;
}
