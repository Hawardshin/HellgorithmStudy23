#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int num[1005]={0,};

int main(){

    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>num[i];

    sort(num, num+n);
    for(int i=0; i<n; i++){
        if (num[i] <= m) m++;
        else break;
    }
    cout<<m;

    return 0;
}