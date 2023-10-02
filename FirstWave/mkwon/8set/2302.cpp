#include <iostream>
#include <algorithm>
using namespace std;

int n,m,res,dp[45]={0,},tab[45];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin>>n>>m;
    for(int i=0; i<m; i++) cin>>tab[i];

    dp[0]=1; dp[1]=1; dp[2]=2;
    for(int i=3; i<=n; i++){
        dp[i]=dp[i-1]+dp[i-2];
    }

    int left=0;
    res=1;
    for(int i=0; i<m; i++){
        res *= dp[tab[i] - left - 1];
        left = tab[i];
    }
    res *= dp[n-left]; //마지막
    cout<<res;

    return 0;
}
