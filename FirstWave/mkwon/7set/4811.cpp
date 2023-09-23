#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
long long dp[31][31];

void calculate()
{
    // 마지막엔 반개
    for(int i=0; i<=30; i++) dp[0][i] = 1;

    for(int i=1; i<=30; i++){ //한개
        for(int j=0; j<=30; j++){ //반개
            if (j==0) dp[i][0]=dp[i-1][1]; //처음엔 한개
            else dp[i][j]=dp[i-1][j+1]+dp[i][j-1];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    calculate();

    while(1){
        cin>>n;
        if (n==0) break;
        cout<<dp[n][0]<<"\n";
    }

    return 0;
}

// 카탈란 수?
// 1 1 2 5 14 42 ~
// 2n! / n! * (n+1)!
