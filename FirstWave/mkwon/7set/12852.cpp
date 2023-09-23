#include <iostream>
#include <algorithm>
using namespace std;

int n,m,dp[1000005]={0,},path[1000005]={0,};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin>>n;

    dp[1]=0; path[1]=1;
    for(int i=2; i<=n; i++){
        dp[i]=dp[i-1]+1;
        path[i]=i-1;

        if(i%2==0 && dp[i/2]+1 < dp[i]){
            dp[i]=dp[i/2]+1;
            path[i]=i/2;
        }
        if(i%3==0 && dp[i/3]+1 < dp[i]){
            dp[i]=dp[i/3]+1;
            path[i]=i/3;
        }
    }
    cout<<dp[n]<<"\n";

    while (1) {
		cout<<n<<" ";
        if(n==1) break;
		n = path[n];
	}

    return 0;
}