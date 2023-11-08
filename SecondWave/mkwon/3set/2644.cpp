#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
int a,b;
int flag=0,res=0;
vector <vector<int>> v(100);

int visit[101]={0,};

void dfs(int node, int cnt){
    // cout<<"\n"<<node<<" "<<cnt;
    
    for (int i=0; i<v[node].size(); i++){
        if (visit[v[node][i]]) continue;
        if (flag) return ;

        if (v[node][i] == b){
            res=cnt+1; flag=1;
            return ;
        }

        visit[v[node][i]]=1;
        dfs(v[node][i],cnt+1);
        visit[v[node][i]]=0;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;
    cin>>a>>b;
    cin>>m;
    while(m--){
        int x,y;
        cin>>x>>y;

        v[x].push_back(y);
        v[y].push_back(x);
    }

    dfs(a,0);
    if (res == 0) cout<<"-1";
    else cout<<res;
    
    return 0;
}