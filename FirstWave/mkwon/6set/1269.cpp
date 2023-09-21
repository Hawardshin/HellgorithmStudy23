#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,res1,res2=0;
vector <int> v;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n>>m;
    for(int i=0; i<n; i++){
        int x; cin>>x; v.push_back(x);
    }

    sort(v.begin(), v.end());
    res1=n;
    for(int i=0; i<m; i++){
        int x; cin>>x;
        if (binary_search(v.begin(), v.end(), x)) res1--;
        else res2++;
    }

    cout<<res1+res2;
    
    return 0;
}