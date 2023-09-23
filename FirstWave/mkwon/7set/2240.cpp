#include <iostream>
#include <algorithm>
using namespace std;

int n,m,res=0,tab[1005][3]={0,},dp[1005][32][3]={0,};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        int a; cin>>a;
        tab[i][a]=1; // 떨어지는 나무면 1, 아니면 0
    }

    // 초 이동 나무
    dp[1][0][1] = tab[1][1];
    dp[1][1][2] = tab[1][2];
    res = max(dp[1][0][1], dp[1][1][2]);

    for(int i=2; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][2]) + tab[i][1];
            dp[i][j][2] = max(dp[i - 1][j - 1][1], dp[i - 1][j][2]) + tab[i][2];

            res = max(max(res, dp[i][j][1]), dp[i][j][2]);
        }
    }
    
    cout<<res;

    return 0;
}
