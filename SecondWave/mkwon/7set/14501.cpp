#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct pos{
    int day;
    int time;
    int pay;
};

class mycompare
{
    public:
    bool operator() (const pos& a, const pos &b) const{
        return a.pay<b.pay;
    }
};

priority_queue <pos, vector<pos>, mycompare> pq;
vector <pair<int,int>> v;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n,res=0;
    cin>>n;

    v.push_back({0,0});
    for(int i=1; i<=n; i++){
        int a,b; cin>>a>>b;
        v.push_back({a,b});
        pos p; p.day=i; p.time=a; p.pay=b;
        pq.push(p);
    }

    while (!pq.empty()){
        int day = pq.top().day;
        int time = pq.top().time;
        int pay = pq.top().pay;
        pq.pop();

        if (day + time -1 > n) continue;
        if (res < pay) res=pay;
        for (int i=day+time; i<=n; i++){
            if (i+v[i].first-1 > n) continue;
            pos temp; temp.day=i; temp.time=v[i].first; temp.pay=pay+v[i].second;
            pq.push(temp);
        }
    }

    cout<<res;

    return 0;
}
