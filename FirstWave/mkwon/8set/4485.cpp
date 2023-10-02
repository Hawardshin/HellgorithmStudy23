#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define INF 2147483647

int n,m,res;
// priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
queue <pair<int, int>> q;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int cnt=1;
    while(1){
        cin>>n;
        if (n==0) break;

        int tab[130][130],vis[130][130];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>tab[i][j];
                vis[i][j]=INF;
            }
        }
        q.push({0,0});
        vis[0][0]=tab[0][0];
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if (x!=0 && vis[x-1][y]>vis[x][y]+tab[x-1][y]){
                vis[x-1][y]=vis[x][y]+tab[x-1][y];
                q.push({x-1,y});
            }
            if (x!=n && vis[x+1][y]>vis[x][y]+tab[x+1][y]){
                vis[x+1][y]=vis[x][y]+tab[x+1][y];
                q.push({x+1,y});
            }
            if (y!=0 && vis[x][y-1]>vis[x][y]+tab[x][y-1]){
                vis[x][y-1]=vis[x][y]+tab[x][y-1];
                q.push({x,y-1});
            }
            if (y!=n && vis[x][y+1]>vis[x][y]+tab[x][y+1]){
                vis[x][y+1]=vis[x][y]+tab[x][y+1];
                q.push({x,y+1});
            }
        }

        cout<<"Problem "<<cnt<<": "<<vis[n-1][n-1]<<"\n";
        cnt++;
    }

    return 0;
}
