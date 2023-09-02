#include <iostream>
#include <algorithm>

using namespace std;

#define INF 2147483647

int n, s, num[100005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    cin>>n>>s;

    int sum=0, res=INF;
    for (int i=0,j=1; j<=n; j++){
        cin>>num[j];
        sum+=num[j];

        if (sum >= s){
            while (sum >= s){
                if ((j-i)<res) res = j-i;
                i++;
                sum -= num[i];
            }
        }
    }

    if (res == INF) cout<<"0";
    else cout<<res;

    return 0;
}