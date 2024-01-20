#include <iostream>
#include <algorithm>
#define INF 2147483647

using namespace std;

int n,h;
int bottom[500005]={0,},up[500005]={0,},sum[500005]={0,};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>h;

    int a,b;
    for (int i=0; i<n/2; i++){
        cin>>a>>b;
        bottom[a]++; up[h+1-b]++;
    }

    for (int i=h-1; i>=1; i--)
        bottom[i] += bottom[i+1]; 
    
    int res = INF, cnt=0;
    for(int i=1; i<=h; i++){
        up[i] += up[i-1];
        sum[i] += up[i] + bottom[i];
        if (res > sum[i]){
            cnt=1;
            res=sum[i];
        }
        else if (sum[i] == res) cnt++;
    }
    cout<<res<<" "<<cnt;


    return 0;
}
