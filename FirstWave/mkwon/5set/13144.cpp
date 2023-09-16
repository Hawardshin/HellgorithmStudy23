#include <iostream>
#include <algorithm>

using namespace std;

int n,m,num[100005]={0,},vis[100005]={0,};
long long res=0;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    cin>>n;
    for(int i=0; i<n; i++) cin>>num[i];

    int i=0,j=0;
    for(; i<n; i++){
        while (vis[num[i]]){
            res+=(i-j);
            vis[num[j]]=0;
            j++;
        }
        vis[num[i]]=1;
    }
    res+= (long long)(i-j)*(i-j+1)/2;

    cout<<res;

    return 0;
}
