#include <iostream>
#include <algorithm>

using namespace std;

long long int x,y;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>x>>y;

    cout<<((y * 100) / x);

    cout<<(x - x * y * y);
    cout<<" "<<(x * y - 1)<<" ";
    long long int res = (x - x*y*y)/(x*y - 1);

    cout<<res;
    
    return 0;
}

// (x + n) / (y + n) != x * y
// (x + n) != x*y*(y + n)
// x + n != x*y*y + x*y*n
// x*y*n - n != x - x*y*y
// n(x*y - 1) = x - x*y*y
// n = (x - x*y*y) / (x*y - 1)