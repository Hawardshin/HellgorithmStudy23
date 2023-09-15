#include <iostream>
#include <algorithm>

using namespace std;
#define INF 2147483647

int n,res=INF,tab[25][25]={0,},vis[25]={0,};

void loop(int x, int cnt){

    if (cnt==n/2){
        int sum1=0,sum2=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if (vis[i] && vis[j]) sum1+=tab[i][j];
                if (!vis[i] && !vis[j]) sum2+=tab[i][j];
            }
        }
        if (abs(sum1-sum2)<res) res=abs(sum1-sum2);
        return ;
    }

    for(int i=x; i<=n; i++){
        if (vis[i]) continue;
        vis[i]=1;
        loop(i,cnt+1);
        vis[i]=0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>tab[i][j];
        }
    }
    
    loop(1,0);
    cout<<res;

    return 0;
}