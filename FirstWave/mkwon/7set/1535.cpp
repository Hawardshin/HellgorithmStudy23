#include <iostream>
#include <algorithm>
using namespace std;

int n,m,res=0,hp[25]={0,},happy[25]={0,},dp[25][105]={0,};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin>>n;
    for(int i=1; i<=n; i++) cin>>hp[i];
    for(int i=1; i<=n; i++) cin>>happy[i];

    for(int i=1; i<=n; i++){
        for(int j=100; j>=0;j--){
            if(j - hp[i] > 0) dp[i][j]=max(dp[i-1][j], dp[i-1][j-hp[i]] + happy[i]);
            else dp[i][j]=dp[i-1][j];
            
            if(res<dp[i][j]) res=dp[i][j];
        }
    }

    cout<<res;

    return 0;
}
