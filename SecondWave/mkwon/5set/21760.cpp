#include <iostream>
#include <algorithm>

using namespace std;

int t,n,m,k,d;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>t;

    while(t--){
        cin>>n>>m>>k>>d;

        long long res = -1;

        for(int b=1; ; b++){

            long long a = b*k;
            long long mysum = ((n*m)*(m-1))/2*a;
            long long othersum = ((n*m)*(n-1)*m)/2*b;

            if (mysum+othersum <= d){
                res=mysum+othersum;
            }
            else break;
        }
        cout<<res<<"\n";

    }
    
    return 0;
}