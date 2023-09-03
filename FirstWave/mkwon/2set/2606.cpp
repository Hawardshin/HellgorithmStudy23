#include <iostream>
#include <algorithm>

using namespace std;

int n,m,num[1005][1005]={0,},nod[1005]={0,},res=-1;

int dfs(int x)
{
    nod[x] = 1;
    res++;
    for (int i=1; i<=n; i++){
        if (num[x][i] == 1){
            num[x][i]=0;
            num[i][x]=0;
            if (!nod[i]) dfs(i);
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        num[a][b]=1;
        num[b][a]=1;
    }

    cout<<dfs(1);

    return 0;
}
