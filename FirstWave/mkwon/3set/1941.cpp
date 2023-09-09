#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int res=0,vis[30]={0,};
char tab[7][7]={0,};

int check(){
    
    queue <pair<int,int> > q;
    int check_vis[30]={0,};
    for (int i = 0; i < 25; i++){
        if (vis[i] == 1){
            q.push({i/5,i%5});
            check_vis[i]=1;
            break;
        }
    }

    int cnt=1;
    while (!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();

        if(cnt==7) break;

        if (x!=0 && vis[(x-1)*5+y]==1 && check_vis[(x-1)*5+y]==0){
            q.push({x-1,y}); check_vis[(x-1)*5+y]=1; cnt++;
        }
        if (x!=4 && vis[(x+1)*5+y]==1 && check_vis[(x+1)*5+y]==0){
            q.push({x+1,y}); check_vis[(x+1)*5+y]=1; cnt++;
        }
        if (y!=0 && vis[x*5+(y-1)]==1 && check_vis[x*5+(y-1)]==0){
            q.push({x,y-1}); check_vis[x*5+(y-1)]=1; cnt++;
        }
        if (y!=4 && vis[x*5+(y+1)]==1 && check_vis[x*5+(y+1)]==0){
            q.push({x,y+1}); check_vis[x*5+(y+1)]=1; cnt++;
        }
    }
    if (cnt == 7) return 1;
    return 0;
}

void loop(int x, int numS, int numY){

    if (numS + numY  == 7){
        if (numS < numY) return;
        if (check()) res++;
        return ;
    }

    for (int i=x; i<25; i++){
        if (vis[i]) continue;
        vis[i] = 1;
        if (tab[i/5][i%5] == 'S') loop(i, numS+1, numY);
        else loop(i, numS, numY+1);
        vis[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin>>tab[i][j];
        }
    }

    loop(0,0,0);
    cout<<res;

    return 0;
}
