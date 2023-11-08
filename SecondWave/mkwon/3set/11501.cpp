#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n,m,t;
int a,b;
int flag=0,res=0;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>t;
    while (t--){

        vector <int> v;
        priority_queue < pair<int,int>, std::vector<pair<int,int>>, std::less<pair<int,int>> > pq;

        cin>>n;
        v.push_back(0);
        for(int i=0; i<n; i++){
            cin>>m; v.push_back(m);
            pq.push({m,i+1});
        }

        long long res=0;
        vector <pair<int,int>> sellDay;

        while (!pq.empty()){
            int cost = pq.top().first;
            int day = pq.top().second;
            pq.pop();
            
            if (sellDay.size() == 0){
                sellDay.push_back({day,cost});
            }
            else if (sellDay[sellDay.size()-1].first < day){
                sellDay.push_back({day,cost});
            }
            else {
                for(int i=0; i<v.size(); i++){
                    if (sellDay[i].first > day){
                        res+= sellDay[i].second-cost;
                        break;
                    }
                }
            }
        }

        cout<<res<<"\n";
    }
    
    return 0;
}