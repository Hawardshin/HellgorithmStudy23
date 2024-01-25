#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

int n, k;
int vis[200005]={0,};
queue <pair<int,int>> q;
vector <int> v;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin>>n>>k;
    
    q.push({n,0});
    vis[n]=0;
    while(!q.empty()){
        int idx = q.front().first;
        int time = q.front().second;
        q.pop();

        if (idx==k){
            cout<<time<<"\n"; break;
        }

        if (idx<100000 && vis[idx*2] == 0){
            vis[idx*2]=time+1;
            q.push({idx*2,time+1});
        }
        if (idx>0 && vis[idx-1] == 0){
            vis[idx-1]=time+1;
            q.push({idx-1,time+1});
        }
        if (idx<100000 && vis[idx+1] == 0){
            vis[idx+1]=time+1;
            q.push({idx+1,time+1});
        }
    }

    int idx=k, cnt=vis[k];
    v.push_back(idx);
    while(1){
        if(cnt == 0) break;
        
        if (idx%2==0 && idx>0 && vis[idx/2] != 0 && vis[idx/2]==cnt-1){
            idx=idx/2;
            v.push_back(idx);
        }
        else if (idx>0 && vis[idx-1] != 0 && vis[idx-1]==cnt-1){
            idx=idx-1;
            v.push_back(idx);
        }
        else if (idx<100000 && vis[idx+1] != 0 && vis[idx+1]==cnt-1){
            idx=idx+1;
            v.push_back(idx);
        }
        cnt--;
    }
    if (n != k) v.push_back(n);

    for(int i=v.size()-1; i>=0; i--) cout<<v[i]<<" ";

    return 0;
}
