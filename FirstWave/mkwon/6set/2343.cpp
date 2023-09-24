#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,v[100005],ans=0,sum=0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n>>m;

    int left=-1;
    for (int i=0; i<n; i++){
        cin>>v[i];
        sum+=v[i];
        if (left<v[i]) left=v[i];
    }

    int right=sum;
    while (left<=right) {
        int mid = (left + right) / 2;
        
        int cnt = 0, temp=0;;
        for (int i=0; i<n; i++) {
            if (temp + v[i] > mid){
                temp=0;
                cnt++;
            }
            temp+=v[i];
        }
        
        if (temp!=0) cnt++;

        if (cnt<=m) right=mid-1;
        else left=mid+1;
    }

    cout<<left;

}