#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m,num[100005];
    cin>>n>>m;

    for (int i=0; i<n; i++){
        cin>>num[i];
    }

    for (int i=1; i<n; i++){
        num[i] += num[i-1];
    }

    for (int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        int res;
        if (a == 1) res = num[b-1];
        else res = num[b-1] - num[a-2];
        cout<<res<<"\n";
    }

    return 0;
}