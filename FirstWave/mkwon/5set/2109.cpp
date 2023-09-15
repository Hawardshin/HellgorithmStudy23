#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct compare{
    bool operator() (pair<int,int> &a, pair<int,int> &b) const
    {
        return a.first <= b.first;
    }
};

priority_queue <pair<int,int>, vector<pair<int,int>>, compare> pq;
int n,res=0,day[10005]={0,};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n;
    for (int i=0; i<n; i++){
        int x,y; cin>>x>>y;
        pq.push({x,y});
    }

    while(!pq.empty()){
        int x = pq.top().first;
        int y = pq.top().second;
        pq.pop();

        for (int i=y; i>=1; i--){
            if (day[i]) continue;
            day[i]=1;
            res+=x;
            break;
        }
    }

    cout<<res;

    return 0;
}