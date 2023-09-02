#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long m,num[1000005],cnt[1005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin>>n>>m;

    for (int i=0; i<n; i++){
        cin>>num[i];
        if (i!=0) num[i] += num[i-1];
        cnt[(int)(num[i] % m)]++;
    }

    long long res = cnt[0];
    for (int i=0; i<m; i++){
        res += cnt[i] * (cnt[i]-1) / 2;
    }

    cout<<res;

    return 0;
}

// (num[i] - num[j-1]) % m == 0
// num[i] % m = num[j-1] % 0
// num % m count -> get Combination