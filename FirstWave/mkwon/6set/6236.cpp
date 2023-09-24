#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,v[100005],res=0,sum=0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n>>m;
    for (int i=0; i<n; i++){
        cin>>v[i];
        sum+=v[i];
    }

    int left=1, right=sum;
    while (left<=right) {
        int mid = (left + right) / 2;
        
        int cnt=1, flag=0, daily=mid;
        for (int i=0; i<n; i++) {
            if (mid<v[i]){
                flag=1; break;
            }
            if (daily<v[i]){
                daily=mid;
                cnt++;
            }
            daily-=v[i];
        }

        if(flag || cnt>m) left=mid+1;
        else {
            right=mid-1;
            res=mid;
        }
    }
    cout<<res;

    return 0;
}