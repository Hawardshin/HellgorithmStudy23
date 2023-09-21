#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int k,n,m,res;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin>>k;
    while(k--){
        res=0;
        vector <int> v;
        cin>>n>>m;
        for(int i=0; i<n; i++){
            int x; cin>>x; v.push_back(x);
        }

        sort(v.begin(), v.end());
        for(int i=0; i<m; i++){
            int x; cin>>x;
            vector<int>::iterator it = upper_bound(v.begin(), v.end(), x);
            while (it != v.end()){
                res++; it++;
            }
        }
        cout<<res<<"\n";
    }
    
    return 0;
}