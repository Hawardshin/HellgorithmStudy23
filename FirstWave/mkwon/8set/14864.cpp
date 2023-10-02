#include <iostream>
#include <algorithm>
using namespace std;

int n,m,res,tab[100005],dp[100005]={0,};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin>>n>>m;
    for(int i=0; i<=n; i++) tab[i]=i;
    for(int i=0; i<m; i++){
        int a,b; cin>>a>>b;
        tab[a]++; tab[b]--;
    }

    for(int i=1; i<=n; i++){
        if (dp[tab[i]]){
            cout<<"-1"; return 0;
        }
        dp[tab[i]]=1;
    }

    for(int i=1; i<=n; i++) cout<<tab[i]<<" ";

    return 0;
}
