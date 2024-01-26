#include <iostream>
#include <queue>

using namespace std;

int n, k;
int vis[200005]={0,};
queue <pair<int,int>> q;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin>>n>>k;
    
    q.push({n,0});
    vis[n]=0;
    while(!q.empty()){
        int idx = q.front().first;
        int time = q.front().second;
        q.pop();

        // cout<<idx<<" "<<time<<"\n";

        if (idx==k){
            cout<<time; break;
        }

        if (idx<100000 && vis[idx*2] == 0){
            vis[idx*2]=1;
            q.push({idx*2,time});
        }
        if (idx>0 && vis[idx-1] == 0){
            vis[idx-1]=1;
            q.push({idx-1,time+1});
        }
        if (idx<100000 && vis[idx+1] == 0){
            vis[idx+1]=1;
            q.push({idx+1,time+1});
        }

    }

    return 0;
}
