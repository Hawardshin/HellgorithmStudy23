#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    long long res=0;

    for (long long i=1; i<n; i++){
        long long a = i * n;
        long long b = i;
        long long num = a+b;
        res+=num;
    }

    cout<<res;
    
    return 0;
}
