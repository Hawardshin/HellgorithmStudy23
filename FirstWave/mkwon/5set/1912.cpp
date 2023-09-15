#include <iostream>
#include <algorithm>

using namespace std;

int n,num[100005]={0,};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n;
    for(int i=0; i<n; i++) cin>>num[i];

    int sum=num[0],res=num[0];
    for(int i=1; i<n; i++){
        if (sum+num[i] > num[i]) sum+=num[i];
        else sum=num[i];
        if(res<sum) res=sum;
    }
    cout<<res;

    return 0;
}