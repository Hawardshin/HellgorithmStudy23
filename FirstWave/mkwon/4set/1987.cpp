#include <iostream>
#include <algorithm>

using namespace std;
#define INF 2147483647

int n,m,alpha[30]={0,},res=0;
char tab[22][22];

void dfs(int x, int y, int cnt){

    if (cnt>res) res=cnt;

    if (x!=0 && alpha[tab[x-1][y]-'A'] == 0){
        alpha[tab[x-1][y]-'A']=1;
        dfs(x-1,y,cnt+1);
        alpha[tab[x-1][y]-'A']=0;
    }
    if (x!=n-1 && alpha[tab[x+1][y]-'A'] == 0){
        alpha[tab[x+1][y]-'A']=1;
        dfs(x+1,y,cnt+1);
        alpha[tab[x+1][y]-'A']=0;
    }
    if (y!=0 && alpha[tab[x][y-1]-'A'] == 0){
        alpha[tab[x][y-1]-'A']=1;
        dfs(x,y-1,cnt+1);
        alpha[tab[x][y-1]-'A']=0;
    }
    if (y!=m-1 && alpha[tab[x][y+1]-'A'] == 0){
        alpha[tab[x][y+1]-'A']=1;
        dfs(x,y+1,cnt+1);
        alpha[tab[x][y+1]-'A']=0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>tab[i][j];
        }
    }

    alpha[tab[0][0]-'A']=1;
    dfs(0,0,1);

    cout<<res;

    return 0;
}