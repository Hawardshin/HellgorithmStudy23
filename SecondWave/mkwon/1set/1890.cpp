#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int num[105][105]={0,};
long dp[105][105]={0,};

int main(){

    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>num[i][j];
        }
    }

    dp[0][0]=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (i==n-1 && j==n-1) break;
            int jump = num[i][j];

            if (dp[i][j] >= 1){
                if (i+jump<n) dp[i+jump][j]+=dp[i][j];
                if (j+jump<n) dp[i][j+jump]+=dp[i][j];
            }
        }
    }

    cout<<dp[n-1][n-1];

    return 0;
}