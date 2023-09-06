#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define INF 2147483647

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector <pair<int, int>> vec[20005];
int n,m,start,res[20005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin>>n>>m>>start;

    for(int i=0; i<m; i++){
        int x,y,z;
        cin>>x>>y>>z;
        vec[x].push_back({y,z});
    }

    for(int i=1; i<=n; i++) res[i]=INF;

    pq.push({0,start});
    res[start] = 0;
    while (!pq.empty())
    {
        int weight= pq.top().first;
        int node  = pq.top().second;
        pq.pop();

        if (res[node] < weight) continue;

        for(int i=0; i<vec[node].size(); i++){
            int vnode = vec[node][i].first;
            int vweight = vec[node][i].second;
            if (res[vnode] > weight + vweight){
                res[vnode] = weight + vweight;
                pq.push({res[vnode], vnode});
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(res[i]==INF) cout<<"INF\n";
        else cout<<res[i]<<"\n";
    }

    return 0;
}
