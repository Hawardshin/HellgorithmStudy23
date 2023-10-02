#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;

struct info {
	int id, cidx,t;
};

struct pqcmp{
    bool operator()(info &a, info &b) {
		if (a.t == b.t) {
			return a.cidx > b.cidx;
		}
		return a.t > b.t;
	}
};

int n,m,dp[45]={0,},tab[45];
long long res=0;

// vector <pair <int,int>> vec;
priority_queue <info, vector<info>, pqcmp> pq, Exit;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin>>n>>m;
    for(int i=0; i<m; i++) pq.push({ 0,i,0 });
    for(int i=0; i<n; i++){
        int a,b; cin>>a>>b;
        info tmp = pq.top();
		pq.pop();
		pq.push({ a, tmp.cidx, tmp.t+b });
		if(tmp.id>0) Exit.push({ tmp.id, -tmp.cidx, tmp.t });
    }

    while (!pq.empty()){
       info tmp = pq.top();
       pq.pop();
       if(tmp.id>0) Exit.push({ tmp.id, -tmp.cidx, tmp.t });
    }
    
    int cnt=1;
    while (!Exit.empty()) {
		long long vv = Exit.top().id;
		Exit.pop();
		res += (vv*cnt);
		cnt++;
	}
	cout << res;

    return 0;
}
