#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,res,tab[105][100005]={0,};
vector <pair<int,int>> vec;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        int a,b; cin>>a>>b;
        vec.push_back({a,b});
    }

    for(int i=1; i<=n; i++){
        int w = vec[i-1].first;
        int v = vec[i-1].second;

        for(int j=1; j<=m; j++){
            if (w<=j) tab[i][j] = max(tab[i-1][j], tab[i-1][j-w]+v);
            else tab[i][j]=tab[i-1][j];
        }
    }
    cout<<tab[n][m];
    
    return 0;
}