#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;

int n,m,s,visit[35][35][35]={0,};
char tab[35][35][35];

typedef struct {
    int x;
    int y;
    int z;
    int cnt;
    char c;
} pos;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    while (1)
    {
        queue <pos> q;
        for(int i=0; i<35; i++){
            for(int j=0; j<35; j++){
                for(int k=0; k<35; k++){
                    tab[i][j][k]=0;
                    visit[i][j][k]=0;
                }
            }
        }
        cin>>s>>n>>m;
        if (s==0 && n==0 && m==0) break;

        for(int i=0; i<s; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<m; k++){
                    cin>>tab[i][j][k];
                    if (tab[i][j][k] == 'S'){
                        pos p;
                        p.x=j; p.y=k; p.z=i; p.cnt=0; p.c='S';
                        visit[i][j][k] = 1;
                        q.push(p);
                    }
                }
            }
        }

        int res = -1;
        while (!q.empty())
        {
            int x = q.front().x;
            int y = q.front().y;
            int z = q.front().z;
            int cnt = q.front().cnt;
            char c = q.front().c;
            q.pop();

            // cout<<z<<" "<<x<<" "<<y<<" "<<c<<" "<<cnt<<" \n";

            if (c == 'E'){
                res = cnt;
                break;
            }

            if (x!=0 && (tab[z][x-1][y]=='.' || tab[z][x-1][y]=='E') && visit[z][x-1][y]==0){
                pos temp; temp.x=x-1; temp.y=y; temp.z=z; temp.cnt=cnt+1; temp.c=tab[z][x-1][y]; q.push(temp); visit[z][x-1][y] = 1;
            }
            if (x!=n-1 && (tab[z][x+1][y]=='.' || tab[z][x+1][y]=='E') && visit[z][x+1][y]==0){
                pos temp; temp.x=x+1; temp.y=y; temp.z=z; temp.cnt=cnt+1; temp.c=tab[z][x+1][y]; q.push(temp); visit[z][x+1][y] = 1;
            }

            if (y!=0 && (tab[z][x][y-1]=='.' || tab[z][x][y-1]=='E') && visit[z][x][y-1]==0){
                pos temp; temp.x=x; temp.y=y-1; temp.z=z; temp.cnt=cnt+1; temp.c=tab[z][x][y-1]; q.push(temp); visit[z][x][y-1] = 1;
            }
            if (y!=m-1 && (tab[z][x][y+1]=='.' || tab[z][x][y+1]=='E') && visit[z][x][y+1]==0){
                pos temp; temp.x=x; temp.y=y+1; temp.z=z; temp.cnt=cnt+1; temp.c=tab[z][x][y+1]; q.push(temp); visit[z][x][y+1] = 1;
            }

            if (z!=0 && (tab[z-1][x][y]=='.' || tab[z-1][x][y]=='E') && visit[z-1][x][y]==0){
                pos temp; temp.x=x; temp.y=y; temp.z=z-1; temp.cnt=cnt+1; temp.c=tab[z-1][x][y]; q.push(temp); visit[z-1][x][y] = 1;
            }
            if (z!=s-1 && (tab[z+1][x][y]=='.' || tab[z+1][x][y]=='E') && visit[z+1][x][y]==0){
                pos temp; temp.x=x; temp.y=y; temp.z=z+1; temp.cnt=cnt+1; temp.c=tab[z+1][x][y]; q.push(temp); visit[z+1][x][y] = 1;
            }
        }

        if (res == -1) cout<<"Trapped!\n";
        else cout<<"Escaped in "<<res<<" minute(s).\n";

    } 


    return 0;
}
