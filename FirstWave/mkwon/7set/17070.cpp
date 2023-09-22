#include <iostream>
#include <algorithm>

using namespace std;

int n,res=0,tab[20][20]={0,},vis[20][20]={0,};

// 가로 세로 대각선 0 1 2
void dfs(int x, int y, int ang){

    if(x==n-1 && y==n-1){
        res++; return;
    }

    // 세로
    if (ang!=0 && x!=n-1 && tab[x+1][y]==0 && vis[x+1][y]==0){
        vis[x+1][y]=1;
        dfs(x+1,y,1);
        vis[x+1][y]=0;
    }
    // 가로
    if (ang!=1 && y!=n-1 && tab[x][y+1]==0 && vis[x][y+1]==0){
        vis[x][y+1]=1;
        dfs(x,y+1,0);
        vis[x][y+1]=0;
    }
    // 대각선
    if (x!=n-1 && y!=n-1 && tab[x+1][y+1]==0 && tab[x+1][y]==0 && tab[x][y+1]==0 && vis[x+1][y+1]==0 && vis[x+1][y]==0 && vis[x][y+1]==0){
        vis[x+1][y+1]=1; vis[x+1][y]=1; vis[x][y+1]=1;
        dfs(x+1,y+1,2); 
        vis[x+1][y+1]=0; vis[x+1][y]=0; vis[x][y+1]=0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>tab[i][j];
        }
    }
    
    vis[0][0]=1; vis[0][1]=1;
    dfs(0,1,0);
    cout<<res;

    return 0;
}