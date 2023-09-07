#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n,tab[100005]={0,}, vis[100005]={0,};

int dfs(int start, int node, int vis[]){

    if (start == node) return 0;
    if (vis[node] == 1) return 1;

    vis[node] = 1;
    return dfs(start, tab[node], vis);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t;
    cin>>t;

    while (t--){
        cin>>n;
        for(int i=1; i<=n; i++)
            cin>>tab[i];
        
        int res = 0;
        for(int i=1; i<=n; i++){
            int vis[100005]={0,};
            vis[i] = 1;
            if (dfs(i, tab[i], vis)) res++;
        }
        cout<<res<<"\n";
    }

    return 0;
}
