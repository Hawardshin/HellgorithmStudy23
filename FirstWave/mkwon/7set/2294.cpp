#include <iostream>
#include <algorithm>
using namespace std;

#define INF 2147483646

int n,m,tab[105]={0,},dp[100005]={0,};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>tab[i];
    for(int i=1; i<=m; i++) dp[i]=INF;

    for(int i=0; i<n; i++){
        for(int j=tab[i]; j<=m; j++){
            dp[j] = min(dp[j - tab[i]]+1, dp[j]);
        }
    }
    if (dp[m]==INF) cout<<"-1";
    else cout<<dp[m];

    return 0;
}