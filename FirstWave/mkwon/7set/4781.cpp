#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

double m;
int n;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    while(1){
        cin>>n>>m;
        if(n==0)break;
        int newm = (int)(m*100+0.5);
        
        vector <pair<int,int>> vec;
        int dp[100005]={0,};

        for(int i=0; i<n; i++){
            int a; double b; cin>>a>>b;
            vec.push_back({a,(int)(b*100+0.5)});
        }

        memset(dp,0,sizeof(dp));
        for(int i=0; i<n; i++){
            int v = vec[i].first;
            int w = vec[i].second;

            for(int j=w; j<=newm; j++){
                dp[j] = max(dp[j], dp[j-w]+v);
            }
        }
        cout<<dp[newm]<<"\n";
    }
    
    return 0;
}