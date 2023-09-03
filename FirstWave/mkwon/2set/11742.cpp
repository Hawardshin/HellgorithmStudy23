#include <iostream>
#include <algorithm>

using namespace std;

int n,m,num[1005][1005]={0,},nod[1005]={0,};

void dfs(int x)
{
    nod[x] = 1;
    for (int i=1; i<=n; i++){
        if (num[x][i] == 1){
            num[x][i]=0;
            num[i][x]=0;
            dfs(i);
        }
    }
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

    int res = 0;
    for (int i=1; i<=n; i++){
        if (!nod[i]){
            dfs(i);
            res++;
        }
    }

    cout<<res;

    return 0;
}
