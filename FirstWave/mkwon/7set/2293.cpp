#include <iostream>
#include <algorithm>
using namespace std;

int n,m,tab[105]={0,},dp[100005]={0,};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>tab[i];

    dp[0]=1;
    for(int i=0; i<n; i++){
        for(int j=tab[i]; j<=m; j++){
            dp[j] += dp[j - tab[i]];
        }
    }
    cout<<dp[m];

    return 0;
}