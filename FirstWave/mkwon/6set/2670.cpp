#include <iostream>
#include <algorithm>

using namespace std;

int n;
double tab[10005]={0,};

int main()
{
    // ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n;
    for(int i=0; i<n; i++) cin>>tab[i];

    double sum=tab[0],res=tab[0];
    for(int i=1; i<n; i++){
        if (tab[i]*sum > tab[i]) sum*=tab[i];
        else sum=tab[i];

        if (res<sum) res=sum;
    }
    // cout.precision(4);
    // cout<<res;
    printf("%.3lf", res);
    
    return 0;
}