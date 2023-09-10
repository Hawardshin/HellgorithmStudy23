#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 2147483647

int n,m,tab[55][55]={0,},vis[55]={0,},res=INF;;
vector <pair<int,int>> house,chick,vec;

void loop(int x, int cnt){
    
    if (cnt == m){
        int sumdis=0;
        for(int i=0; i<house.size(); i++){
            int dis = INF;
            for (int j=0; j<vec.size(); j++){
                int temp = abs(house[i].first-vec[j].first)+abs(house[i].second-vec[j].second);
                if (dis > temp) dis=temp;
            }
            sumdis+=dis;
        }
        if (sumdis < res) res=sumdis;
    }

    for(int i=x; i<chick.size(); i++){
        if (vis[i]) continue;
        vec.push_back({chick[i].first, chick[i].second});
        vis[i]=1;
        loop(i, cnt+1);
        vis[i]=0;
        vec.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>tab[i][j];
            if(tab[i][j] == 1) house.push_back({i,j});
            if(tab[i][j] == 2) chick.push_back({i,j});
        }
    }

    loop(0,0);

    cout<<res;

    return 0;
}
