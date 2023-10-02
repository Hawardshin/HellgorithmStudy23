#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n,m,x,visited[100001];
vector <int> adj[100001], rev_adj[100001];
int cnt=-1, reverse_cnt=-1;

void dfs(int cur){
    if (visited[cur])
        return;
 
    visited[cur] = true;
    cnt++;
 
    for (int next : adj[cur])
        dfs(next);
}

void reverse_dfs(int cur){
    if (visited[cur])
        return;
 
    visited[cur] = true;
    reverse_cnt++;
 
    for (int next : rev_adj[cur])
        reverse_dfs(next);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin>>n>>m>>x;
    for(int i=0; i<m; i++){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }

     dfs(x);
 
    memset(visited, 0x00, sizeof(visited));
    reverse_dfs(x);
 
    cout << reverse_cnt + 1 << ' ' << n - cnt << "\n";

    return 0;
}
