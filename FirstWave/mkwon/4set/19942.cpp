#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define INF 2147483647

int n,res=INF,vis[25]={0,},sum[5]={0,};
vector <int> nut,v[20],group,resvec;

void loop(int x){

    int cnt=0;
    for(int i=0; i<4; i++){
        if (sum[i] >= nut[i]){
            cnt++;
        }
    }

    if (cnt == 4){
        if(sum[4] < res) {
            res = sum[4];
            resvec.clear();
            for(int i=0; i<group.size(); i++)
                resvec.push_back(group[i]);
        }
        return ;
    }

    for(int i=x; i<n; i++){
        if (vis[i]) continue;
        vis[i]=1;
        group.push_back(i+1);
        for(int j=0; j<5; j++) sum[j]+=v[i][j];
        loop(i+1);
        vis[i]=0;
        group.pop_back();
        for(int j=0; j<5; j++) sum[j]-=v[i][j];
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n;
    for(int i=0; i<4; i++){
        int x; cin>>x; nut.push_back(x);
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<5; j++){
            int x;
            cin>>x;
            v[i].push_back(x);
        }
    }

    loop(0);

    if (res == INF){
        cout<<"-1"; return 0;
    }
    cout<<res<<"\n";
    for(int i=0; i<resvec.size(); i++){
        cout<<resvec[i]<<" ";
    }

    return 0;
}