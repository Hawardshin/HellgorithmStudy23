#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,vis[105]={0,};
vector <int> v,prt;

void loop(int x, int cnt){

    if (cnt == m){
        for (int i=0; i<m; i++)
            cout<<prt[i]<<" ";
        cout<<"\n";
        return ;
    }

    for(int i=x; i<n; i++){
        if (vis[i] == 1) continue;
        vis[i] = 1;
        prt.push_back(v[i]);
        loop(i, cnt+1);
        prt.pop_back();
        vis[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n>>m;
    for (int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    loop(0,0);

    return 0;
}