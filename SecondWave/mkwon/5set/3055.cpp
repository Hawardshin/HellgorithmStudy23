#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n,m;
char tab[55][55]={0,};

queue <pair<int,int>> q1,q2;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>tab[i][j];
            if (tab[i][j]=='S'){
                q1.push({i,j});
            }
            if (tab[i][j]=='*'){
                q2.push({i,j});
            }
        }
    }

    int count=0, flag=0;
    while(1){
        int human = q1.size();
        int water = q2.size();
        if (human == 0) break;

        while(water--){
            int x = q2.front().first;
            int y = q2.front().second;
            q2.pop();

            if(x!=0 && tab[x-1][y]=='.'){
                tab[x-1][y]='*';
                q2.push({x-1,y});
            }
            if(y!=0 && tab[x][y-1]=='.'){
                tab[x][y-1]='*';
                q2.push({x,y-1});
            }
            if(x!=n-1 && tab[x+1][y]=='.'){
                tab[x+1][y]='*';
                q2.push({x+1,y});
            }
            if(y!=m-1 && tab[x][y+1]=='.'){
                tab[x][y+1]='*';
                q2.push({x,y+1});
            }
        }

        while (human--){
            int x = q1.front().first;
            int y = q1.front().second;
            q1.pop();

            if(x!=0 && tab[x-1][y]=='.'){
                tab[x-1][y]='S';
                q1.push({x-1,y});
            }
            if(y!=0 && tab[x][y-1]=='.'){
                tab[x][y-1]='s';
                q1.push({x,y-1});
            }
            if(x!=n-1 && tab[x+1][y]=='.'){
                tab[x+1][y]='S';
                q1.push({x+1,y});
            }
            if(y!=m-1 && tab[x][y+1]=='.'){
                tab[x][y+1]='S';
                q1.push({x,y+1});
            }

            if(x!=0 && tab[x-1][y]=='D'){
                count++; flag=1; break;
            }
            if(y!=0 && tab[x][y-1]=='D'){
                count++; flag=1; break;
            }
            if(x!=n-1 && tab[x+1][y]=='D'){
                count++; flag=1; break;
            }
            if(y!=m-1 && tab[x][y+1]=='D'){
                count++; flag=1; break;
            }
        }

        if (flag) break;
        count++;
    }

    if (flag) cout<<count;
    else cout<<"KAKTUS";
    
    return 0;
}