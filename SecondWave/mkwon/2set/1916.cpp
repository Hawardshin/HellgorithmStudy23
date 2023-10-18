#include <iostream>
#include <algorithm>
#include <queue>  
#include <vector>

using namespace std;
#define INF 100000005

struct pos{
    int weight;
    int node;
};

class mycompare
{
    bool reverse;
    public:
    mycompare (const bool& revparam=false)
        {reverse=revparam;}
    bool operator() (const pos& a, const pos &b) const{
        return a.weight>b.weight;
    }
};

priority_queue <pos, vector<pos>, mycompare > pq;

int n,m,startN,endN;
vector < vector <int> > v(1005);
vector < vector <int> > v2(1005);
int dp[1005]={0,},vis[1005]={0,};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    
    for (int i=0; i<m; i++){
        int a,b,c; cin>>a>>b>>c;
        v[a].push_back(b);
        v2[a].push_back(c);
    }
    cin>>startN>>endN;

    for(int i=0; i<=n; i++) dp[i]=INF;

    pos temp; temp.node=startN; temp.weight=0;
    pq.push(temp);
    while (!pq.empty()){
        pos p = pq.top();
        int node = p.node;
        int weight = p.weight;
        pq.pop();

        if (node == endN){
            cout<<weight;
            break;
        }

        for(int i=0; i<v[node].size(); i++){
            int nextNode = v[node][i];
            int nextCost = v2[node][i];
            if(vis[nextNode] == 1) continue;

            pos temp; temp.node=nextNode; temp.weight=weight+nextCost;
            pq.push(temp);
        }
        vis[node]=1;
    }
    
    return 0;
}