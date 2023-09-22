#include <iostream>
#include <algorithm>
using namespace std;

int n,m,res=0,vis[55][55]={0,},dp[55][55]={0,};
char tab[55][55];

// void dfs(int x, int y, int cnt){
//     if (res < cnt) res=cnt;
//     if (x<0 || y<0 || x>=n || y>=m) return ;
//     if (tab[x][y]=='H') return;
//     if (dp[x][y]>cnt) return;
//     if (vis[x][y]==1) { cout<<"-1"; exit(0); }

//     int num = tab[x][y]-'0';
//     dp[x][y]=cnt;
    
//     vis[x][y]=1;
//     dfs(x-num,y,cnt+1);
//     dfs(x+num,y,cnt+1);
//     dfs(x,y-num,cnt+1);
//     dfs(x,y+num,cnt+1);
//     vis[x][y]=0;
// }

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int DFS(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m || tab[x][y] == 'H') 
		return 0;

	if (vis[x][y] == 1) {
		cout << -1 << endl;
		exit(0);
	}

	if (dp[x][y] != -1)
		return dp[x][y];

	vis[x][y] = 1;
	dp[x][y] = 0;
 
    int num = tab[x][y]-'0';
	for (int i = 0; i < 4; i++) {
		
		int nx = x + (num * dx[i]);
		int ny = y + (num * dy[i]);

		dp[x][y] = max(dp[x][y], DFS(nx, ny) + 1);
	}

	vis[x][y] = false;

	return dp[x][y];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>tab[i][j];
            dp[i][j]=-1;
        }
    }

    // vis[0][0]=1;
    // dfs(0,0,0);
    cout<<DFS(0, 0);;

    return 0;
}