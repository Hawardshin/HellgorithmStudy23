#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,res=0;

vector<int> v;

void eratos(int n) {
    vector<bool> prime(n + 1, true);
    
    for (int i=2; i*i<=n; ++i) {
        if (prime[i]) {
            for (int j=i*i; j<=n; j+=i) {
                prime[j]=false;
            }
        }
    }
    
    for (int i=2; i<=n; ++i) {
        if (prime[i]) v.push_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n;
    if (n == 1) {
        cout << 0;
        return 0;
    }

    eratos(n);

    int start=0,end=0,sum=0;
    while (end<=v.size()) {
        if (sum>=n) sum-=v[start++];
        if (sum<n) sum+=v[end++];
        if (sum==n) res++;
    }

    cout<<res;

    return 0;
}
