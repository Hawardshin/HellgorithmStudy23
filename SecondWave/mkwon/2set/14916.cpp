#include <iostream>
#include <algorithm>

using namespace std;

#define INF 100009

int n;
int dp[100005]={0,};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n;

    for(int i=0; i<=n; i++){
        dp[i]=INF;
    }

    dp[2]=1; dp[5]=1;
    for(int i=2; i<=n; i++){
        if (i%5==0) dp[i] = min(dp[i], dp[i-5]+1);
        dp[i] = min(dp[i], dp[i-2]+1);
    }

    if (dp[n] == INF) cout<<"-1";
    else cout<<dp[n];
    
    return 0;
}