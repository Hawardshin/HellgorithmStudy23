#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define INF 2147483647

int n,m,tab[305][305]={0,};
queue <pair<int, int>> q;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>tab[i][j];
        }
    }

    int cnt = 0;
    while(1){
        //bfs
        int visit[305][305]={0,},ice=0;;
        for(int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (tab[i][j]>0 && visit[i][j]==0){
                    q.push({i,j}); visit[i][j]=1; ice++;
                    while (!q.empty()){
                        int x=q.front().first;
                        int y=q.front().second;
                        q.pop();

                        if (x!=0 && tab[x-1][y]!=0 && visit[x-1][y]==0){
                            q.push({x-1,y}); visit[x-1][y]=1;
                        }
                        if (y!=0 && tab[x][y-1]!=0 && visit[x][y-1]==0){
                            q.push({x,y-1}); visit[x][y-1]=1;
                        }
                        if (x!=n-1 && tab[x+1][y]!=0 && visit[x+1][y]==0){
                            q.push({x+1,y}); visit[x+1][y]=1;
                        }
                        if (y!=m-1 && tab[x][y+1]!=0 && visit[x][y+1]==0){
                            q.push({x,y+1}); visit[x][y+1]=1;
                        }
                    }
                } 
            }
        }

        if (ice >= 2){
            cout<<cnt; return 0;
        }
        if (ice == 0){
            cout<<"0"; return 0;
        }

        // melt
        int melt[305][305]={0,};
        for(int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                int meltcnt=0;
                if (i!=0 && tab[i-1][j]==0) meltcnt++;
                if (j!=0 && tab[i][j-1]==0) meltcnt++;
                if (i!=n-1 && tab[i+1][j]==0) meltcnt++;
                if (j!=m-1 && tab[i][j+1]==0) meltcnt++;
                melt[i][j] = meltcnt;
            }
        }

        for(int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (tab[i][j]<melt[i][j]) tab[i][j]=0;
                else tab[i][j]-=melt[i][j];
            }
        }

        cnt++;
    }

    return 0;
}
