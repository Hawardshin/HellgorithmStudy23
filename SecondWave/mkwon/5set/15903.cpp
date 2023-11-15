#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int t,n,m,k,d;
int num[1005]={0,};
long long res = 0;

priority_queue <long long, std::vector<long long>, std::greater<long long> > pq;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>num[i];
        pq.push(num[i]);
    }
    
    int cnt=0;
    while(1){
        if(cnt == m) break;
        long long top = pq.top();
        pq.pop();
        long long top2 = pq.top();
        pq.pop();

        long long sum = top + top2;
        pq.push(sum);
        pq.push(sum);
        cnt++;
    }

    while(!pq.empty()){
        long long top = pq.top();
        pq.pop();
        
        res+=top;
    }

    cout<<res;
    
    return 0;
}
