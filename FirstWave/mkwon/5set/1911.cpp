#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <pair<int,int>> v;
int n,m,res=0;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n>>m;
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }

    sort(v.begin(), v.end());

    int dis=0;
    for(int i=0; i<n; i++){
        int x=v[i].first;
        int y=v[i].second;

        if (dis >= y) continue;

        if (dis < x) dis=x;
        else if (dis > x) x=dis;

        int temp1 = (y-x)/m;
        int temp2 = (y-x)%m;

        if(temp2) temp1++;
        res+=temp1;

        dis+=m*temp1;
    }

    cout<<res;

    return 0;
}