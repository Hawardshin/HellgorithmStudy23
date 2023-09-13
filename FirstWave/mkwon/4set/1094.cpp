#include <iostream>
#include <algorithm>

using namespace std;

int n,cnt=0;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n;

    while(n>0){
        if (n%2==1) cnt++;
        n=n/2;
    }
    cout<<cnt;

    return 0;
}